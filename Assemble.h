#ifndef RUBIK__S_CUBE_ASSEMBLINGRUBIKSCUBE_H
#define RUBIK__S_CUBE_ASSEMBLINGRUBIKSCUBE_H

#include "SmallCube.h"
#include "RubikCube.h"

class AssemblingRubiksCube {
private:
    CRubicsCube assembleCube;
public:
    AssemblingRubiksCube(CRubicsCube cube);


    bool check_nn_cross(); //wrong cross check

    void assembling_cross();//assembling incorrect cross
    void pif_paf_up(char side);//for first layer corners
    bool check_neighboring_side(char side);//neighbours check
    bool check_up_white();//check on white tops
    void assembling_white_side();//white side assemble
    void side_selection(char side);//for second layer
    void second_layer();//second layer assemble
    bool check_yellow_cross();//third layer cross check
    void assembling_yellow_cross();//third layer cross assemble
    void assembling_true_angle();//for third layer corners
    void turning_corners();//corners
    void final();
    CRubicsCube assemble();

    static bool invariance(CRubicsCube one);
};


#endif
