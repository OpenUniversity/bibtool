/*** general.h ****************************************************************
** 
** This file is part of BibTool.
** It is distributed under the GNU General Public License.
** See the file COPYING for details.
** 
** (c) 1996-2015 Gerd Neugebauer
** 
** Net: gene@gerd-neugebauer.de
** 
******************************************************************************/

/*-----------------------------------------------------------------------------
**	
**---------------------------------------------------------------------------*/

#include <bibtool/config.h>

#include <stdio.h>

#ifdef __STDC__
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#ifdef LINT
 int fputs(char*,FILE*);
 int fputc(char,FILE*);
 int fclose(FILE*);
 int fflush(FILE*);
 int fprintf(FILE*,char*, ...);
 int printf(char*, ...);
#endif

#else
#ifdef HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#define strchr(A,B)  index(A,B)
#define strrchr(A,B) rindex(A,B)
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#else
 extern void    exit();
 extern VoidPTR malloc();
 extern VoidPTR realloc();
 extern char    *getenv();
#ifdef SIZE_T
#define size_t		SIZE_T
#else
#define size_t		unsigned
#endif
#endif
#endif

/*-----------------------------------------------------------------------------
**	Misc definitions
**---------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
** Constant:	TRUE
** Type:	int
** Purpose:	Just in case that this constant is not defined in any
**		used system header file it will be defined here. It
**		represents the |TRUE| condition.
**___________________________________________________			     */
#ifndef TRUE
#define TRUE  (1)
#endif
/*-----------------------------------------------------------------------------
** Constant:	FALSE
** Type:	int
** Purpose:	Just in case that this constant is not defined in any
**		used system header file it will be defined here. It
**		represents the |FALSE| condition.
**___________________________________________________			     */
#ifndef FALSE
#define FALSE (0)
#endif

/*-----------------------------------------------------------------------------
** Macro:	FOREVER
** Purpose:	This is an infinite loop.
**		
** Arguments:	none
**___________________________________________________			     */
#define FOREVER for (;;)

/*-----------------------------------------------------------------------------
** Macro:	POSSIBLY_UNUSED
** Purpose:	Mark a variable as possibly unused. It silences a gcc
**		compiler warning.
**		
** Arguments:	none
**___________________________________________________			     */
#define POSSIBLY_UNUSED(X) (void)(X)
