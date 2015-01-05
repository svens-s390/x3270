/*
 * Copyright (c) 1993-2009, 2013-2015 Paul Mattes.
 * Copyright (c) 1990, Jeff Sparkes.
 * Copyright (c) 1989, Georgia Tech Research Corporation (GTRC), Atlanta, GA
 *  30332.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the names of Paul Mattes, Jeff Sparkes, GTRC nor the names of
 *       their contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY PAUL MATTES, JEFF SPARKES AND GTRC "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL PAUL MATTES, JEFF SPARKES OR GTRC BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *	charset.c
 *		This module handles character sets.
 */

#include "globals.h"

#include "3270ds.h"
#include "resources.h"
#include "appres.h"
#include "cg.h"

#include "charsetc.h"
#include "kybdc.h"
#include "popupsc.h"
#if defined(X3270_DISPLAY) || (defined(C3270) && !defined(_WIN32)) /*[*/
#include "screenc.h"
#endif /*]*/
#include "tablesc.h"
#include "unicodec.h"
#include "unicode_dbcsc.h"
#include "utf8c.h"
#include "utilc.h"

#include <errno.h>
#include <locale.h>
#if !defined(_WIN32) /*[*/
#include <langinfo.h>
#endif /*]*/

#if defined(__CYGWIN__) /*[*/
#include <w32api/windows.h>
#undef _WIN32
#endif /*]*/

/* Globals. */
Boolean charset_changed = False;
#define DEFAULT_CGEN	0x02b90000
#define DEFAULT_CSET	0x00000025
unsigned long cgcsgid = DEFAULT_CGEN | DEFAULT_CSET;
unsigned long cgcsgid_dbcs = 0L;
char *default_display_charset = "3270cg-1a,3270cg-1,iso8859-1";

/* Statics. */
static enum cs_result charset_init2(const char *csname, const char *codepage,
	const char *cgcsgid, const char *display_charsets);
static void set_cgcsgids(const char *spec);
static Boolean set_cgcsgid(char *spec, unsigned long *idp);
static void set_host_codepage(char *codepage);
static void set_charset_name(const char *csname);

static char *host_codepage = NULL;
static char *charset_name = NULL;

/*
 * Change character sets.
 */
enum cs_result
charset_init(const char *csname)
{
    enum cs_result rc;
    char *codeset_name;
    const char *codepage;
    const char *cgcsgid;
    const char *display_charsets;
    const char *dbcs_cgcsgid = NULL;
    const char *dbcs_display_charsets = NULL;
    Boolean need_free = False;

#if !defined(_WIN32) /*[*/
    /* Get all of the locale stuff right. */
    setlocale(LC_ALL, "");

    /* Figure out the locale code set (character set encoding). */
    codeset_name = NewString(nl_langinfo(CODESET));
# if defined(__CYGWIN__) /*[*/
    /*
     * Cygwin's locale support is quite limited.  If the locale
     * indicates "US-ASCII", which appears to be the only supported
     * encoding, ignore it and use the Windows ANSI code page, which
     * observation indicates is what is actually supported.
     *
     * Hopefully at some point Cygwin will start returning something
     * meaningful here and this logic will stop triggering.
     */
    if (!strcmp(codeset_name, "US-ASCII")) {
	Free(codeset_name);
	codeset_name = xs_buffer("CP%d", GetACP());
    }
# endif /*]*/
#else /*][*/
    codeset_name = xs_buffer("CP%d", appres.local_cp);
#endif /*]*/
    set_codeset(codeset_name);
    Free(codeset_name);

    /* Do nothing, successfully. */
    if (csname == NULL || !strcasecmp(csname, "us")) {
	set_cgcsgids(NULL);
	set_host_codepage(NULL);
	set_charset_name(NULL);
#if defined(X3270_DISPLAY) /*[*/
	(void) screen_new_display_charsets(default_display_charset, "us");
#endif /*]*/
	(void) set_uni(NULL, &codepage, &cgcsgid, &display_charsets);
	(void) set_uni_dbcs("", NULL, NULL);
	return CS_OKAY;
    }

    if (!set_uni(csname, &codepage, &cgcsgid, &display_charsets)) {
	return CS_NOTFOUND;
    }
    if (appres.sbcs_cgcsgid != NULL) {
	cgcsgid = appres.sbcs_cgcsgid; /* override */
    }
    if (set_uni_dbcs(csname, &dbcs_cgcsgid, &dbcs_display_charsets)) {
	if (appres.dbcs_cgcsgid != NULL) {
	    dbcs_cgcsgid = appres.dbcs_cgcsgid; /* override */
	}
	cgcsgid = xs_buffer("%s+%s", cgcsgid, dbcs_cgcsgid);
	display_charsets = xs_buffer("%s+%s", display_charsets,
	    dbcs_display_charsets);
	need_free = True;
    }

    rc = charset_init2(csname, codepage, cgcsgid, display_charsets);
    if (need_free) {
	Free((char *)cgcsgid);
	Free((char *)display_charsets);
    }
    if (rc != CS_OKAY) {
	return rc;
    }

    return CS_OKAY;
}

/* Set a CGCSGID.  Return True for success, False for failure. */
static Boolean
set_cgcsgid(char *spec, unsigned long *r)
{
    unsigned long cp;
    char *ptr;

    if (spec != NULL &&
	    (cp = strtoul(spec, &ptr, 0)) &&
	    ptr != spec &&
	    *ptr == '\0') {
	if (!(cp & ~0xffffL)) {
	    *r = DEFAULT_CGEN | cp;
	} else {
	    *r = cp;
	}
	return True;
    } else {
	return False;
    }
}

/* Set the CGCSGIDs. */
static void
set_cgcsgids(const char *spec)
{
    int n_ids = 0;
    char *spec_copy;
    char *buf;
    char *token;

    if (spec != NULL) {
	buf = spec_copy = NewString(spec);
	while (n_ids >= 0 && (token = strtok(buf, "+")) != NULL) {
	    unsigned long *idp = NULL;

	    buf = NULL;
	    switch (n_ids) {
	    case 0:
		idp = &cgcsgid;
		break;
	    case 1:
		idp = &cgcsgid_dbcs;
		break;
	    default:
		popup_an_error("Extra CGCSGID(s), ignoring");
		break;
	    }
	    if (idp == NULL)
		break;
	    if (!set_cgcsgid(token, idp)) {
		popup_an_error("Invalid CGCSGID '%s', ignoring", token);
		n_ids = -1;
		break;
	    }
	    n_ids++;
	}
	Free(spec_copy);
	if (n_ids > 0) {
	    return;
	}
    }

    if (appres.sbcs_cgcsgid != NULL) {
	cgcsgid = strtoul(appres.sbcs_cgcsgid, NULL, 0);
    } else {
	cgcsgid = DEFAULT_CGEN | DEFAULT_CSET;
    }
    if (appres.dbcs_cgcsgid != NULL) {
	cgcsgid_dbcs = strtoul(appres.dbcs_cgcsgid, NULL, 0);
    } else {
	cgcsgid_dbcs = 0L;
    }
}

/* Set the host codepage. */
static void
set_host_codepage(char *codepage)
{
	if (codepage == NULL) {
		Replace(host_codepage, NewString("037"));
		return;
	}
	if (host_codepage == NULL || strcmp(host_codepage, codepage)) {
	    	Replace(host_codepage, NewString(codepage));
	}
}

/* Set the global charset name. */
static void
set_charset_name(const char *csname)
{
	if (csname == NULL) {
		Replace(charset_name, NewString("us"));
		charset_changed = False;
		return;
	}
	if ((charset_name != NULL && strcmp(charset_name, csname)) ||
	    (appres.charset != NULL && strcmp(appres.charset, csname))) {
		Replace(charset_name, NewString(csname));
		charset_changed = True;
	}
}

/* Character set init, part 2. */
static enum cs_result
charset_init2(const char *csname, const char *codepage, const char *cgcsgid,
	const char *display_charsets)
{
	const char *rcs = display_charsets;
	int n_rcs = 0;
	char *rcs_copy, *buf, *token;

	/* Isolate the pieces. */
	buf = rcs_copy = NewString(rcs);
	while ((token = strtok(buf, "+")) != NULL) {
		buf = NULL;
		switch (n_rcs) {
		case 0:
		case 1:
		    break;
		default:
		    popup_an_error("Extra charset value(s), ignoring");
		    break;
		}
		n_rcs++;
	}
	Free(rcs_copy);

	/* Can't swap DBCS modes while connected. */
	if (IN_3270 && (n_rcs == 2) != dbcs) {
		popup_an_error("Can't change DBCS modes while connected");
		return CS_ILLEGAL;
	}

#if defined(X3270_DISPLAY) /*[*/
	if (!screen_new_display_charsets(
		    rcs? rcs: default_display_charset,
		    csname)) {
		return CS_PREREQ;
	}
#else /*][*/
	if (n_rcs > 1)
		dbcs = True;
	else
		dbcs = False;
#endif /*]*/

	/* Set up the cgcsgids. */
	set_cgcsgids(cgcsgid);

	/* Set up the host code page. */
	set_host_codepage((char *)codepage);

	/* Set up the character set name. */
	set_charset_name(csname);

	return CS_OKAY;
}

/* Return the current host codepage. */
const char *
get_host_codepage(void)
{
	return (host_codepage != NULL)? host_codepage: "037";
}

/* Return the current character set name. */
char *
get_charset_name(void)
{
	return (charset_name != NULL)? charset_name:
	    ((appres.charset != NULL)? appres.charset: "us");
}
