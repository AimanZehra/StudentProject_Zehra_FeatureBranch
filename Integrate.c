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

#include "Integrate.h"
#include "Forces.h"
#include "Statistics.h"
#include "Particles.h"
#include "WriteSystem.h"
#include "Parameters.h"


void updateX(Particle *p, double deltaTime){
  int i, d;

  double a = deltaTime * .5 / p -> m;

  for ( d = 0; d < DIM; d++) {
    p -> x[d] += deltaTime * (p -> v[d] + a * p -> f[d]);  /* According to Eq. (A) */
    p -> fOld[d] = p -> f[d];
  }
}


void updateV(Particle *p, double timeDelta){
  int i, d;
  double a = timeDelta * .5 / p -> m;
  for ( d = 0; d < DIM; d++)
    p -> v[d] += a * (p -> f[d] + p -> fOld[d]);  /* According to Eq. (B) */
}


void computeX(Particle *p, int N, double deltaTime){
  int i;

  for (i = 0; i < N; i++)
    updateX(&p[i], deltaTime);
}



void computeV(Particle *p, int N, double deltaTime){
  int i;

  for (i = 0; i < N; i++)
    updateV(&p[i], deltaTime);
}


void timeIntegration(Particle *p, S_Parameter *parameter, char *nameSystemFile, double time)
{
  int counter;
  
  computeForces(p, parameter -> N);
  
  while (time < parameter -> timeEnd) {
    
    time += parameter -> timeDelta;
    counter++;
    
    computeX (p, parameter -> N, parameter -> timeDelta);
     
    computeForces (p, parameter -> N);
      
    computeV (p, parameter -> N, parameter -> timeDelta);
     
    computeStatistics (p, parameter -> N, time);

    if((counter%1000) == 0)
    {
        outputResults(p, parameter -> N, time);
    }
 
    /* In this version, the system file is always written after the 50th and the 10000th timestep */
    /* SUGGESTED CHALLENGE FOR YOU: IMPLEMENT A NEW PARAMETER "saveSystem" THAT IS READ IN BY THE FILE 
       AND THEN SAVE THE SYSTEM EVERY saveSystem TIMESTEPS AUTOMATICALLY.
    */

    if (!(counter%(SAVE_SYSTEM)) ) 
      writeSystemToFile(p, parameter, nameSystemFile, counter);
  }
}
   
