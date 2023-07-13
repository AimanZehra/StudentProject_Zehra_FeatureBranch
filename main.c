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

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "Defs.h"
#include "Particles.h"
#include "Statistics.h"
#include "Integrate.h"
#include "Forces.h"
#include "ExceptionHandling.h"
#include "Initialization.h"
#include "Parameters.h"
#include "ReadParameters.h"
#include "WriteSystem.h"
#include "ReadSystem.h"



/* And Finally, the main function */
/* NOTE: When you want to print out data, then you have to change
   Statistics.c
*/

int main (int numc, char *argv[]){ 

  double test =0.0;
  /* Allocate the parameters at the beginning, THEN read the file and initialize */
  S_Parameter *parameter = (S_Parameter *)malloc(sizeof(S_Parameter));

  /* Allow for providing the name of the inputfile (argv[1]) and of the System restart file (argv[2]) */
  if ((numc > 4) || (numc < 3)) 
    error(PARSECOMMANDLINE, __FUNCTION__, __FILE__, __LINE__);
  
  /* The logic is the follwoing: 
     1. Always read the provided input parameter file.
     2. Use this file for initialization, except an old system file was provided;
        in this case, use the old system file data to initialize everything by 
        simply overwriting the variables.
  */
    readParameters(argv[1],parameter);
 
  /* Now, assign the correct number of Particles and check for errors */
  Particle *p = (Particle*) malloc(parameter->N * sizeof (*p));
  if (!p)
    error(NOMEMORY, __FUNCTION__, __FILE__, __LINE__);
  

  /* In case of an old system file, overwrite all variables;
     Remark: Re-starting an old system with a different number of 
     particles N will crash the code (and doesn't make sense)
  */
  if (numc == 4)
      initPreviousSystem(p,parameter,argv[3]);
    
  else 
    initAllData(p, parameter);   

  timeIntegration(p, parameter, argv[2], 0.);

  return (0);  
}
