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

#include "Particles.h"
#include "Forces.h"

void forceCalculate(Particle *i, Particle *j){
  int d;
  double distance = 0.0;
  double force = 0.0;

  for (d = 0; d < DIM; d++)
    distance += sqr(j -> x[d] - i ->x[d]);

  force = i -> m * j -> m / (sqrt(distance) * distance);

  for (d = 0; d < DIM; d++)
    i -> f[d] += force * (j -> x[d] - i -> x[d]);
}




/*================================================================================ */
/**
   void computeForces(Particle *p, int N)

   \brief Computation of the new forces based after \em one timestep 
   using the Verlet-velocity method with the all particle approach

   \param *p A pointer to the particle information
   \param N The total number of particles

   In the basis version of the code the force is calculatied according to 
   \f[ 
   \vec{F}_i=-\nabla_{\vec{x}_i} V(\vec{x}_1,...,\vec{x}_N) = -\sum_{j=1,j\neq i}^{N}
   \nabla_{\vec{x}_i}U(r_{ij})=\sum_{j=1,j\neq i}^{N}\vec{F}_{ij} 
   \f], i.e. the two forces \f$\vec{F}_{ij}\f$ and  \f$\vec{F}_{ji}\f$ are calculated 
   separately.\n\n
   Alternatively, in an improved version, Newton's third law is taken into account, i.e
   the force  \f$\vec{F}_{ji}\f$ need not be calculated if \f$\vec{F}_{ij}\f$ already
   has been evaluated. It is \f$\vec{F}_{ji} = -\vec{F}_{ij}\f$. That way one can save 
   half of the computations of the forces. 

*/
void computeForces(Particle *p, int N)
{
  int d,i,j;

  for (i = 0; i < N; i++) // Comment 
    for (d = 0; d < DIM; d++)
      p[i].f[d] = 0.0;
  /* All forces are now set to zero */

  for (i = 0; i < N; i++)
    for (j = 0; j < N ; j++)
      if (i != j) forceCalculate(&p[i], &p[j]);
}
/*-------------------------------------------------------------------------------- */
