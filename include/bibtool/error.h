/*** error.h ******************************************************************
** 
** This file is part of BibTool.
** It is distributed under the GNU General Public License.
** See the file COPYING for details.
** 
** (c) 1996-2015 Gerd Neugebauer
** 
** Net: gene@gerd-neugebauer.de
** 
**-----------------------------------------------------------------------------
** Description:
**	This header file provides means for issuing error
**	messages. Most of the macros provided in this header file are
**	based on the function |error()| described in |error.c|.
**	Nevertheless this function covers the general cases the macros
**	in this header file are more convenient since they hide the
**	unneccesary arguments of the |error()| function providing
**	appropriate values.
**
**	This header file makes availlable the function |error()| as
**	defined in |error.c|.
**
******************************************************************************/

#include<stdio.h>
#include<bibtool/type.h>

/*-----------------------------------------------------------------------------
** Constant:	ERR_ERROR
** Type:	int
** Purpose:	Error type: Indicate that the error can not be
**		suppressed and the messaged is marked as error.
**___________________________________________________			     */
#define ERR_ERROR	1

/*-----------------------------------------------------------------------------
** Constant:	ERR_WARNING
** Type:	int
** Purpose:	Error type: Indicate that the error is in fact a
**		warning which can be suppressed. The messaged is
**		marked as warning. This flag is only in effect if the
**		|ERR_ERROR| flag is not set.
**___________________________________________________			     */
#define ERR_WARNING	2
#define ERR_WARN	2

/*-----------------------------------------------------------------------------
** Constant:	ERR_POINT
** Type:	int
** Purpose:	Error type: Indicate that the line and the error
**		pointer should be displayed (if not suppressed via
**		other flags).
**___________________________________________________			     */
#define ERR_POINT	4

/*-----------------------------------------------------------------------------
** Constant:	ERR_FILE
** Type:	int
** Purpose:	Error type: Indicate that the file name and line
**		number should be displayed (if not suppressed via
**		other flags).
**___________________________________________________			     */
#define ERR_FILE	8

/*-----------------------------------------------------------------------------
** Constant:	ERR_EXIT
** Type:	int
** Purpose:	Error type: Indicate that the |error()| function
**		should be terminated by |exit()| instead of
**		returning.
**___________________________________________________			     */
#define ERR_EXIT      256


 extern char  *err_format;
 extern Uchar *err_point;
 extern Uchar *err_oom;
 extern FILE  *err_file;

/*-----------------------------------------------------------------------------
** Macro:	ERROR_EXIT()
** Type:	void
** Purpose:	Raise an error, print the single string argument as
**		error message and terminate the program with |exit()|.
** Arguments:
**	X	Error message.
** Returns:	nothing
**___________________________________________________			     */
#define ERROR_EXIT(X)				\
	error(ERR_ERROR|ERR_EXIT,(Uchar*)X,	\
	      (Uchar*)0,(Uchar*)0,(Uchar*)0,(Uchar*)0,0,(char*)0)

/*-----------------------------------------------------------------------------
** Macro:	OUT_OF_MEMORY()
** Type:	void
** Purpose:	Raise an error because |malloc()| or |realloc()|
**		failed. The argument denoted the type of memory for
**		which the allocation failed. The program is
**		terminated.
** Arguments:
**	X	String denoting the type of unallocatable memory.
** Returns:	nothing
**___________________________________________________			     */
#define OUT_OF_MEMORY(X)			\
	error(ERR_ERROR|ERR_EXIT,err_oom,	\
	      (Uchar*)X,err_point,(Uchar*)0,(Uchar*)0,0,(char*)0)

/*-----------------------------------------------------------------------------
** Macro:	ERROR()
** Type:	void
** Purpose:	Raise an error. Print the argument as error message
**		and continue.
** Arguments:
**	X	Error message.
** Returns:	nothing
**___________________________________________________			     */
#define ERROR(X)				\
	error(ERR_ERROR,(Uchar*)X,		\
	      (Uchar*)0,(Uchar*)0,(Uchar*)0,(Uchar*)0,0,(char*)0)

/*-----------------------------------------------------------------------------
** Macro:	ERROR2()
** Type:	void
** Purpose:	Raise an error. Print the two arguments as error message
**		and continue.
** Arguments:
**	X	First error message.
**	Y	Continuation of the error message.
** Returns:	nothing
**___________________________________________________			     */
#define ERROR2(X,Y)				\
	error(ERR_ERROR,(Uchar*)X,		\
	      (Uchar*)Y,(Uchar*)0,(Uchar*)0,(Uchar*)0,0,(char*)0)

/*-----------------------------------------------------------------------------
** Macro:	ERROR3()
** Type:	void
** Purpose:	Raise an error. Print the three arguments as error message
**		and continue.
** Arguments:
**	X	First error message.
**	Y	Continuation of the error message.
**	Z	Second continuation of the error message.
** Returns:	nothing
**___________________________________________________			     */
#define ERROR3(X,Y,Z)				\
	error(ERR_ERROR,(Uchar*)X,		\
	      (Uchar*)Y,(Uchar*)Z,(Uchar*)0,(Uchar*)0,0,(char*)0)

/*-----------------------------------------------------------------------------
** Macro:	WARNING()
** Type:	void
** Purpose:	Raise a warning. Print the argument as warning message
**		and continue.
** Arguments:
**	X	Warning message.
** Returns:	nothing
**___________________________________________________			     */
#define WARNING(X)				\
	error(ERR_WARN,(Uchar*)X,		\
	      (Uchar*)0,(Uchar*)0,(Uchar*)0,(Uchar*)0,0,(char*)0)

/*-----------------------------------------------------------------------------
** Macro:	WARNING2()
** Type:	void
** Purpose:	Raise a warning. Print the two arguments as warning message
**		and continue.
** Arguments:
**	X	First warning message.
**	Y	Continuation of warning message.
** Returns:	nothing
**___________________________________________________			     */
#define WARNING2(X,Y)				\
	error(ERR_WARN,(Uchar*)X,		\
	      (Uchar*)Y,(Uchar*)0,(Uchar*)0,(Uchar*)0,0,(char*)0)

/*-----------------------------------------------------------------------------
** Macro:	WARNING3()
** Type:	void
** Purpose:	Raise a warning. Print the thre arguments as warning message
**		and continue.
** Arguments:
**	X	First warning message.
**	Y	Continuation of warning message.
**	Z	Second continuation of warning message.
** Returns:	nothing
**___________________________________________________			     */
#define WARNING3(X,Y,Z)				\
	error(ERR_WARN,(Uchar*)X,		\
	      (Uchar*)Y,(Uchar*)Z,(Uchar*)0,(Uchar*)0,0,(char*)0)

/*-----------------------------------------------------------------------------
** Macro:	Err()
** Type:	void
** Purpose:	Print a string to the error stream. This message is
**		preceded with an indicator. The message is \emph{not}
**		automatically terminated by a newline.
** Arguments:
**	S	String to print.
** Returns:	nothing
**___________________________________________________			     */
#define Err(S)			(void)fprintf(err_file,err_format,S)

/*-----------------------------------------------------------------------------
** Macro:	ErrC()
** Type:	void
** Purpose:	Print a single character to the error stream.
** Arguments:
**	CHAR	Character to send to output.
** Returns:	nothing
**___________________________________________________			     */
#define ErrC(CHAR)		(void)fputc(CHAR,err_file)

/*-----------------------------------------------------------------------------
** Macro:	ErrPrint()
** Type:	void
** Purpose:	Print a string to the error stream. The string is not
**		preceded by any indicator not is it automatically
**		terminated by a newline.
** Arguments:
**	F	String to print.
** Returns:	nothing
**___________________________________________________			     */
#define ErrPrint(F)		(void)fputs(F,err_file)

/*-----------------------------------------------------------------------------
** Macro:	ErrPrintF()
** Type:	void
** Purpose:	Apply a formatting instruction (with |printf()|). This
**		macro takes a format string and a second argument
**		which is determined by the formatting string.
** Arguments:
**	F	Format.
**	A	Argument.
** Returns:	nothing
**___________________________________________________			     */
#define ErrPrintF(F,A)		(void)fprintf(err_file,F,A)

/*-----------------------------------------------------------------------------
** Macro:	ErrPrintF2()
** Type:	void
** Purpose:	Apply a formatting instruction (with |printf()|). This
**		macro takes a format string and two additional arguments
**		which are determined by the formatting string.
** Arguments:
**	F	Format
**	A	First argument.
**	B	Second argument.
** Returns:	nothing
**___________________________________________________			     */
#define ErrPrintF2(F,A,B)	(void)fprintf(err_file,F,A,B)

/*-----------------------------------------------------------------------------
** Macro:	ErrPrintF3()
** Type:	void
** Purpose:	Apply a formatting instruction (with |printf()|). This
**		macro takes a format string and three additional arguments
**		which are determined by the formatting string.
** Arguments:
**	F	Format
**	A	First argument.
**	B	Second argument.
**	C	Third argument.
** Returns:	nothing
**___________________________________________________			     */
#define ErrPrintF3(F,A,B,C)	(void)fprintf(err_file,F,A,B,C)

/*-----------------------------------------------------------------------------
** Constant:	FlushErr()
** Type:	void
** Purpose:	Flush the error stream. This can be useful when single
**		characters are written to an error stream which does
**		buffering. 
** Returns:	nothing
**___________________________________________________			     */
#define FlushErr		(void)fflush(err_file)

/*-----------------------------------------------------------------------------
** Macro:	VerbosePrint1()
** Type:	void
** Purpose:	Print an informative message to the error stream.
** Arguments:
**	A	Verbose message.
** Returns:	nothing
**___________________________________________________			     */
#define VerbosePrint1(A)	(void)fprintf(err_file,"--- BibTool: %s\n",A)

/*-----------------------------------------------------------------------------
** Macro:	VerbosePrint2()
** Type:	void
** Purpose:	Print an informative message consisting of two
**		substrings to the error stream.
** Arguments:
**	A	Verbose message.
**	B	Continuation of verbose message.
** Returns:	nothing
**___________________________________________________			     */
#define VerbosePrint2(A,B)	(void)fprintf(err_file,"--- BibTool: %s%s\n",A,B)

/*-----------------------------------------------------------------------------
** Macro:	VerbosePrint3()
** Type:	void
** Purpose:	Print an informative message consisting of three
**		substrings to the error stream.
** Arguments:
**	A	Verbose message.
**	B	Continuation of verbose message.
**	C	Second continuation of verbose message.
** Returns:	nothing
**___________________________________________________			     */
#define VerbosePrint3(A,B,C)	(void)fprintf(err_file,"--- BibTool: %s%s%s\n",A,B,C)

/*-----------------------------------------------------------------------------
** Macro:	VerbosePrint4()
** Type:	void
** Purpose:	Print an informative message consisting of four
**		substrings to the error stream.
** Arguments:
**	A	Verbose message.
**	B	Continuation of verbose message.
**	C	Second continuation of verbose message.
**	D	Third continuation of verbose message.
** Returns:	nothing
**___________________________________________________			     */
#define VerbosePrint4(A,B,C,D)	(void)fprintf(err_file,"--- BibTool: %s%s%s%s\n",A,B,C,D)

#ifdef DEBUG

/*-----------------------------------------------------------------------------
** Macro:	DebugPrint1()
** Type:	void
** Purpose:	This Macro is for debugging purposes. The compilation
**		determines whether this macro prints its argument or
**		simply ignores it. This is achieved by defining or
**		undefining the macro |DEBUG| when compiling.
** Arguments:
**	A	Debug message.
** Returns:	nothing
**___________________________________________________			     */
#define DebugPrint1(A)		(void)fprintf(err_file,"+++ BibTool: %s\n",A)

/*-----------------------------------------------------------------------------
** Macro:	DebugPrint2()
** Type:	void
** Purpose:	This Macro is for debugging purposes. The compilation
**		determines whether this macro prints its arguments or
**		simply ignores them. This is achieved by defining or
**		undefining the macro |DEBUG| when compiling.
** Arguments:
**	A	Debug message.
**	B	Continuation of the debug message.
** Returns:	nothing
**___________________________________________________			     */
#define DebugPrint2(A,B)	(void)fprintf(err_file,"+++ BibTool: %s%s\n",A,B)

/*-----------------------------------------------------------------------------
** Macro:	DebugPrint3()
** Type:	void
** Purpose:	
** Purpose:	This Macro is for debugging purposes. The compilation
**		determines whether this macro prints its arguments or
**		simply ignores them. This is achieved by defining or
**		undefining the macro |DEBUG| when compiling.
** Arguments:Debug message.
**	A	Debug message.
**	B	Continuation of the debug message.
**	C	Second continuation of the debug message.
** Returns:	nothing
**___________________________________________________			     */
#define DebugPrint3(A,B,C)	(void)fprintf(err_file,"+++ BibTool: %s%s%s\n",A,B,C)

/*-----------------------------------------------------------------------------
** Macro:	DebugPrintF1()
** Type:	void
** Purpose:	This Macro is for debugging purposes. The compilation
**		determines whether this macro prints its argument or
**		simply ignores it. This is achieved by defining or
**		undefining the macro |DEBUG| when compiling.
** Arguments:
**	A	Debug message.
** Returns:	nothing
**___________________________________________________			     */
#define DebugPrintF1(A)		(void)fprintf(err_file,A)

/*-----------------------------------------------------------------------------
** Macro:	DebugPrintF2()
** Type:	void
** Purpose:	This Macro is for debugging purposes. The compilation
**		determines whether this macro prints its arguments or
**		simply ignores them. This is achieved by defining or
**		undefining the macro |DEBUG| when compiling.
** Arguments:
**	F	The format for the debug message.
**	A	Debug message.
** Returns:	nothing
**___________________________________________________			     */
#define DebugPrintF2(F,A)	(void)fprintf(err_file,F,A)

/*-----------------------------------------------------------------------------
** Macro:	DebugPrintF3()
** Type:	void
** Purpose:	
** Purpose:	This Macro is for debugging purposes. The compilation
**		determines whether this macro prints its arguments or
**		simply ignores them. This is achieved by defining or
**		undefining the macro |DEBUG| when compiling.
** Arguments:Debug message.
**	F	The format for the debug message.
**	A	Debug message.
**	B	Continuation of the debug message.
** Returns:	nothing
**___________________________________________________			     */
#define DebugPrintF3(F,A,B)	(void)fprintf(err_file,F,A,B)
#else
#define DebugPrint1(A)	      
#define DebugPrint2(A,B)      
#define DebugPrint3(A,B,C)  
#define DebugPrintF1(A)	      
#define DebugPrintF2(A,B)      
#define DebugPrintF3(A,B,C)    
#endif



#ifdef __STDC__
#define _ARG(A) A
#else
#define _ARG(A) ()
#endif
 void error _ARG((int type,Uchar *s1,Uchar *s2,Uchar *s3,Uchar *line,Uchar *ep,int line_no,char *file_name));/* error.c*/
 void init_error _ARG((FILE * file));

