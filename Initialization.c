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

#include "Initialization.h"
#include "Parameters.h"


/**
   \fn void  initAllData(Particle *p, S_Parameter *parameter)
   
   \brief This function initializes all particle attributes in the structure Particle. For 2D and 3D this has to be
   done explicitly here in the code.

   The case study of planetary motion. This study works in 2D AND 3D. The particle information is always allocated as 3D, but only in
   the 2D case the 3D information is ignored in the corresponding loops.
   
   \param *p The pointer to all particle properties.
   \param *parameter The pointer to all parameters.
*/


void initAllData(Particle *p, S_Parameter *parameter)
{	
      int count = 0,i,j,k;
      for (k = 1.0; k <= 20; k += 2) //z coordinate
    {
        for (i = 1.0; i <= 20; i += 2) //x coordinate
        {
            /* Iterate over columns */
            for (j = 1.0; j <= 20; j += 2) //y coordinate
            {
                /* Print star for each column */
                //printf("*");
                p[count].x[0] = i;
                p[count].x[1] = j;
                p[count].x[2] = k;
                
                p[count].m = 0.000003;
                p[count].v[0] = 0.0;
                p[count].v[1] = 0.0;
                p[count].v[2] = 0.0;
               
                //printf(" %d%d%d", i, j, k);
                printf("\n %2f %2f %2f", p[count].x[0], p[count].x[1], p[count].x[2]);

                count++;
            }

            /* Move to the next line/row */
            printf("\n");
        }
    }
    
    
    //printf("%d",count);
    
    		p[count].x[0] = 40.0;
    		p[count].x[1] = 10.0;
    		p[count].x[2] = 10.0;
    
                p[count].m = 0.000000003;
                p[count].v[0] = -0.296;
                p[count].v[1] = 0.0;
                p[count].v[2] = 0.0;
    
    }

