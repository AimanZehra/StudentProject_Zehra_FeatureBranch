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

#ifndef __DATA_PARAMETERS_H
#define __DATA_PARAMETERS_H



/* ============================================================= */
/** \file  DataParameter.h
    \brief The list of simulation variables which is passed to 
    most functions. The variables this list are initialized by 
    the given values of the input file InputParams.dat.

    \version 1.0
    \date 01 Dec 2011
    \author Dr. rer. nat. Martin O. Steinhauser

    Email: Martin.Steinhauser@emi.fraunhofer.de

    Actually, always a \em pointer to a local instance 
    (declared in main.c) of S_Parameter is passed to each 
    function such that each function always works with the 
    \em original data and \em not with a local copy of them. 
 */
/* ============================================================= */




/* ============================================================= */
/** \struct Parameter
    \brief A structure that is used in almost every module, 
    but centrally located here.

    This structure contains \em all simulation parameters 
    which are centrally located here and which are initialized 
    by the external \em infile input file.\n
    
    \note The order of the parameters in this structure is not 
    the same as in the external \em infile. This doesn't matter, as the 
    infile is first parsed and then those values are assigned to the 
    correct local parameters in \ref IoHandling.c.
    The analyze functions rely on the size of the structure T_Parameter.

    A new parameter is added as follows:\n
    \arg Add the parameter at the end of the list in struct S_Parameter.
    \arg Add a new KEY_WORD anywhere in the external input-file. Better, insert it, where it
    fits logically.
    \arg Add the same new KEY_WORD at the end of the list \em char \em keywords[][100] in
    \see Initialization.c
    \arg Add the KEY_WORD TYPE at the same place in the list \em char \em keyword_type[][100]
    in \see Initialization.c
    \arg Add the assignment of the parameters of struct \ref S_Parameter in \see Initialization.c
    \arg Done. Now the new keyword can be used in the code.
*/
/* ============================================================= */



struct Parameter
{
  /* Simple Parameters */
  int N;
  double timeDelta;
  double timeEnd;
  double radius;

  /* Particles' Parameters */
  /** \note In principle, the number of parameters could be
      completely allocated dynamically, depending on the actual number
      of parameters really provided by the input file. However, I
      don't want to bother with this - normaly, you don't assign the
      particles' positions and velocities via the inputfile, but
      by a function within the code. Imagine, you'd have to assign
      these data by an input file for 10^6 particles - that's nonsense.
      So I do it the easy way for this exercise like the following:
      1. I declare all variables here.
      2. These are initialized by reading in the values from the input
      file.
      3. Then, these variables are passed to the old function initAllData(),
      where the actual masses, positions and velocities are assigned
      exactly like before, just that the values are now not hard-coded
      but the values from the input file.
  */
  /* BODY 0 */
  double mass0;
  double position0_X;
  double position0_Y;
  double position0_Z;
  double velocity0_X;
  double velocity0_Y;
  double velocity0_Z;

  /* BODY 1 */
  double mass1;
  double position1_X;
  double position1_Y;
  double position1_Z;
  double velocity1_X;
  double velocity1_Y;
  double velocity1_Z;

  /* BODY 2 */
  double mass2;
  double position2_X;
  double position2_Y;
  double position2_Z;
  double velocity2_X;
  double velocity2_Y;
  double velocity2_Z;

  /* BODY 3 */
  double mass3;
  double position3_X;
  double position3_Y;
  double position3_Z;
  double velocity3_X;
  double velocity3_Y;
  double velocity3_Z;

  /* BODY 4 */
  double mass4;
  double position4_X;
  double position4_Y;
  double position4_Z;
  double velocity4_X;
  double velocity4_Y;
  double velocity4_Z;

  /* BODY 5 */
  double mass5;
  double position5_X;
  double position5_Y;
  double position5_Z;
  double velocity5_X;
  double velocity5_Y;
  double velocity5_Z;
};
typedef struct Parameter S_Parameter;
#endif
