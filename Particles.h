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
#include "Defs.h"

#ifndef __PARTICLES_H
#define __PARTICLES_H
/**
   \struct Particle
*/
typedef struct {
  double m;           /* mass */
  double x[DIM];      /* position */
  double v[DIM];      /* velocity */
  double f[DIM];      /* force */
  double fOld[DIM];   /* Old force - needed for Verlet-velocity */
} Particle;

/* ============================================================== */
#endif
