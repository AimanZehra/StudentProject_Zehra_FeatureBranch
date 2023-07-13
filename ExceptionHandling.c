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


/* ============================================================= */
/** \file  ExceptionHandling.c 
    \brief Functions for handling error messages in a common and elegant way.
    
    \version 1.0
    \date 01. March. 2015
    \author Dr. rer. nat. Martin O. Steinhauser, Copyright (2003-present)
    
    Email: Martin.Steinhauser@emi.fraunhofer.de
*/
/* ============================================================= */


/*  ======================================================== */
/* Basic includes. */
#include <stdio.h>
#include <stdlib.h>

/* ======================================================== */
/* Personal headers. */
#include "ExceptionHandling.h"


/*--------------------------------------------------------------------------*/
void error(enum errorNumber error, const char *functionName, char *filename,  
	   int line){

  char *errMessages[]={
    "Memory allocation failure.\n",
    "I cannot allocate file buffer.\n", 
    "Missing Parameter in list.\n",
    "Bad parameter.\n",
    "Degenerated case in calculation.\n",
    "Inconsistent potential cutoffs\n",
    "I Can't open file.\n",
    "The Number of Keywords in the parameter file is wrong.\n",
    "This input file is not valid -- it has no copyright notice.\n",
    "There is at least one double keyword in the input file.\n",
    "You must use exactly two arguments to main: a.out <Input-file> <System-file>.\n\
OR: With a restart file, use three arguments: a.out <Input-file> <System-file (New)> <System-file (Old)>\n\
The input file has been named 'InputParamsDat'.\n\
'a.out' is the name of the binary file.\n\
'System-file' can be any name picked by you. This provides the re-start functionality.\n"
  };
  printf("________________________________________________________________________________________\n");
  printf("-----> ERROR MESSAGE\n\"%s\"\nin function %s in file \"%s\" at line %d.\nTERMINATING... \n"
	 ,errMessages[(int)(error)], functionName, filename, line);
  printf("________________________________________________________________________________________\n");
  exit((int)error);
}


void warning(enum warningNumber warning, const char *functionName, char *filename,  
	     int line){
  
  char *warningMessages[]={
    "System() call is not available on this system",
    "I could not open a file.",
    "I could not remove a file.",
    "I could not allocate buffer space."
  };
  printf("______________________________________________________________________________________\n");
  printf("-----> WARNING MESSAGE\n\"%s\"\nin function %s in file \"%s\" at line %d.\nTRYING TO CONTINUE WITHOUT WARRANTY!\n",
	 warningMessages[(int)(warning)], functionName, filename, line);
  printf("________________________________________________________________________________________\n");
}
/* ======================= */
/* END ExpectionHandling.c */
/* ======================= */
