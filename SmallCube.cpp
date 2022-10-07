#include "SmallCube.h"

CSmallCube::CSmallCube() {
    L_U_side = 'e';
    L_D_side = 'e';
    L_L_side = 'e';
    L_R_side = 'e';
    L_F_side = 'e';
    L_B_side = 'e';

    position_L_U_side = -1;
    position_L_D_side = -1;
    position_L_L_side = -1;
    position_L_R_side = -1;
    position_L_F_side = -1;
    position_L_B_side = -1;

}

void CSmallCube::u_degree_rotation()
{
    std::vector<char> arr = {L_F_side, L_L_side, L_B_side, L_R_side};
    L_F_side = arr[3];
    L_L_side = arr[0];
    L_B_side = arr[1];
    L_R_side = arr[2];
}

void CSmallCube::d_degree_rotation()
{
    std::vector<char> arr = {L_F_side, L_L_side, L_B_side, L_R_side};
    L_F_side = arr[1];
    L_L_side = arr[2];
    L_B_side = arr[3];
    L_R_side = arr[0];
}

void CSmallCube::r_degree_rotation()
{
    std::vector<char> arr = {L_F_side, L_B_side, L_U_side, L_D_side};
    L_F_side = arr[3];
    L_D_side = arr[1];
    L_B_side = arr[2];
    L_U_side = arr[0];

}

void CSmallCube::l_degree_rotation()
{
    std::vector<char> arr = {L_F_side, L_B_side, L_U_side, L_D_side};
    L_F_side = arr[2];
    L_D_side = arr[0];
    L_B_side = arr[3];
    L_U_side = arr[1];
}

void CSmallCube::f_degree_rotation()
{
    std::vector<char> arr = {L_L_side, L_R_side, L_U_side, L_D_side};
    L_L_side = arr[3];
    L_R_side = arr[2];
    L_U_side = arr[0];
    L_D_side = arr[1];
}

void CSmallCube::b_degree_rotation()
{
    std::vector<char> arr = {L_L_side, L_R_side, L_U_side, L_D_side};
    L_L_side = arr[2];
    L_R_side = arr[3];
    L_U_side = arr[1];
    L_D_side = arr[0];
}



