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
#include "Particles.h"
#include "Parameters.h"

#ifndef __INTEGRATE_H
#define __INTEGRATE_H
extern void updateX(Particle *, double);
extern void updateV(Particle *, double);
extern void computeX(Particle *, int, double);
extern void computeV(Particle *, int, double);
extern void timeIntegration(Particle *, S_Parameter *, char *, double);
#endif
