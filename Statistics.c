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
#include "Statistics.h"

void computeStatistics(Particle *p, int N, double time){

  int i, d;
  double velocity;
  double energy = 0.;

  for (i = 0; i < N; i++){

    velocity = 0.;

    for (d = 0; d < DIM; d++)
      velocity += sqr(p[i].v[d]);
    
    energy += .5 * p[i].m * velocity;
  }
  /* If you want: insert a function here, that prints out the kinetic energy 
     at this timestep time */
  /* printf("Check: E_kin = %f\n",energy); */
}


/* REMARK: In this function you'd have to add the functionality to print and/or store 
   the data of the different masses.
*/
void outputResults(Particle *p, int N, double time){

  static int once = 1;

  if (once){
    /* printf("# First Point Mass:  time X  Y  Z\n"); */
/*     printf("# remark: You find this in Statistics.c\n"); */
    //once = 0;
    
    int i;
    char fname[20];
    FILE* WriteOutput;

    sprintf(fname, "snapshot_%d.txt", once );
    WriteOutput = fopen(fname,"w");
    if (!WriteOutput)
    { 
       printf(" .dat file could not be created !\n");
    }
    else
    {
    	for( i = 0; i < 1001; ++i)
    	{
    		fprintf(WriteOutput, "%lf, %lf, %lf\n", p[i].x[0], p[i].x[1], p[i].x[2]);	
    	}
       
    }
    fclose(WriteOutput);
    
    once++;

    /*
    FILE* WriteOutput;
    WriteOutput = fopen("DebriParticle.dat","a");
    if (!WriteOutput)
    { 
       printf("DebriParticle.txt could not be created !\n");
    }
    else
    {
       fprintf(WriteOutput, "%lf, %lf, %lf\n", p[1000].x[0], p[1000].x[1], p[1000].x[2]);
    }
    fclose(WriteOutput);  */

/*   printf(" %f %f %f %f\n",time, p[4].x[0], p[4].x[1], p[4].x[2]); */
}
}

