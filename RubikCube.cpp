#include "RubikCube.h"

CRubicsCube::CRubicsCube()
{
    cube = std::vector<std::vector<std::vector<CSmallCube>>>
    (3, std::vector<std::vector<CSmallCube >>(3,
            std::vector<CSmallCube>(3,CSmallCube())));
    default_colors();
}

void CRubicsCube::default_colors()
{

    for (int x = 0; x < 3; x++)
        for (int z = 0; z < 3; z++)
            cube[x][2][z].L_U_side = 'y';


    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            cube[x][y][2].L_F_side = 'b';


    for (int z = 0; z < 3; z++)
        for (int y = 0; y < 3; y++)
            cube[0][y][z].L_L_side = 'o';


    for (int z = 0; z < 3; z++)
        for (int y = 0; y < 3; y++)
            cube[2][y][z].L_R_side = 'r';


    for (int x = 0; x < 3; x++)
        for (int z = 0; z < 3; z++)
            cube[x][0][z].L_D_side = 'w';

    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            cube[x][y][0].L_B_side = 'g';

}

void CRubicsCube::printCube()
{
    int score = 0;
    std::cout << "   cube print:" << std::endl;
    for (int z = 0; z < 3; z++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (score == 3)
            {
                std::cout << std::endl;
                score = 0;
            }
            if(score == 0)
                std::cout <<"       ";
            std::cout << cube[x][2][z].L_U_side << " ";
            score++;
        }
    }

    std::cout <<std::endl;
    for(int x = 2; x >= 0; x--)
    {
        for (int i = 0; i < 3; i++)
            std::cout << cube[0][x][i].L_L_side << " ";
        std::cout<<" ";
        for (int i = 0; i < 3; i++)
            std::cout << cube[i][x][2].L_F_side << " ";
        std::cout<<" ";
        for (int i = 0; i < 3; i++)
            std::cout << cube[2][x][2-i].L_R_side << " ";
        std::cout <<std::endl;
    }
    score = 0;
    for (int z = 2; z >= 0; z--)
    {
        for (int x = 0; x < 3; x++)
        {
            if (score == 3)
            {
                std::cout << std::endl;
                score = 0;
            }
            if(score == 0)
                std::cout <<"       ";
            std::cout << cube[x][0][z].L_D_side << " ";
            score++;
        }
    }
    for (int y = 2; y >= 0; y--)
    {
        for (int x = 2; x >= 0; x--)
        {
            if (score == 3)
            {
                std::cout << std::endl;
                score = 0;
            }
            if(score == 0)
                std::cout <<"       ";
            std::cout << cube[x][y][0].L_B_side << " ";
            score++;
        }
    }
    std::cout << std::endl;
}

void CRubicsCube::turn_clockwise(char side)
{
    if(side == 'U')
    {
        std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
        positionCubes('U');
        for (int z = 0; z < 3; z++)
            for (int x = 0; x < 3; x++)
                if (cube[x][2][z].position_L_U_side == 1)
                {
                    backup_cube[2][2][0] = cube[x][2][z];
                    backup_cube[2][2][0].position_L_U_side = 3;
                    backup_cube[2][2][0].u_degree_rotation();
                }
                else if (cube[x][2][z].position_L_U_side == 2)
                {
                    backup_cube[2][2][1] = cube[x][2][z];
                    backup_cube[2][2][1].position_L_U_side = 4;
                    backup_cube[2][2][1].u_degree_rotation();
                }
                else if (cube[x][2][z].position_L_U_side == 3)
                {
                    backup_cube[2][2][2] = cube[x][2][z];
                    backup_cube[2][2][2].position_L_U_side = 5;
                    backup_cube[2][2][2].u_degree_rotation();
                }
                else if (cube[x][2][z].position_L_U_side == 4)
                {
                    backup_cube[1][2][2] = cube[x][2][z];
                    backup_cube[1][2][2].position_L_U_side = 6;
                    backup_cube[1][2][2].u_degree_rotation();
                }
                else if (cube[x][2][z].position_L_U_side == 5)
                {
                    backup_cube[0][2][2] = cube[x][2][z];
                    backup_cube[0][2][2].position_L_U_side = 7;
                    backup_cube[0][2][2].u_degree_rotation();
                }
                else if (cube[x][2][z].position_L_U_side == 6)
                {
                    backup_cube[0][2][1] = cube[x][2][z];
                    backup_cube[0][2][1].position_L_U_side = 8;
                    backup_cube[0][2][1].u_degree_rotation();
                }
                else if (cube[x][2][z].position_L_U_side == 7)
                {
                    backup_cube[0][2][0] = cube[x][2][z];
                    backup_cube[0][2][0].position_L_U_side = 1;
                    backup_cube[0][2][0].u_degree_rotation();
                }
                else if (cube[x][2][z].position_L_U_side == 8)
                {
                    backup_cube[1][2][0] = cube[x][2][z];
                    backup_cube[1][2][0].position_L_U_side = 2;
                    backup_cube[1][2][0].u_degree_rotation();
                }
        cube = backup_cube;
    }
    else if(side == 'D')
    {
        std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
        positionCubes('D');
        for (int z = 0; z < 3; z++) {
            for (int x = 0; x < 3; x++) {
                if (cube[x][0][z].position_L_D_side == 1)
                {
                    backup_cube[2][0][2] = cube[x][0][z];
                    backup_cube[2][0][2].position_L_D_side = 3;
                    backup_cube[2][0][2].d_degree_rotation();
                }
                else if (cube[x][0][z].position_L_D_side == 2)
                {
                    backup_cube[2][0][1] = cube[x][0][z];
                    backup_cube[2][0][1].position_L_D_side = 4;
                    backup_cube[2][0][1].d_degree_rotation();
                }
                else if (cube[x][0][z].position_L_D_side == 3)
                {
                    backup_cube[2][0][0] = cube[x][0][z];
                    backup_cube[2][0][0].position_L_D_side = 5;
                    backup_cube[2][0][0].d_degree_rotation();
                }
                else if (cube[x][0][z].position_L_D_side == 4)
                {
                    backup_cube[1][0][0] = cube[x][0][z];
                    backup_cube[1][0][0].position_L_D_side = 6;
                    backup_cube[1][0][0].d_degree_rotation();
                }
                else if (cube[x][0][z].position_L_D_side == 5)
                {
                    backup_cube[0][0][0] = cube[x][0][z];
                    backup_cube[0][0][0].position_L_D_side = 7;
                    backup_cube[0][0][0].d_degree_rotation();
                }
                else if (cube[x][0][z].position_L_D_side == 6)
                {
                    backup_cube[0][0][1] = cube[x][0][z];
                    backup_cube[0][0][1].position_L_D_side = 8;
                    backup_cube[0][0][1].d_degree_rotation();
                }
                else if (cube[x][0][z].position_L_D_side == 7)
                {
                    backup_cube[0][0][2] = cube[x][0][z];
                    backup_cube[0][0][2].position_L_D_side = 1;
                    backup_cube[0][0][2].d_degree_rotation();
                }
                else if (cube[x][0][z].position_L_D_side == 8)
                {
                    backup_cube[1][0][2] = cube[x][0][z];
                    backup_cube[1][0][2].position_L_D_side = 2;
                    backup_cube[1][0][2].d_degree_rotation();
                }
            }
        }
        cube = backup_cube;
    }
    else if(side == 'R')
    {
        std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
        positionCubes('R');
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                if (cube[2][y][z].position_L_R_side == 1)
                {
                    backup_cube[2][2][0] = cube[2][y][z];
                    backup_cube[2][2][0].position_L_R_side = 3;
                    backup_cube[2][2][0].r_degree_rotation();
                }
                else if (cube[2][y][z].position_L_R_side == 2)
                {
                    backup_cube[2][1][0] = cube[2][y][z];
                    backup_cube[2][1][0].position_L_R_side = 4;
                    backup_cube[2][1][0].r_degree_rotation();
                }
                else if (cube[2][y][z].position_L_R_side == 3)
                {
                    backup_cube[2][0][0] = cube[2][y][z];
                    backup_cube[2][0][0].position_L_R_side = 5;
                    backup_cube[2][0][0].r_degree_rotation();
                }
                else if (cube[2][y][z].position_L_R_side == 4)
                {
                    backup_cube[2][0][1] = cube[2][y][z];
                    backup_cube[2][0][1].position_L_R_side = 6;
                    backup_cube[2][0][1].r_degree_rotation();
                }
                else if (cube[2][y][z].position_L_R_side == 5)
                {
                    backup_cube[2][0][2] = cube[2][y][z];
                    backup_cube[2][0][2].position_L_R_side = 7;
                    backup_cube[2][0][2].r_degree_rotation();
                }
                else if (cube[2][y][z].position_L_R_side == 6)
                {
                    backup_cube[2][1][2] = cube[2][y][z];
                    backup_cube[2][1][2].position_L_R_side = 8;
                    backup_cube[2][1][2].r_degree_rotation();
                }
                else if (cube[2][y][z].position_L_R_side == 7)
                {
                    backup_cube[2][2][2] = cube[2][y][z];
                    backup_cube[2][2][2].position_L_R_side = 1;
                    backup_cube[2][2][2].r_degree_rotation();
                }
                else if (cube[2][y][z].position_L_R_side == 8)
                {
                    backup_cube[2][2][1] = cube[2][y][z];
                    backup_cube[2][2][1].position_L_R_side = 2;
                    backup_cube[2][2][1].r_degree_rotation();
                }
            }
        }
        cube = backup_cube;
    }
    else if(side == 'L')
    {
        std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
        positionCubes('L');
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                if (cube[0][y][z].position_L_L_side == 1)
                {
                    backup_cube[0][2][2] = cube[0][y][z];
                    backup_cube[0][2][2].position_L_L_side = 3;
                    backup_cube[0][2][2].l_degree_rotation();
                }
                else if (cube[0][y][z].position_L_L_side == 2)
                {
                    backup_cube[0][1][2] = cube[0][y][z];
                    backup_cube[0][1][2].position_L_L_side = 4;
                    backup_cube[0][1][2].l_degree_rotation();
                }
                else if (cube[0][y][z].position_L_L_side == 3)
                {
                    backup_cube[0][0][2] = cube[0][y][z];
                    backup_cube[0][0][2].position_L_L_side = 5;
                    backup_cube[0][0][2].l_degree_rotation();
                }
                else if (cube[0][y][z].position_L_L_side == 4)
                {
                    backup_cube[0][0][1] = cube[0][y][z];
                    backup_cube[0][0][1].position_L_L_side = 6;
                    backup_cube[0][0][1].l_degree_rotation();
                }
                else if (cube[0][y][z].position_L_L_side == 5)
                {
                    backup_cube[0][0][0] = cube[0][y][z];
                    backup_cube[0][0][0].position_L_L_side = 7;
                    backup_cube[0][0][0].l_degree_rotation();
                }
                else if (cube[0][y][z].position_L_L_side == 6)
                {
                    backup_cube[0][1][0] = cube[0][y][z];
                    backup_cube[0][1][0].position_L_L_side = 8;
                    backup_cube[0][1][0].l_degree_rotation();
                }
                else if (cube[0][y][z].position_L_L_side == 7)
                {
                    backup_cube[0][2][0] = cube[0][y][z];
                    backup_cube[0][2][0].position_L_L_side = 1;
                    backup_cube[0][2][0].l_degree_rotation();
                }
                else if (cube[0][y][z].position_L_L_side == 8)
                {
                    backup_cube[0][2][1] = cube[0][y][z];
                    backup_cube[0][2][1].position_L_L_side = 2;
                    backup_cube[0][2][1].l_degree_rotation();
                }
            }

        }
        cube = backup_cube;
    }
    else if(side == 'F')
    {
        std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
        positionCubes('F');
        for (int y = 0; y < 3; y++)
            for (int x = 0; x < 3; x++)
                if (cube[x][y][2].position_L_F_side == 1)
                {
                    backup_cube[2][2][2] = cube[x][y][2];
                    backup_cube[2][2][2].position_L_F_side = 3;
                    backup_cube[2][2][2].f_degree_rotation();
                }
                else if (cube[x][y][2].position_L_F_side == 2)
                {
                    backup_cube[2][1][2] = cube[x][y][2];
                    backup_cube[2][1][2].position_L_F_side = 4;
                    backup_cube[2][1][2].f_degree_rotation();
                }
                else if (cube[x][y][2].position_L_F_side == 3)
                {
                    backup_cube[2][0][2] = cube[x][y][2];
                    backup_cube[2][0][2].position_L_F_side = 5;
                    backup_cube[2][0][2].f_degree_rotation();
                }
                else if (cube[x][y][2].position_L_F_side == 4)
                {
                    backup_cube[1][0][2] = cube[x][y][2];
                    backup_cube[1][0][2].position_L_F_side = 6;
                    backup_cube[1][0][2].f_degree_rotation();
                }
                else if (cube[x][y][2].position_L_F_side == 5)
                {
                    backup_cube[0][0][2] = cube[x][y][2];
                    backup_cube[0][0][2].position_L_F_side = 7;
                    backup_cube[0][0][2].f_degree_rotation();
                }
                else if (cube[x][y][2].position_L_F_side == 6)
                {
                    backup_cube[0][1][2] = cube[x][y][2];
                    backup_cube[0][1][2].position_L_F_side = 8;
                    backup_cube[0][1][2].f_degree_rotation();
                }
                else if (cube[x][y][2].position_L_F_side == 7)
                {
                    backup_cube[0][2][2] = cube[x][y][2];
                    backup_cube[0][2][2].position_L_F_side = 1;
                    backup_cube[0][2][2].f_degree_rotation();
                }
                else if (cube[x][y][2].position_L_F_side == 8)
                {
                    backup_cube[1][2][2] = cube[x][y][2];
                    backup_cube[1][2][2].position_L_F_side = 2;
                    backup_cube[1][2][2].f_degree_rotation();
                }
        cube = backup_cube;
    }
    else if(side == 'B')
    {
        std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
        positionCubes('B');
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                if (cube[x][y][0].position_L_B_side == 1)
                {
                    backup_cube[0][2][0] = cube[x][y][0];
                    backup_cube[0][2][0].position_L_B_side = 3;
                    backup_cube[0][2][0].b_degree_rotation();
                }
                else if (cube[x][y][0].position_L_B_side == 2)
                {
                    backup_cube[0][1][0] = cube[x][y][0];
                    backup_cube[0][1][0].position_L_B_side = 4;
                    backup_cube[0][1][0].b_degree_rotation();
                }
                else if (cube[x][y][0].position_L_B_side == 3)
                {
                    backup_cube[0][0][0] = cube[x][y][0];
                    backup_cube[0][0][0].position_L_B_side = 5;
                    backup_cube[0][0][0].b_degree_rotation();
                }
                else if (cube[x][y][0].position_L_B_side == 4)
                {
                    backup_cube[1][0][0] = cube[x][y][0];
                    backup_cube[1][0][0].position_L_B_side = 6;
                    backup_cube[1][0][0].b_degree_rotation();
                }
                else if (cube[x][y][0].position_L_B_side == 5)
                {
                    backup_cube[2][0][0] = cube[x][y][0];
                    backup_cube[2][0][0].position_L_B_side = 7;
                    backup_cube[2][0][0].b_degree_rotation();
                }
                else if (cube[x][y][0].position_L_B_side == 6)
                {
                    backup_cube[2][1][0] = cube[x][y][0];
                    backup_cube[2][1][0].position_L_B_side = 8;
                    backup_cube[2][1][0].b_degree_rotation();
                }
                else if (cube[x][y][0].position_L_B_side == 7)
                {
                    backup_cube[2][2][0] = cube[x][y][0];
                    backup_cube[2][2][0].position_L_B_side = 1;
                    backup_cube[2][2][0].b_degree_rotation();
                }
                else if (cube[x][y][0].position_L_B_side == 8)
                {
                    backup_cube[1][2][0] = cube[x][y][0];
                    backup_cube[1][2][0].position_L_B_side = 2;
                    backup_cube[1][2][0].b_degree_rotation();
                }
            }
        }
        cube = backup_cube;
    }
}

void CRubicsCube::turn_counterclockwise(char side)
{
    turn_clockwise(side);
    turn_clockwise(side);
    turn_clockwise(side);
}

void CRubicsCube::positionCubes(char side)
{
    if (side == 'U')
    {
        for (int z = 0; z < 3; z++)
            for (int x = 0; x < 3; x++)
                if (z == 0)
                    cube[x][2][z].position_L_U_side = x + 1;
                else if (z == 1)
                {
                    if (x == 0)
                        cube[x][2][z].position_L_U_side = 8;
                    else if (x == 2)
                        cube[x][2][z].position_L_U_side = 4;
                }
                else if (z == 2)
                    cube[x][2][z].position_L_U_side = abs(x - 7);
    }
    else if (side == 'D')
    {
        for (int z = 2; z >= 0; z--)
            for (int x = 0; x < 3; x++)
                if (z == 2)
                    cube[x][0][z].position_L_D_side = x + 1;
                else if (z == 1)
                {
                    if (x == 0)

                        cube[x][0][z].position_L_D_side = 8;
                    else if (x == 2)
                        cube[x][0][z].position_L_D_side = 4;

                }
                else if (z == 0)
                    cube[x][0][z].position_L_D_side = abs(x - 7);
    }
    else if (side == 'R')
    {
        for (int y = 2; y >= 0; y--)
        {
            for (int z = 0; z < 3; z++) {
                if (y == 2) {
                    cube[2][y][z].position_L_R_side = abs(z - 3);
                } else if (y == 1) {
                    if (z == 0) {
                        cube[2][y][z].position_L_R_side = 4;
                    } else if (z == 2) {
                        cube[2][y][z].position_L_R_side = 8;
                    }
                } else if (y == 0) {
                    cube[2][y][z].position_L_R_side = z + 5;
                }
            }
        }
    } else if (side == 'L') {
        for (int y = 2; y >= 0; y--) {
            for (int z = 0; z < 3; z++) {
                if (y == 2) {
                    cube[0][y][z].position_L_L_side = z + 1;
                } else if (y == 1) {
                    if (z == 0) {
                        cube[0][y][z].position_L_L_side = 8;
                    } else if (z == 2) {
                        cube[0][y][z].position_L_L_side = 4;
                    }
                } else if (y == 0) {
                    cube[0][y][z].position_L_L_side = abs(z - 7);
                }
            }
        }
    } else if (side == 'F') {
        for (int y = 2; y >= 0; y--) {
            for (int x = 0; x < 3; x++) {
                if (y == 2) {
                    cube[x][y][2].position_L_F_side = x + 1;
                } else if (y == 1) {
                    if (x == 0) {
                        cube[x][y][2].position_L_F_side = 8;
                    } else if (x == 2) {
                        cube[x][y][2].position_L_F_side = 4;
                    }
                } else if (y == 0) {
                    cube[x][y][2].position_L_F_side = abs(x - 7);
                }
            }
        }
    } else if (side == 'B') {
        for (int y = 2; y >= 0; y--) {
            for (int x = 0; x < 3; x++) {
                if (y == 2) {
                    cube[x][y][0].position_L_B_side = abs(x - 3);
                } else if (y == 1) {
                    if (x == 0) {
                        cube[x][y][0].position_L_B_side = 4;
                    } else if (x == 2) {
                        cube[x][y][0].position_L_B_side = 8;
                    }
                } else if (y == 0) {
                    cube[x][y][0].position_L_B_side = x + 5;
                }
            }
        }
    }
}

CRubicsCube &CRubicsCube::operator=(const CRubicsCube &other)
= default;

void CRubicsCube::writing_file() {
    int score = 0;
    std::ofstream out;
    out.open("../output.txt");
    out << "   cube print:" << std::endl;
    for (int z = 0; z < 3; z++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (score == 3)
            {
                out << std::endl;
                score = 0;
            }
            if(score == 0)
                out <<"       ";
            out << cube[x][2][z].L_U_side << " ";
            score++;
        }
    }

    out <<std::endl;
    for(int x = 2; x >= 0; x--)
    {
        for (int i = 0; i < 3; i++)
            out << cube[0][x][i].L_L_side << " ";
        out<<" ";
        for (int i = 0; i < 3; i++)
            out << cube[i][x][2].L_F_side << " ";
        out<<" ";
        for (int i = 0; i < 3; i++)
            out << cube[2][x][2-i].L_R_side << " ";
        out <<std::endl;
    }
    score = 0;
    for (int z = 2; z >= 0; z--)
    {
        for (int x = 0; x < 3; x++)
        {
            if (score == 3)
            {
                out << std::endl;
                score = 0;
            }
            if(score == 0)
                out <<"       ";
            out << cube[x][0][z].L_D_side << " ";
            score++;
        }
    }
    for (int y = 2; y >= 0; y--)
    {
        for (int x = 2; x >= 0; x--)
        {
            if (score == 3)
            {
                out << std::endl;
                score = 0;
            }
            if(score == 0)
                out <<"       ";
            out << cube[x][y][0].L_B_side << " ";
            score++;
        }
    }
    out << std::endl;
    out.close();
}

void CRubicsCube::read_file()
{
    std::vector<std::vector<std::vector<CSmallCube>>> backup_cube = cube;
    std::ifstream fin;
    fin.open("../input.txt");
    for (int z = 0; z < 3; z++)
        for (int x = 0; x < 3; x++)
            fin >> cube[x][2][z].L_U_side;

    for (int y = 2; y >= 0; y--)
        for (int z = 0; z < 3; z++)
            fin >> cube[0][y][z].L_L_side;

    for (int y = 2; y >= 0; y--)
        for (int x = 0; x < 3; x++)
            fin >> cube[x][y][2].L_F_side;

    for (int y = 2; y >= 0; y--)
        for (int z = 2; z >= 0; z--)
            fin >> cube[2][y][z].L_R_side;

    for (int z = 2; z >= 0; z--)
        for (int x = 0; x < 3; x++)
            fin >> cube[x][0][z].L_D_side;

    for (int y = 2; y >= 0; y--)
        for (int x = 2; x >= 0; x--)
            fin >> cube[x][y][0].L_B_side;
    fin.close();
}

void CRubicsCube::random_turn()
{
    int k = 0;
    for(int i = 0 ; i < 20; i++)
    {
        k = rand() % 10;
        if (k==0)
            turn_clockwise('F');
        else if (k==1)
            turn_clockwise('B');
        else if (k==2)
            turn_clockwise('L');
        else if (k==3)
            turn_clockwise('R');
        else if (k==4)
            turn_clockwise('D');
        else if (k==5)
            turn_clockwise('U');
        else if (k==6)
            turn_counterclockwise('L');
        else if (k==7)
            turn_counterclockwise('D');
        else if (k==8)
            turn_counterclockwise('F');
        else if (k==9)
            turn_counterclockwise('B');
    }
}

