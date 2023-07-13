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

#include "ReadSystem.h"
#include "Particles.h"
#include "Parameters.h"
#include "ExceptionHandling.h"

void initPreviousSystem(Particle *particle,S_Parameter *params,char *commandLineArgument){

  int stepnumber = 0;
  int i;

  /* File pointer to the configuration file
   *
   */
  FILE *pfile;

  /* Print information
   *
   */
  printf("\n======================================================================================== \n");
  printf("[MODULE READ SYSTEM] THIS IS A RESTARTED SYSTEM!\n"
	 "[MODULE READ SYSTEM] OLD RE-START SYSTEM FILE: \"%s\":\n",commandLineArgument);

  /* Check, if everything is O.K.
   *
   */
  if (! (pfile=fopen(commandLineArgument,"rb")) )
    error(FOPEN, __FUNCTION__, __FILE__, __LINE__);

  /* When the file was successfully opened, read the SYSTEM DATA from this file...
   *
   */
  else
    {
	
      /*==============*/
      /* DATA BLOCK 1 ===> The current integration cycle number */
      /*==============*/
      /*-------------------------------------*/
      fread(&stepnumber,sizeof(stepnumber),1,pfile);
    
      /*==============*/
      /* DATA BLOCK 2 ===> The basic parameter data structure */
      /*==============*/
      fread(params,sizeof(S_Parameter),1,pfile);
      printf("[MODULE READ SYSTEM] USING THE OLD SYSTEM FILE PARAMETERS FOR A RESTART\n");
     
      /*==============*/
      /* DATA BLOCK 3 ===> The basic particle data structure */
      /*==============*/
      for (i = 0; i < (params -> N); i ++){
	fread(&(particle[i]),sizeof(Particle),1,pfile);
      }
      fclose(pfile);
    }

  printf("\n========================================================================");
  printf("\n[MODULE READ SYSTEM] THE SYSTEM IS NOW RESTARTED WITH CYCLE NUMBER 0\n");
  printf("========================================================================\n\n");
}

