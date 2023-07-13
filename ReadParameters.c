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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "ReadParameters.h"
#include "Parameters.h"
#include "ExceptionHandling.h"

void readParameters(char *nameOfParamFile, S_Parameter *parameters){
  FILE *readFile = NULL;
  int flag       = 0;
  int a          = 0;
  int keyCount   = 0;
  int nrKeys     = 0;
  int var        = 0;
  double *dParameters;
  int  *iParameters;

  char inp[100];
  char keyword[100];
  int checkCopyright = 1;


  /*======================================================*/
  /* USER_RESPONSABILITY: SET NUMBER AND TYPE OF KEYWORDS */
  /*======================================================*/
  char keywords[][100]={
    /* GENERAL VARIABLES */
    "NUM_PARTICLES_TOTAL","TIME_DELTA","TIME_END",   /* 0-2 */
    /* PARTICLE 0 */                                 /* 3-9 */
    "0_MASS",
    "0_POSX","0_POSY","0_POSZ",
    "0_VELOX","0_VELOY","0_VELOZ",
    /* PARTICLE 1 */                                 /* 10-16 */
    "1_MASS",
    "1_POSX","1_POSY","1_POSZ",
    "1_VELOX","1_VELOY","1_VELOZ",
    /* PARTICLE 2 */                                 /* 17-23 */
    "2_MASS",
    "2_POSX","2_POSY","2_POSZ",
    "2_VELOX","2_VELOY","2_VELOZ",
    /* PARTICLE 3 */                                 /* 24-30 */
    "3_MASS",
    "3_POSX","3_POSY","3_POSZ",
    "3_VELOX","3_VELOY","3_VELOZ",
    /* PARTICLE 4 */                                 /* 31-37 */
    "4_MASS",
    "4_POSX","4_POSY","4_POSZ",
    "4_VELOX","4_VELOY","4_VELOZ",
    /* PARTICLE 5 */                                 /* 38-44 */
    "5_MASS",
    "5_POSX","5_POSY","5_POSZ",
    "5_VELOX","5_VELOY","5_VELOZ",
    "",
  };

  char keyword_type[][10]={
    "INT", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE",    /* 0 - 7 */
    "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", /* 8 -15 */
    "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", /* 16-23 */
    "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", /* 24-31 */
    "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", /* 32-39 */
    "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", "DOUBLE", ""                  /* 40-45 */
  };

  /*-------------------------------------------*/
  /* Store the number of keys in this variable */
  /*-------------------------------------------*/
  for (nrKeys = 0; strlen(keywords[nrKeys]); nrKeys++);

  /*---------------------------------------------*/
  /*  Keep track of integer and double parameters. */
  /*---------------------------------------------*/
  dParameters = (double *)(malloc)(nrKeys * sizeof(double));
  iParameters = (int *)   (malloc)(nrKeys * sizeof (int));
  if (! ( (dParameters) && (iParameters) ) )
    error(NOMEMORY,__FUNCTION__,__FILE__,__LINE__);

  /*---------------------------------------------*/
  /* Initialize with default values */
  /*---------------------------------------------*/
  for (a=0;a<nrKeys;a++)
    {
      dParameters[a] = 0.0;
      iParameters[a] = 0;
    }


  /*---------------------------------------------*/
  /* Infile operations. */
  /*---------------------------------------------*/
  readFile=fopen(nameOfParamFile,"r");
  if (!readFile)
    error(FOPEN,__FUNCTION__,__FILE__,__LINE__);


  /*---------------------------------------------*/
  /* Check copyright notice */
  /*---------------------------------------------*/
  printf("==================================================================\n");
  printf("[MODULE READ PARAMETERS] Checking Input File...\n");
  printf("[MODULE READ PARAMETERS] COPYRIGHT FILE NOTICE  ");

  while( (checkCopyright == 1) && (!feof(readFile)) ){
    fgets(inp,100,readFile);
    if(!(strncmp(inp,"PMC-Code",8))){
      fgets(inp,100,readFile);
      if ( !(strncmp(inp,"Copyright Prof. Dr. habil. Martin O. Steinhauser",48))){
	checkCopyright = 0;
	printf("O.K.\n");
      }
    }
  }
  if (checkCopyright == 1)
    error(MISSINGCOPYRIGHTNOTICE,__FUNCTION__,__FILE__,__LINE__);


  /*---------------------------------------------*/
  /* Read parameters from infile */
  /*---------------------------------------------*/
  fseek(readFile,0,SEEK_SET);
  while(!feof(readFile)){
    fgets(inp,100,readFile);
    strcpy(keyword,"NOKEYWORD");
    flag = 0;                 /* keyword found? */
    sscanf(inp,"%s",keyword); /* get possible keyword from input line */

    for(a=0;a<nrKeys;a++)
      {
	if(!(strncmp(keyword,keywords[a],strlen(keyword))))
	  {
	    /* ----------------------------------------------- */
	    /* Check the error of using the same keyword twice */
	    for (var = a+1;var<nrKeys;var++)
	      {
		if(!(strncmp(keyword,keywords[var],strlen(keyword))))
		  {
		    error(DOUBLEKEYWORD,__FUNCTION__,__FILE__,__LINE__);
		  }
	      }


	    if(!strncmp(keyword_type[a],"INT",3)) /* assign ints */
	      {
		/* get keyword and parameter value from input line */
		sscanf(inp, "%s %i", keyword, &iParameters[a]);
	      }


	    if(!strncmp(keyword_type[a],"DOUBLE",6)) /* assign double */
	      {
		/* get keyword and parameter value from input line */
		sscanf(inp, "%s %lf", keyword,&dParameters[a]);
	      }

	    keyCount += 1;
	    flag = 1;
	  }
      }
    /* end of file parser */
  }
  /*---------------------------------------------*/
  fclose(readFile);

  printf("[MODULE READ PARAMETERS] NUMBER OF KEYWORDS  ");
  if(keyCount == nrKeys){
    printf("   O.K.\n");
  }
  else{
    printf("==================================================================\n");
    printf("[MODULE READ PARAMETERS] MODUL INIT:\n");
    printf("[MODULE READ PARAMETERS] Counted keywords in file \"%s\": %i\n",nameOfParamFile,keyCount);
    printf("[MODULE READ PARAMETERS] Number of Keys in module \"%s\": %i\n",__FILE__,nrKeys);
    error(KEYWORDS,__FUNCTION__,__FILE__,__LINE__);
  }

  /* Assign all simple parameter values */
  parameters-> N                      = iParameters[0];
  parameters-> timeDelta              = dParameters[1];
  parameters-> timeEnd                = dParameters[2];

  /* Now assign all Body Parameters */
  /* BODY 0 */
  parameters-> mass0                  = dParameters[3];
  parameters-> position0_X            = dParameters[4];
  parameters-> position0_Y            = dParameters[5];
  parameters-> position0_Z            = dParameters[6];
  parameters-> velocity0_X            = dParameters[7];
  parameters-> velocity0_Y            = dParameters[8];
  parameters-> velocity0_Z            = dParameters[9];

  /* BODY 1 */
  parameters-> mass1                  = dParameters[10];
  parameters-> position1_X            = dParameters[11];
  parameters-> position1_Y            = dParameters[12];
  parameters-> position1_Z            = dParameters[13];
  parameters-> velocity1_X            = dParameters[14];
  parameters-> velocity1_Y            = dParameters[15];
  parameters-> velocity1_Z            = dParameters[16];

  /* BODY 2 */
  parameters-> mass2                  = dParameters[17];
  parameters-> position2_X            = dParameters[18];
  parameters-> position2_Y            = dParameters[19];
  parameters-> position2_Z            = dParameters[20];
  parameters-> velocity2_X            = dParameters[21];
  parameters-> velocity2_Y            = dParameters[22];
  parameters-> velocity2_Z            = dParameters[23];

  /* BODY 3 */
  parameters-> mass3                  = dParameters[24];
  parameters-> position3_X            = dParameters[25];
  parameters-> position3_Y            = dParameters[26];
  parameters-> position3_Z            = dParameters[27];
  parameters-> velocity3_X            = dParameters[28];
  parameters-> velocity3_Y            = dParameters[29];
  parameters-> velocity3_Z            = dParameters[30];
 
  /* BODY 4 */
  parameters-> mass4                  = dParameters[31];
  parameters-> position4_X            = dParameters[32];
  parameters-> position4_Y            = dParameters[33];
  parameters-> position4_Z            = dParameters[34];
  parameters-> velocity4_X            = dParameters[35];
  parameters-> velocity4_Y            = dParameters[36];
  parameters-> velocity4_Z            = dParameters[37];


  /* BODY 5 */
  parameters-> mass5                  = dParameters[38];
  parameters-> position5_X            = dParameters[39];
  parameters-> position5_Y            = dParameters[40];
  parameters-> position5_Z            = dParameters[41];
  parameters-> velocity5_X            = dParameters[42];
  parameters-> velocity5_Y            = dParameters[43];
  parameters-> velocity5_Z            = dParameters[44];

  /* REMARK: THIS WOULD BE THE PLACE WHERE YOU CHECKED
     ALL VARIABLES FOR CONSISITENCY!
  */

  /* REMARK: Here, you would normally have a function PrintParameters(), which 
     prints all parameters to the screen as a check
  */
}

