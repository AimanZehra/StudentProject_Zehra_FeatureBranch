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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Parameters.h"
#include "Particles.h"
#include "WriteSystem.h"
#include "ExceptionHandling.h"

void writeSystemToFile(Particle *particle, S_Parameter *param, char *filename, int i)
{
  int steps, systemFileSize;

  /* Needed pointers.
   *
   */
  FILE   *fpbin;
  char   *copyname;

  /* Declare a switch between two system data files.
   *
   */
  static int sw = 1;

  /* Initialization of needed standard variables.
   *
   */
  steps         = i;

  /* Memory for the char pointers
   *
   */
  copyname = (char *)(malloc( (sizeof(filename) + sizeof("_COPY")) * sizeof(char)));
  if (!copyname)
    warning(NOFILEBUFFER, __FUNCTION__, __FILE__, __LINE__);

  strcpy(copyname,filename);
  strcat(copyname,"_COPY");


  /* Use TWO files to save the system data and open them one at a time
   *
   */
  if (sw)
    {
      if (! (fpbin=fopen(filename,"wb")) )
	warning(NOFILEBUFFER, __FUNCTION__, __FILE__, __LINE__);
      else
	{
	  printf("[MODULE WRITE SYSTEM] Writing System Restart File\"%s\" at Integration Step %i...",filename,steps);
	} /* else... */
    } /* if (sw)... */
  else
    {
      if (! (fpbin=fopen(copyname,"wb")) )
	warning(NOFILEBUFFER, __FUNCTION__, __FILE__, __LINE__);
      else
	{
	  printf("[MODULE WRITE SYSTEM] Writing System File \"%s\" at Cycle Number %i ...",filename,steps);
	}

    } /* else (if sw)... */


  /* Write the SYSTEM DATA into the system file...
   *
   */
  /*==============*/
  /* DATA BLOCK 1 -- The current integration cycle number */
  /*==============*/
  fwrite(&steps,sizeof(steps),1,fpbin);

  /*==============*/
  /* DATA BLOCK 2 -- The complete data structure as whole, not the single arguments */
  /*==============*/
  fwrite(param,sizeof(S_Parameter),1,fpbin);

  /*==============*/
  /* DATA BLOCK 3 -- The particle data structure, i.e. the properties of all particles */
  /*==============*/
  for (i=0; i< (param -> N); i++)
    {
      fwrite(&particle[i],sizeof(Particle),1,fpbin);
         }
  fflush(fpbin);
  fclose(fpbin);
  printf("DONE!\n");

  /* Finally turn switch
   *
   */
  sw = (sw+1) % 2;
}
