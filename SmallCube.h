#ifndef RUBIK__S_CUBE_CSMALLCUBE_H
#define RUBIK__S_CUBE_CSMALLCUBE_H

#include <string>
#include <vector>
#include <iostream>
class CSmallCube
{
public:
    char L_U_side;
    char L_D_side;
    char L_L_side;
    char L_R_side;
    char L_F_side;
    char L_B_side;

    int position_L_U_side;
    int position_L_D_side;
    int position_L_L_side;
    int position_L_R_side;
    int position_L_F_side;
    int position_L_B_side;

    CSmallCube();

    void u_degree_rotation();

    void d_degree_rotation();

    void r_degree_rotation();

    void l_degree_rotation();

    void f_degree_rotation();

    void b_degree_rotation();
};


#endif
