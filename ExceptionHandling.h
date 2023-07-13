/*  Lecture in WS 2021/22                                   */
/*  --------------------------------------------------------*/
/*  Author: Prof Dr. rer. nat. habil. Martin Steinhauser    */
/*                                                          */
/*  Frankfurt University of Applied Sciences                */
/*  Nibelungenplatz 1                                       */
/*  60318 Frankfurt am Main, Germany                        */
/*                                                          */
/*  Phone: +49 69 1533-2207                                 */
/*  Email: martin.steinhauser@fb2.fra-uas.de                */
/*  --------------------------------------------------------*/
/* =========================================================*/
#ifndef __EXCEPTION_HANDLING_H
#define __EXCEPTION_HANDLING_H

/* ============================================================= */
/** \file  ExceptionHandling.h
    \brief Do a 'nice' exit when it is necessary.

    \version 1.0
    \date 07 DEC 2011
    \author Dr. rer. nat. Martin O. Steinhauser

    Email: Martin.Steinhauser@emi.fraunhofer.de
 */
/* ============================================================ */


/** \var enum errorNumber 
    \brief This variable defines the error commands.
 */
enum errorNumber {
	NOMEMORY               = 0,
	NOBUFFERAVAILABLE      = 1,
	MISSINGPARAM           = 2,
	BADPARAM               = 3,
	DEGCASE                = 4,
	CUTOFF                 = 5,
	FOPEN                  = 6,
	KEYWORDS               = 7,
	MISSINGCOPYRIGHTNOTICE = 8,
	DOUBLEKEYWORD          = 9,
	PARSECOMMANDLINE       = 10
};

/** \enum warningNumber This variable defines the warning commands
 */
enum warningNumber {
	NOSYSTEMCALL           = 0,
	OPENFILE               = 1,
	REMOVEFILE             = 2,
	NOFILEBUFFER           = 3
};

void error(enum errorNumber, const char *, char *,int);
void warning(enum warningNumber, const char *, char *,int);
/* ============================================================= */

#endif /* __EXCEPTION_HANDLING_H */
