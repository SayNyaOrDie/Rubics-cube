#include "Assemble.h"

AssemblingRubiksCube::AssemblingRubiksCube(CRubicsCube cube)
{
    assembleCube = cube;
}


bool AssemblingRubiksCube::check_nn_cross()
{
    std::vector<int> position;
    bool crossCheck = true;

    assembleCube.positionCubes('U');
    if (assembleCube.cube[1][2][0].L_U_side == 'w')
        position.push_back(assembleCube.cube[1][2][0].position_L_U_side);
    else crossCheck = false;

    if (assembleCube.cube[2][2][1].L_U_side == 'w')
        position.push_back(assembleCube.cube[2][2][1].position_L_U_side);
    else crossCheck = false;

    if (assembleCube.cube[1][2][2].L_U_side == 'w')
        position.push_back(assembleCube.cube[1][2][2].position_L_U_side);
    else crossCheck = false;

    if (assembleCube.cube[0][2][1].L_U_side == 'w')
        position.push_back(assembleCube.cube[0][2][1].position_L_U_side);
    else crossCheck = false;

    return crossCheck;
}

void AssemblingRubiksCube::assembling_cross()
{

    //assemble incorrect white cross
    for(int k = 0;k<24;k++)
    {
        if (!check_nn_cross())
        {
            if (assembleCube.cube[0][1][2].L_F_side == 'w')
            {
                if (assembleCube.cube[0][2][1].L_U_side == 'w')
                {
                    while (assembleCube.cube[0][2][1].L_U_side == 'w')
                        assembleCube.turn_clockwise('U');

                    assembleCube.turn_counterclockwise('L');
                }
                else
                    assembleCube.turn_counterclockwise('L');
            }

            if (assembleCube.cube[2][1][2].L_F_side == 'w')
            {
                if (assembleCube.cube[2][2][1].L_U_side == 'w')
                {
                    while (assembleCube.cube[2][2][1].L_U_side == 'w')
                        assembleCube.turn_clockwise('U');
                    assembleCube.turn_clockwise('R');
                }
                else
                    assembleCube.turn_clockwise('R');
            }

            if (assembleCube.cube[1][2][2].L_F_side == 'w')
            {
                assembleCube.turn_clockwise('F');
                if (assembleCube.cube[2][2][1].L_U_side == 'w')
                {
                    while (assembleCube.cube[2][2][1].L_U_side == 'w')
                        assembleCube.turn_clockwise('U');

                    assembleCube.turn_clockwise('R');

                    if (assembleCube.cube[1][2][2].L_U_side == 'w')
                    {
                        if (!check_nn_cross())
                            while (assembleCube.cube[1][2][2].L_U_side == 'w')
                                assembleCube.turn_clockwise('U');
                        assembleCube.turn_counterclockwise('F');
                    }
                    else
                        assembleCube.turn_counterclockwise('F');
                }
                else
                {
                    assembleCube.turn_clockwise('R');
                    if (assembleCube.cube[1][2][2].L_U_side == 'w')
                    {
                        if (!check_nn_cross())
                            while (assembleCube.cube[1][2][2].L_U_side == 'w')
                                assembleCube.turn_clockwise('U');
                        assembleCube.turn_counterclockwise('F');
                    }
                    else
                        assembleCube.turn_counterclockwise('F');
                }
            }

            if (assembleCube.cube[1][0][2].L_F_side == 'w')
            {
                if (assembleCube.cube[1][2][2].L_U_side == 'w')
                {
                    while (assembleCube.cube[1][2][2].L_U_side == 'w')
                        assembleCube.turn_clockwise('U');

                    assembleCube.turn_counterclockwise('F');
                }
                else
                    assembleCube.turn_counterclockwise('F');

                if (assembleCube.cube[2][2][1].L_U_side == 'w')
                {
                    while (assembleCube.cube[2][2][1].L_U_side == 'w')
                        assembleCube.turn_clockwise('U');

                    assembleCube.turn_clockwise('R');
                    if (assembleCube.cube[1][2][2].L_U_side == 'w')
                    {
                        if (!check_nn_cross())
                        {
                            while (assembleCube.cube[1][2][2].L_U_side == 'w')
                                assembleCube.turn_clockwise('U');

                            assembleCube.turn_clockwise('F');
                        }
                    }
                    else
                        assembleCube.turn_clockwise('F');
                }
                else
                {
                    assembleCube.turn_clockwise('R');
                    if (assembleCube.cube[1][2][2].L_U_side == 'w')
                    {
                        if (!check_nn_cross())
                        {
                            while (assembleCube.cube[1][2][2].L_U_side == 'w')
                                assembleCube.turn_clockwise('U');

                            assembleCube.turn_clockwise('F');
                        }

                    }
                    else
                        assembleCube.turn_clockwise('F');
                }
            }

            if (assembleCube.cube[0][1][0].L_L_side == 'w')
            {
                if (assembleCube.cube[1][2][0].L_U_side == 'w')
                {
                    while (assembleCube.cube[1][2][0].L_U_side == 'w')
                        assembleCube.turn_clockwise('U');

                    assembleCube.turn_counterclockwise('B');
                }
                else
                    assembleCube.turn_counterclockwise('B');
            }

            if (assembleCube.cube[0][1][2].L_L_side == 'w')
            {
                if (assembleCube.cube[1][2][2].L_U_side == 'w')
                {
                    while (assembleCube.cube[1][2][2].L_U_side == 'w')
                        assembleCube.turn_clockwise('U');

                    assembleCube.turn_clockwise('F');
                }
                else
                    assembleCube.turn_clockwise('F');
            }

            if (assembleCube.cube[0][2][1].L_L_side == 'w')
            {
                assembleCube.turn_clockwise('L');
                if (assembleCube.cube[1][2][2].L_U_side == 'w')
                {
                    while (assembleCube.cube[1][2][2].L_U_side == 'w')
                        assembleCube.turn_clockwise('U');

                    assembleCube.turn_clockwise('F');
                    if (assembleCube.cube[0][2][1].L_U_side == 'w')
                    {
                        if (!check_nn_cross())
                        {
                            while (assembleCube.cube[0][2][1].L_U_side == 'w')
                                assembleCube.turn_clockwise('U');

                            assembleCube.turn_counterclockwise('L');
                        }


                    }
                    else
                        assembleCube.turn_counterclockwise('L');
                }
                else
                {
                    assembleCube.turn_clockwise('F');
                    if (assembleCube.cube[0][2][1].L_U_side == 'w')
                    {
                        if (!check_nn_cross())
                        {
                            while (assembleCube.cube[0][2][1].L_U_side == 'w')
                                assembleCube.turn_clockwise('U');
                            assembleCube.turn_counterclockwise('L');
                        }


                    }
                    else
                        assembleCube.turn_counterclockwise('L');
                }
            }

            if (assembleCube.cube[0][0][1].L_L_side == 'w')
            {
                if (assembleCube.cube[0][2][1].L_U_side == 'w')
                {
                    while (assembleCube.cube[0][2][1].L_U_side == 'w')
                        assembleCube.turn_clockwise('U');

                    assembleCube.turn_counterclockwise('L');
                }
                else
                    assembleCube.turn_counterclockwise('L');
            }

            if (assembleCube.cube[1][2][2].L_U_side == 'w')
            {
                while (assembleCube.cube[1][2][2].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_clockwise('F');
                if (assembleCube.cube[0][2][1].L_U_side == 'w')
                {
                    if (!check_nn_cross())
                    {
                        while (assembleCube.cube[0][2][1].L_U_side == 'w')
                            assembleCube.turn_clockwise('U');

                        assembleCube.turn_clockwise('L');
                    }

                }
                else
                    assembleCube.turn_clockwise('L');
            }
            else
            {
                assembleCube.turn_clockwise('F');
                if (assembleCube.cube[0][2][1].L_U_side == 'w')
                {
                    if (!check_nn_cross())
                    {
                        while (assembleCube.cube[0][2][1].L_U_side == 'w')
                            assembleCube.turn_clockwise('U');

                        assembleCube.turn_clockwise('L');
                    }
                }
                else
                    assembleCube.turn_clockwise('L');
            }
        }
        if (assembleCube.cube[2][1][2].L_R_side == 'w')
        {
            if (assembleCube.cube[1][2][2].L_U_side == 'w')
            {
                while (assembleCube.cube[1][2][2].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_counterclockwise('F');
            }
            else
                assembleCube.turn_counterclockwise('F');
        }

        if (assembleCube.cube[2][1][0].L_R_side == 'w')
        {
            if (assembleCube.cube[1][2][0].L_U_side == 'w')
            {
                while (assembleCube.cube[1][2][0].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_clockwise('B');
            }
            else
                assembleCube.turn_clockwise('B');
        }

        if (assembleCube.cube[2][2][1].L_R_side == 'w')
        {
            assembleCube.turn_clockwise('R');
            if (assembleCube.cube[1][2][0].L_U_side == 'w')
            {
                while (assembleCube.cube[1][2][0].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_clockwise('B');
                if (assembleCube.cube[2][2][1].L_U_side == 'w')
                {
                    if (!check_nn_cross())
                    {
                        while (assembleCube.cube[2][2][1].L_U_side == 'w')
                            assembleCube.turn_clockwise('U');

                        assembleCube.turn_counterclockwise('R');
                    }


                }
                else
                    assembleCube.turn_counterclockwise('R');
            }
            else
            {
                assembleCube.turn_clockwise('B');
                if (assembleCube.cube[2][2][1].L_U_side == 'w')
                {
                    if (!check_nn_cross())
                    {
                        while (assembleCube.cube[2][2][1].L_U_side == 'w')
                            assembleCube.turn_clockwise('U');

                        assembleCube.turn_counterclockwise('R');
                    }


                }
                else
                    assembleCube.turn_counterclockwise('R');
            }
        }

        if (assembleCube.cube[2][0][1].L_R_side == 'w')
        {
            if (assembleCube.cube[2][2][1].L_U_side == 'w')
            {
                while (assembleCube.cube[2][2][1].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_counterclockwise('R');
            }
            else
                assembleCube.turn_counterclockwise('R');

            if (assembleCube.cube[1][2][0].L_U_side == 'w')
            {
                while (assembleCube.cube[1][2][0].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_clockwise('B');
                if (assembleCube.cube[2][2][1].L_U_side == 'w')
                {
                    if (!check_nn_cross())
                    {
                        while (assembleCube.cube[2][2][1].L_U_side == 'w')
                            assembleCube.turn_clockwise('U');

                        assembleCube.turn_clockwise('R');
                    }

                }
                else
                    assembleCube.turn_clockwise('R');
            }
            else
            {
                assembleCube.turn_clockwise('B');
                if (assembleCube.cube[2][2][1].L_U_side == 'w') {
                    if (!check_nn_cross()) {
                        while (assembleCube.cube[2][2][1].L_U_side == 'w') {
                            assembleCube.turn_clockwise('U');
                        }
                        assembleCube.turn_clockwise('R');
                    }

                } else {
                    assembleCube.turn_clockwise('R');
                }
            }
        }

        if (assembleCube.cube[0][1][0].L_B_side == 'w')
        {
            if (assembleCube.cube[0][2][1].L_U_side == 'w')
            {
                while (assembleCube.cube[0][2][1].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('L');
            }
            else
                assembleCube.turn_clockwise('L');
        }

        if (assembleCube.cube[2][1][0].L_B_side == 'w')
        {
            if (assembleCube.cube[2][2][1].L_U_side == 'w')
            {
                while (assembleCube.cube[2][2][1].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_counterclockwise('R');
            }
            else
                assembleCube.turn_counterclockwise('R');
        }

        if (assembleCube.cube[1][2][0].L_B_side == 'w')
        {
            assembleCube.turn_clockwise('B');
            if (assembleCube.cube[0][2][1].L_U_side == 'w')
            {
                while (assembleCube.cube[0][2][1].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_clockwise('L');
                if (assembleCube.cube[1][2][0].L_U_side == 'w')
                {
                    if (!check_nn_cross())
                    {
                        while (assembleCube.cube[1][2][0].L_U_side == 'w')
                            assembleCube.turn_clockwise('U');

                        assembleCube.turn_counterclockwise('B');
                    }


                } else {
                    assembleCube.turn_counterclockwise('B');
                }
            } else {
                assembleCube.turn_clockwise('L');
                if (assembleCube.cube[1][2][0].L_U_side == 'w') {
                    if (!check_nn_cross()) {
                        while (assembleCube.cube[1][2][0].L_U_side == 'w') {
                            assembleCube.turn_clockwise('U');
                        }
                        assembleCube.turn_counterclockwise('B');
                    }


                } else {
                    assembleCube.turn_counterclockwise('B');
                }
            }
        }

        if (assembleCube.cube[1][0][0].L_B_side == 'w')
        {
            if (assembleCube.cube[1][2][0].L_U_side == 'w')
            {
                while (assembleCube.cube[1][2][0].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_counterclockwise('B');
            } else
                assembleCube.turn_counterclockwise('B');

            if (assembleCube.cube[0][2][1].L_U_side == 'w')
            {
                while (assembleCube.cube[0][2][1].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_clockwise('L');
                if (assembleCube.cube[1][2][0].L_U_side == 'w')
                {
                    if (!check_nn_cross())
                    {
                        while (assembleCube.cube[1][2][0].L_U_side == 'w')
                            assembleCube.turn_clockwise('U');

                        assembleCube.turn_clockwise('B');
                    }

                }
                else
                    assembleCube.turn_clockwise('B');

            }
            else
            {
                assembleCube.turn_clockwise('L');
                if (assembleCube.cube[1][2][0].L_U_side == 'w')
                {
                    if (!check_nn_cross())
                    {
                        while (assembleCube.cube[1][2][0].L_U_side == 'w')
                            assembleCube.turn_clockwise('U');

                        assembleCube.turn_clockwise('B');
                    }

                }
                else
                    assembleCube.turn_clockwise('B');
            }
        }

        if (assembleCube.cube[0][0][1].L_D_side == 'w')
        {
            if (assembleCube.cube[0][2][1].L_U_side == 'w')
            {
                while (assembleCube.cube[0][2][1].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('L');
            }
            else
            {
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('L');
            }
        }

        if (assembleCube.cube[2][0][1].L_D_side == 'w')
        {
            if (assembleCube.cube[2][2][1].L_U_side == 'w')
            {
                while (assembleCube.cube[2][2][1].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('R');
            }
            else
            {
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('R');
            }
        }

        if (assembleCube.cube[1][0][2].L_D_side == 'w')
        {
            assembleCube.turn_clockwise('D');
            if (assembleCube.cube[2][2][1].L_U_side == 'w')
            {
                while (assembleCube.cube[2][2][1].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_counterclockwise('D');
            }
            else
            {
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_counterclockwise('D');
            }
        }

        if (assembleCube.cube[1][0][0].L_D_side == 'w')
        {
            assembleCube.turn_counterclockwise('D');
            if (assembleCube.cube[2][2][1].L_U_side == 'w')
            {
                while (assembleCube.cube[2][2][1].L_U_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('D');
            }
            else
            {
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('D');
            }
        }
    }

    //Assembling Correct cross
    if (check_nn_cross())
    {
        while ((assembleCube.cube[1][1][0].L_B_side != assembleCube.cube[1][2][0].L_B_side) || assembleCube.cube[1][2][0].L_U_side != 'w')
            assembleCube.turn_clockwise('U');

        assembleCube.turn_clockwise('B');
        assembleCube.turn_clockwise('B');

        while ((assembleCube.cube[2][1][1].L_R_side != assembleCube.cube[2][2][1].L_R_side) || assembleCube.cube[2][2][1].L_U_side != 'w')
            assembleCube.turn_clockwise('U');

        assembleCube.turn_clockwise('R');
        assembleCube.turn_clockwise('R');

        while ((assembleCube.cube[1][1][2].L_F_side != assembleCube.cube[1][2][2].L_F_side) || assembleCube.cube[1][2][2].L_U_side != 'w')
            assembleCube.turn_clockwise('U');

        assembleCube.turn_clockwise('F');
        assembleCube.turn_clockwise('F');

        while ((assembleCube.cube[0][1][1].L_L_side != assembleCube.cube[0][2][1].L_L_side) || assembleCube.cube[0][2][1].L_U_side != 'w')
            assembleCube.turn_clockwise('U');

        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('L');
    }
}

void AssemblingRubiksCube::pif_paf_up(char side)
{

    //0 2 2
    if (side == '7')
        while (assembleCube.cube[0][2][2].L_U_side != 'w')
        {
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
        }
    else if (side == '5')
        //2 2 2
        while (assembleCube.cube[2][2][2].L_U_side != 'w')
        {
            assembleCube.turn_clockwise('R');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('R');
            assembleCube.turn_counterclockwise('U');
        }
    else if (side == '3')
        //2 2 0
        while (assembleCube.cube[2][2][0].L_U_side != 'w')
        {
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
        }
    else if (side == '1')
        //0 2 0
        while (assembleCube.cube[0][2][0].L_U_side != 'w')
        {
            assembleCube.turn_clockwise('L');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('L');
            assembleCube.turn_counterclockwise('U');
        }

}

bool AssemblingRubiksCube::check_neighboring_side(char side)
{
    if (side == '7')
    {
        if (((assembleCube.cube[0][2][2].L_L_side == assembleCube.cube[0][1][1].L_L_side) &&
             (assembleCube.cube[0][2][2].L_F_side == assembleCube.cube[1][1][2].L_F_side)) ||
            ((assembleCube.cube[0][2][2].L_L_side == assembleCube.cube[1][1][2].L_F_side) &&
             (assembleCube.cube[0][2][2].L_F_side == assembleCube.cube[0][1][1].L_L_side)))
            return true;
    }
    else if (side == '5')
    {
        if (((assembleCube.cube[2][2][2].L_F_side == assembleCube.cube[1][1][2].L_F_side) &&
             (assembleCube.cube[2][2][2].L_R_side == assembleCube.cube[2][1][1].L_R_side)) ||
            ((assembleCube.cube[2][2][2].L_F_side == assembleCube.cube[2][1][1].L_R_side) &&
             (assembleCube.cube[2][2][2].L_R_side == assembleCube.cube[1][1][2].L_F_side)))
            return true;
    }
    else if (side == '3')
    {
        if (((assembleCube.cube[2][2][0].L_R_side == assembleCube.cube[2][1][1].L_R_side) &&
             (assembleCube.cube[2][2][0].L_B_side == assembleCube.cube[1][1][0].L_B_side)) ||
            ((assembleCube.cube[2][2][0].L_R_side == assembleCube.cube[1][1][0].L_B_side) &&
             (assembleCube.cube[2][2][0].L_B_side == assembleCube.cube[2][1][1].L_R_side)))
            return true;
    }
    else if (side == '1')
    {
        if (((assembleCube.cube[0][2][0].L_B_side == assembleCube.cube[1][1][0].L_B_side) &&
             (assembleCube.cube[0][2][0].L_L_side == assembleCube.cube[0][1][1].L_L_side)) ||
            ((assembleCube.cube[0][2][0].L_B_side == assembleCube.cube[0][1][1].L_L_side) &&
             (assembleCube.cube[0][2][0].L_L_side == assembleCube.cube[1][1][0].L_B_side)))
            return true;
    }
    return false;
}

bool AssemblingRubiksCube::check_up_white() {

    if (assembleCube.cube[0][2][2].L_U_side != 'w' && assembleCube.cube[0][2][2].L_L_side != 'w' &&
        assembleCube.cube[0][2][2].L_F_side != 'w')
        return false;

    if (assembleCube.cube[2][2][2].L_U_side != 'w' && assembleCube.cube[2][2][2].L_R_side != 'w' &&
        assembleCube.cube[2][2][2].L_F_side != 'w')
        return false;

    if (assembleCube.cube[2][2][0].L_U_side != 'w' && assembleCube.cube[2][2][0].L_B_side != 'w' &&
        assembleCube.cube[2][2][0].L_R_side != 'w')
        return false;

    if (assembleCube.cube[0][2][0].L_U_side != 'w' && assembleCube.cube[0][2][0].L_B_side != 'w' &&
        assembleCube.cube[0][2][0].L_L_side != 'w')
        return false;

    return true;
}

void AssemblingRubiksCube::assembling_white_side()
{

    //replacing white 0 0 2
    if (!check_up_white())
    {
        while (assembleCube.cube[0][2][2].L_U_side == 'w' || assembleCube.cube[0][2][2].L_L_side == 'w' ||
               assembleCube.cube[0][2][2].L_F_side == 'w')
            assembleCube.turn_clockwise('U');

        assembleCube.turn_clockwise('F');
        while (assembleCube.cube[0][2][2].L_U_side == 'w' || assembleCube.cube[0][2][2].L_L_side == 'w' ||
               assembleCube.cube[0][2][2].L_F_side == 'w')
            assembleCube.turn_clockwise('U');

        assembleCube.turn_counterclockwise('F');

        if (!check_up_white())
        {
            //2 0 2
            while (assembleCube.cube[2][2][2].L_U_side == 'w' || assembleCube.cube[2][2][2].L_R_side == 'w' ||
                   assembleCube.cube[2][2][2].L_F_side == 'w')
                assembleCube.turn_clockwise('U');

            assembleCube.turn_clockwise('R');
            while (assembleCube.cube[2][2][2].L_U_side == 'w' || assembleCube.cube[2][2][2].L_R_side == 'w' ||
                   assembleCube.cube[2][2][2].L_F_side == 'w')
                assembleCube.turn_clockwise('U');

            assembleCube.turn_counterclockwise('R');
            if (!check_up_white())
            {
                //2 0 0
                while (assembleCube.cube[2][2][0].L_U_side == 'w' || assembleCube.cube[2][2][0].L_B_side == 'w' ||
                       assembleCube.cube[2][2][0].L_R_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_clockwise('B');
                while (assembleCube.cube[2][2][0].L_U_side == 'w' || assembleCube.cube[2][2][0].L_B_side == 'w' ||
                       assembleCube.cube[2][2][0].L_R_side == 'w')
                    assembleCube.turn_clockwise('U');

                assembleCube.turn_counterclockwise('B');
                if (!check_up_white())
                {
                    //0 0 0
                    while (assembleCube.cube[0][2][0].L_U_side == 'w' || assembleCube.cube[0][2][0].L_B_side == 'w' ||
                           assembleCube.cube[0][2][0].L_L_side == 'w')
                        assembleCube.turn_clockwise('U');

                    assembleCube.turn_clockwise('L');
                    while (assembleCube.cube[0][2][0].L_U_side == 'w' || assembleCube.cube[0][2][0].L_B_side == 'w' ||
                           assembleCube.cube[0][2][0].L_L_side == 'w')
                        assembleCube.turn_clockwise('U');

                    assembleCube.turn_counterclockwise('L');
                }

            }

        }


    }
    //preparing corners for turn

    //0 0 2
    if (assembleCube.cube[0][2][2].L_U_side == 'w' || assembleCube.cube[0][2][2].L_L_side == 'w' ||
        assembleCube.cube[0][2][2].L_F_side == 'w')
        pif_paf_up('7');
    else
    {
        while (assembleCube.cube[0][2][2].L_U_side != 'w' && assembleCube.cube[0][2][2].L_L_side != 'w' &&
               assembleCube.cube[0][2][2].L_F_side != 'w')
            assembleCube.turn_clockwise('U');

        pif_paf_up('7');
    }

    while (!check_neighboring_side('7'))
    {
        assembleCube.turn_clockwise('U');
        if (assembleCube.cube[0][2][2].L_U_side == 'w' || assembleCube.cube[0][2][2].L_L_side == 'w' ||
            assembleCube.cube[0][2][2].L_F_side == 'w')
            pif_paf_up('7');
        else
        {
            while (assembleCube.cube[0][2][2].L_U_side != 'w' && assembleCube.cube[0][2][2].L_L_side != 'w' &&
                   assembleCube.cube[0][2][2].L_F_side != 'w')
                assembleCube.turn_clockwise('U');
            pif_paf_up('7');
        }
    }
    while (assembleCube.cube[0][0][2].L_D_side != 'w')
    {
        assembleCube.turn_clockwise('F');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('F');
        assembleCube.turn_counterclockwise('U');
    }
    //2 0 2
    if (assembleCube.cube[2][2][2].L_U_side == 'w' || assembleCube.cube[2][2][2].L_R_side == 'w' ||
        assembleCube.cube[2][2][2].L_F_side == 'w')
        pif_paf_up('5');
    else
    {
        while (assembleCube.cube[2][2][2].L_U_side != 'w' && assembleCube.cube[2][2][2].L_R_side != 'w' &&
               assembleCube.cube[2][2][2].L_F_side != 'w')
            assembleCube.turn_clockwise('U');
        pif_paf_up('5');
    }

    while (!check_neighboring_side('5'))
    {
        assembleCube.turn_clockwise('U');
        if (assembleCube.cube[2][2][2].L_U_side == 'w' || assembleCube.cube[2][2][2].L_R_side == 'w' ||
            assembleCube.cube[2][2][2].L_F_side == 'w')
            pif_paf_up('5');
        else
        {
            while (assembleCube.cube[2][2][2].L_U_side != 'w' && assembleCube.cube[2][2][2].L_R_side != 'w' &&
                   assembleCube.cube[2][2][2].L_F_side != 'w')
                assembleCube.turn_clockwise('U');
            pif_paf_up('5');
        }
    }
    while (assembleCube.cube[2][0][2].L_D_side != 'w')
    {
        assembleCube.turn_clockwise('R');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('R');
        assembleCube.turn_counterclockwise('U');
    }

    //2 0 0
    if (assembleCube.cube[2][2][0].L_U_side == 'w' || assembleCube.cube[2][2][0].L_B_side == 'w' ||
        assembleCube.cube[2][2][0].L_R_side == 'w')
        pif_paf_up('3');
    else
    {
        while (assembleCube.cube[2][2][0].L_U_side != 'w' && assembleCube.cube[2][2][0].L_R_side != 'w' &&
               assembleCube.cube[2][2][0].L_B_side != 'w')
            assembleCube.turn_clockwise('U');
        pif_paf_up('3');
    }

    while (!check_neighboring_side('3'))
    {
        assembleCube.turn_clockwise('U');
        if (assembleCube.cube[2][2][0].L_U_side == 'w' || assembleCube.cube[2][2][0].L_B_side == 'w' ||
            assembleCube.cube[2][2][0].L_R_side == 'w')
            pif_paf_up('3');
        else
        {
            while (assembleCube.cube[2][2][0].L_U_side != 'w' && assembleCube.cube[2][2][0].L_R_side != 'w' &&
                   assembleCube.cube[2][2][0].L_B_side != 'w')
                assembleCube.turn_clockwise('U');
            pif_paf_up('3');
        }
    }
    while (assembleCube.cube[2][0][0].L_D_side != 'w')
    {
        assembleCube.turn_clockwise('B');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('B');
        assembleCube.turn_counterclockwise('U');
    }

    //0 0 0
    if (assembleCube.cube[0][2][0].L_U_side == 'w' || assembleCube.cube[0][2][0].L_B_side == 'w' ||
        assembleCube.cube[0][2][0].L_L_side == 'w')
        pif_paf_up('1');
    else
    {
        while (assembleCube.cube[0][2][0].L_U_side != 'w' && assembleCube.cube[0][2][0].L_L_side != 'w' &&
               assembleCube.cube[0][2][0].L_B_side != 'w')
            assembleCube.turn_clockwise('U');
        pif_paf_up('1');
    }

    while (!check_neighboring_side('1'))
    {
        assembleCube.turn_clockwise('U');
        if (assembleCube.cube[0][2][0].L_U_side == 'w' || assembleCube.cube[0][2][0].L_B_side == 'w' ||
            assembleCube.cube[0][2][0].L_L_side == 'w')
            pif_paf_up('1');
        else
        {
            while (assembleCube.cube[0][2][0].L_U_side != 'w' && assembleCube.cube[0][2][0].L_L_side != 'w' &&
                   assembleCube.cube[0][2][0].L_B_side != 'w')
                assembleCube.turn_clockwise('U');
            pif_paf_up('1');
        }
    }
    while (assembleCube.cube[0][0][0].L_D_side != 'w')
    {
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('U');
    }
}

void AssemblingRubiksCube::side_selection(char side)
{
    if (side == 'B')
    {
        //finding blue edge
        int score_blue = 0;
        for (int i = 0; i < 4; i++)
        {
            if (assembleCube.cube[1][1][2].L_F_side == assembleCube.cube[1][2][2].L_F_side)
                score_blue++;
            assembleCube.turn_clockwise('U');
        }

        if (score_blue == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                if (assembleCube.cube[1][1][2].L_F_side == assembleCube.cube[1][2][2].L_F_side)
                    break;
                assembleCube.turn_clockwise('U');
            }
            if (assembleCube.cube[1][2][2].L_U_side == 'o')
            {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('L');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('F');
                assembleCube.turn_counterclockwise('U');

            }
            else if (assembleCube.cube[1][2][2].L_U_side == 'r')
            {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('F');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('U');
            }
        }
        else if (score_blue == 2)
        {
            for (int i = 0; i < 4; i++)
            {
                if (assembleCube.cube[1][1][2].L_F_side == assembleCube.cube[1][2][2].L_F_side)
                    break;
                assembleCube.turn_clockwise('U');
            }
            if (assembleCube.cube[1][2][2].L_U_side == 'o')
            {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('L');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('F');
                assembleCube.turn_counterclockwise('U');

            }
            else if (assembleCube.cube[1][2][2].L_U_side == 'r')
            {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('F');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('U');
            }
            for (int i = 0; i < 4; i++)
            {
                if (assembleCube.cube[1][1][2].L_F_side == assembleCube.cube[1][2][2].L_F_side)
                    break;
                assembleCube.turn_clockwise('U');
            }
            if (assembleCube.cube[1][2][2].L_U_side == 'o')
            {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('L');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('F');
                assembleCube.turn_counterclockwise('U');

            }
            else if (assembleCube.cube[1][2][2].L_U_side == 'r')
            {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('F');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('U');
            }
        }
    }
    else if (side == 'O')
    {
        //finding orange edge
        int score_orange = 0;
        for (int i = 0; i < 4; i++)
        {
            if (assembleCube.cube[0][1][1].L_L_side == assembleCube.cube[0][2][1].L_L_side)
                score_orange++;
            assembleCube.turn_clockwise('U');
        }

        if (score_orange == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                if (assembleCube.cube[0][1][1].L_L_side == assembleCube.cube[0][2][1].L_L_side)
                    break;
                assembleCube.turn_clockwise('U');
            }
            if (assembleCube.cube[0][2][1].L_U_side == 'g') {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('B');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('B');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('L');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('U');


            }
            else if (assembleCube.cube[0][2][1].L_U_side == 'b')
            {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('F');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('L');
                assembleCube.turn_clockwise('U');
            }
        }
        else if (score_orange == 2)
        {
            for (int i = 0; i < 4; i++)
            {
                if (assembleCube.cube[0][1][1].L_L_side == assembleCube.cube[0][2][1].L_L_side)
                    break;
                assembleCube.turn_clockwise('U');
            }
            if (assembleCube.cube[0][2][1].L_U_side == 'g') {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('B');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('B');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('L');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('U');


            }
            else if (assembleCube.cube[0][2][1].L_U_side == 'b')
            {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('F');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('L');
                assembleCube.turn_clockwise('U');
            }
            for (int i = 0; i < 4; i++)
            {
                if (assembleCube.cube[0][1][1].L_L_side == assembleCube.cube[0][2][1].L_L_side)
                    break;
                assembleCube.turn_clockwise('U');
            }
            if (assembleCube.cube[0][2][1].L_U_side == 'g') {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('B');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('B');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('L');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('U');


            } else if (assembleCube.cube[0][2][1].L_U_side == 'b') {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('F');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('L');
                assembleCube.turn_clockwise('U');
            }

        }
    }
    else if (side == 'R')
    {
        //finding red edge
        int score_red = 0;
        for (int i = 0; i < 4; i++)
        {
            if (assembleCube.cube[2][1][1].L_R_side == assembleCube.cube[2][2][1].L_R_side)
                score_red++;
            assembleCube.turn_clockwise('U');
        }
        if (score_red == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                if (assembleCube.cube[2][1][1].L_R_side == assembleCube.cube[2][2][1].L_R_side)
                    break;
                assembleCube.turn_clockwise('U');
            }
            if (assembleCube.cube[2][2][1].L_U_side == 'g')
            {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('B');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('B');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');


            }
            else if (assembleCube.cube[2][2][1].L_U_side == 'b')
            {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('F');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
            }
        }
        else if (score_red == 2)
        {
            for (int i = 0; i < 4; i++)
            {
                if (assembleCube.cube[2][1][1].L_R_side == assembleCube.cube[2][2][1].L_R_side)
                    break;
                assembleCube.turn_clockwise('U');
            }
            if (assembleCube.cube[2][2][1].L_U_side == 'g') {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('B');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('B');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');


            }
            else if (assembleCube.cube[2][2][1].L_U_side == 'b')
            {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('F');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
            }
            for (int i = 0; i < 4; i++) {
                if (assembleCube.cube[2][1][1].L_R_side == assembleCube.cube[2][2][1].L_R_side)
                    break;
                assembleCube.turn_clockwise('U');
            }
            if (assembleCube.cube[2][2][1].L_U_side == 'g') {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('B');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('B');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');


            }
            else if (assembleCube.cube[2][2][1].L_U_side == 'b')
            {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('F');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
            }
        }

    }
    else if (side == 'G')
    {
        //finding green edge
        int score_green = 0;
        for (int i = 0; i < 4; i++)
        {
            if (assembleCube.cube[1][1][0].L_B_side == assembleCube.cube[1][2][0].L_B_side)
                score_green++;
            assembleCube.turn_clockwise('U');
        }
        if (score_green == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                if (assembleCube.cube[1][1][0].L_B_side == assembleCube.cube[1][2][0].L_B_side)
                    break;
                assembleCube.turn_clockwise('U');
            }
            if (assembleCube.cube[1][2][0].L_U_side == 'r')
            {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('B');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('B');
                assembleCube.turn_counterclockwise('U');

            }
            else if (assembleCube.cube[1][2][0].L_U_side == 'o')
            {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('L');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('B');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('B');
                assembleCube.turn_clockwise('U');
            }
        }
        else if (score_green == 2)
        {
            for (int i = 0; i < 4; i++)
            {
                if (assembleCube.cube[1][1][0].L_B_side == assembleCube.cube[1][2][0].L_B_side)
                    break;
                assembleCube.turn_clockwise('U');
            }
            if (assembleCube.cube[1][2][0].L_U_side == 'r')
            {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('B');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('B');
                assembleCube.turn_counterclockwise('U');

            }
            else if (assembleCube.cube[1][2][0].L_U_side == 'o')
            {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('L');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('B');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('B');
                assembleCube.turn_clockwise('U');
            }
            for (int i = 0; i < 4; i++)
            {
                if (assembleCube.cube[1][1][0].L_B_side == assembleCube.cube[1][2][0].L_B_side)
                    break;
                assembleCube.turn_clockwise('U');
            }
            if (assembleCube.cube[1][2][0].L_U_side == 'r')
            {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('B');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('B');
                assembleCube.turn_counterclockwise('U');

            }
            else if (assembleCube.cube[1][2][0].L_U_side == 'o')
            {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('L');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('L');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('B');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('B');
                assembleCube.turn_clockwise('U');
            }
        }
    }
}

void AssemblingRubiksCube::second_layer()
{
    for (int i = 0; i < 4; i++)
    {
        side_selection('B');
        side_selection('O');
        side_selection('R');
        side_selection('G');
    }
    for (int k = 0; k < 4; k++)
    {
        //check the wrong positions
        if (!((assembleCube.cube[0][1][2].L_F_side == assembleCube.cube[1][1][2].L_F_side) &&
              (assembleCube.cube[0][1][2].L_L_side == assembleCube.cube[0][1][1].L_L_side)))
        {
            assembleCube.turn_counterclockwise('L');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('L');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
            for (int i = 0; i < 4; i++)
            {
                side_selection('B');
                side_selection('O');
                side_selection('R');
                side_selection('G');
            }
        }
        if (!((assembleCube.cube[2][1][2].L_F_side == assembleCube.cube[1][1][2].L_F_side) &&
              (assembleCube.cube[2][1][2].L_R_side == assembleCube.cube[2][1][1].L_R_side)))
        {
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_clockwise('R');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('R');
            assembleCube.turn_counterclockwise('U');
            for (int i = 0; i < 4; i++)
            {
                side_selection('B');
                side_selection('O');
                side_selection('R');
                side_selection('G');
            }
        }
        if (!((assembleCube.cube[2][1][0].L_B_side == assembleCube.cube[1][1][0].L_B_side) &&
              (assembleCube.cube[2][1][0].L_R_side == assembleCube.cube[2][1][1].L_R_side)))
        {
            assembleCube.turn_counterclockwise('R');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('R');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            for (int i = 0; i < 4; i++)
            {
                side_selection('B');
                side_selection('O');
                side_selection('R');
                side_selection('G');
            }

        }
        if (!((assembleCube.cube[0][1][0].L_B_side == assembleCube.cube[1][1][0].L_B_side) &&
              (assembleCube.cube[0][1][0].L_L_side == assembleCube.cube[0][1][1].L_L_side)))
        {
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_clockwise('L');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('L');
            assembleCube.turn_counterclockwise('U');
            for (int i = 0; i < 4; i++)
            {
                side_selection('B');
                side_selection('O');
                side_selection('R');
                side_selection('G');
            }
        }
    }
}

bool AssemblingRubiksCube::check_yellow_cross()
{
    if (assembleCube.cube[1][2][0].L_U_side != 'y')
        return false;
    if (assembleCube.cube[2][2][1].L_U_side != 'y')
        return false;
    if (assembleCube.cube[1][2][2].L_U_side != 'y')
        return false;
    if (assembleCube.cube[0][2][1].L_U_side != 'y')
        return false;

    return true;
}

void AssemblingRubiksCube::assembling_yellow_cross()
{
    //check cross
    if (!check_yellow_cross())
    {
        if (assembleCube.cube[1][2][0].L_U_side == 'y' && assembleCube.cube[1][2][2].L_U_side == 'y')
        {
            assembleCube.turn_clockwise('R');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_counterclockwise('R');
        }
        else if (assembleCube.cube[0][2][1].L_U_side == 'y' && assembleCube.cube[2][2][1].L_U_side == 'y')
        {
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('R');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('R');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_counterclockwise('F');
        }
        if (!check_yellow_cross())
        {
            if (assembleCube.cube[1][2][0].L_U_side == 'y' && assembleCube.cube[0][2][1].L_U_side == 'y')
            {
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('F');
            }
            else if (assembleCube.cube[1][2][0].L_U_side == 'y' && assembleCube.cube[2][2][1].L_U_side == 'y')
            {
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('F');
            }
            else if (assembleCube.cube[2][2][1].L_U_side == 'y' && assembleCube.cube[1][2][2].L_U_side == 'y')
            {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('F');
            }
            else if (assembleCube.cube[1][2][2].L_U_side == 'y' && assembleCube.cube[0][2][1].L_U_side == 'y')
            {
                assembleCube.turn_clockwise('U');
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('F');
            }
            if (!(check_yellow_cross()))
            {
                assembleCube.turn_clockwise('F');
                assembleCube.turn_clockwise('R');
                assembleCube.turn_clockwise('U');
                assembleCube.turn_counterclockwise('R');
                assembleCube.turn_counterclockwise('U');
                assembleCube.turn_counterclockwise('F');

                if (assembleCube.cube[1][2][0].L_U_side == 'y' && assembleCube.cube[0][2][1].L_U_side == 'y')
                {
                    assembleCube.turn_clockwise('F');
                    assembleCube.turn_clockwise('R');
                    assembleCube.turn_clockwise('U');
                    assembleCube.turn_counterclockwise('R');
                    assembleCube.turn_counterclockwise('U');
                    assembleCube.turn_clockwise('R');
                    assembleCube.turn_clockwise('U');
                    assembleCube.turn_counterclockwise('R');
                    assembleCube.turn_counterclockwise('U');
                    assembleCube.turn_counterclockwise('F');
                }
                else if (assembleCube.cube[1][2][0].L_U_side == 'y' && assembleCube.cube[2][2][1].L_U_side == 'y')
                {
                    assembleCube.turn_counterclockwise('U');
                    assembleCube.turn_clockwise('F');
                    assembleCube.turn_clockwise('R');
                    assembleCube.turn_clockwise('U');
                    assembleCube.turn_counterclockwise('R');
                    assembleCube.turn_counterclockwise('U');
                    assembleCube.turn_clockwise('R');
                    assembleCube.turn_clockwise('U');
                    assembleCube.turn_counterclockwise('R');
                    assembleCube.turn_counterclockwise('U');
                    assembleCube.turn_counterclockwise('F');
                }
                else if (assembleCube.cube[2][2][1].L_U_side == 'y' && assembleCube.cube[1][2][2].L_U_side == 'y')
                {
                    assembleCube.turn_clockwise('U');
                    assembleCube.turn_clockwise('U');
                    assembleCube.turn_clockwise('F');
                    assembleCube.turn_clockwise('R');
                    assembleCube.turn_clockwise('U');
                    assembleCube.turn_counterclockwise('R');
                    assembleCube.turn_counterclockwise('U');
                    assembleCube.turn_clockwise('R');
                    assembleCube.turn_clockwise('U');
                    assembleCube.turn_counterclockwise('R');
                    assembleCube.turn_counterclockwise('U');
                    assembleCube.turn_counterclockwise('F');
                }
                else if (assembleCube.cube[1][2][2].L_U_side == 'y' && assembleCube.cube[0][2][1].L_U_side == 'y')
                {
                    assembleCube.turn_clockwise('U');
                    assembleCube.turn_clockwise('F');
                    assembleCube.turn_clockwise('R');
                    assembleCube.turn_clockwise('U');
                    assembleCube.turn_counterclockwise('R');
                    assembleCube.turn_counterclockwise('U');
                    assembleCube.turn_clockwise('R');
                    assembleCube.turn_clockwise('U');
                    assembleCube.turn_counterclockwise('R');
                    assembleCube.turn_counterclockwise('U');
                    assembleCube.turn_counterclockwise('F');
                }
            }
        }
    }

}

void AssemblingRubiksCube::assembling_true_angle()
{
    while (!((assembleCube.cube[2][2][2].L_U_side == 'y' ||
              assembleCube.cube[2][2][2].L_U_side == 'b' ||
              assembleCube.cube[2][2][2].L_U_side == 'r') &&
             (assembleCube.cube[2][2][2].L_F_side == 'y' ||
              assembleCube.cube[2][2][2].L_F_side == 'b' ||
              assembleCube.cube[2][2][2].L_F_side == 'r') &&
             (assembleCube.cube[2][2][2].L_R_side == 'y' ||
              assembleCube.cube[2][2][2].L_R_side == 'b' ||
              assembleCube.cube[2][2][2].L_R_side == 'r')))
        assembleCube.turn_clockwise('U');

    while (!((assembleCube.cube[2][2][0].L_U_side == 'y' ||
              assembleCube.cube[2][2][0].L_U_side == 'g' ||
              assembleCube.cube[2][2][0].L_U_side == 'r') &&
             (assembleCube.cube[2][2][0].L_B_side == 'y' ||
              assembleCube.cube[2][2][0].L_B_side == 'g' ||
              assembleCube.cube[2][2][0].L_B_side == 'r') &&
             (assembleCube.cube[2][2][0].L_R_side == 'y' ||
              assembleCube.cube[2][2][0].L_R_side == 'g' ||
              assembleCube.cube[2][2][0].L_R_side == 'r')))
    {
        assembleCube.turn_clockwise('R');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('R');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('R');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('R');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('R');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('R');
        assembleCube.turn_counterclockwise('U');

        assembleCube.turn_counterclockwise('F');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('F');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('F');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('F');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('F');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('F');
        assembleCube.turn_clockwise('U');
    }

    while (!((assembleCube.cube[0][2][0].L_U_side == 'y' ||
              assembleCube.cube[0][2][0].L_U_side == 'g' ||
              assembleCube.cube[0][2][0].L_U_side == 'o') &&
             (assembleCube.cube[0][2][0].L_B_side == 'y' ||
              assembleCube.cube[0][2][0].L_B_side == 'g' ||
              assembleCube.cube[0][2][0].L_B_side == 'o') &&
             (assembleCube.cube[0][2][0].L_L_side == 'y' ||
              assembleCube.cube[0][2][0].L_L_side == 'g' ||
              assembleCube.cube[0][2][0].L_L_side == 'o')))
    {
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('U');

        assembleCube.turn_counterclockwise('B');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('B');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('B');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('B');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('B');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('B');
        assembleCube.turn_clockwise('U');
        while (!((assembleCube.cube[2][2][2].L_U_side == 'y' ||
                  assembleCube.cube[2][2][2].L_U_side == 'b' ||
                  assembleCube.cube[2][2][2].L_U_side == 'r') &&
                 (assembleCube.cube[2][2][2].L_F_side == 'y' ||
                  assembleCube.cube[2][2][2].L_F_side == 'b' ||
                  assembleCube.cube[2][2][2].L_F_side == 'r') &&
                 (assembleCube.cube[2][2][2].L_R_side == 'y' ||
                  assembleCube.cube[2][2][2].L_R_side == 'b' ||
                  assembleCube.cube[2][2][2].L_R_side == 'r')))
            assembleCube.turn_clockwise('U');
    }
    while (!((assembleCube.cube[2][2][2].L_U_side == 'y' ||
              assembleCube.cube[2][2][2].L_U_side == 'b' ||
              assembleCube.cube[2][2][2].L_U_side == 'r') &&
             (assembleCube.cube[2][2][2].L_F_side == 'y' ||
              assembleCube.cube[2][2][2].L_F_side == 'b' ||
              assembleCube.cube[2][2][2].L_F_side == 'r') &&
             (assembleCube.cube[2][2][2].L_R_side == 'y' ||
              assembleCube.cube[2][2][2].L_R_side == 'b' ||
              assembleCube.cube[2][2][2].L_R_side == 'r')))
        assembleCube.turn_clockwise('U');
}

void AssemblingRubiksCube::turning_corners()
{
    while (assembleCube.cube[0][2][2].L_U_side != 'y')
    {
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('D');
        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('D');
    }
    assembleCube.turn_counterclockwise('U');
    while (assembleCube.cube[0][2][2].L_U_side != 'y')
    {
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('D');
        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('D');
    }
    assembleCube.turn_counterclockwise('U');
    while (assembleCube.cube[0][2][2].L_U_side != 'y')
    {
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('D');
        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('D');
    }
    assembleCube.turn_counterclockwise('U');
    while (assembleCube.cube[0][2][2].L_U_side != 'y')
    {
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('D');
        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('D');
    }
}

void AssemblingRubiksCube::final()
{
    while (!((assembleCube.cube[2][2][2].L_U_side == 'y' ||
              assembleCube.cube[2][2][2].L_U_side == 'b' ||
              assembleCube.cube[2][2][2].L_U_side == 'r') &&
             (assembleCube.cube[2][2][2].L_F_side == 'y' ||
              assembleCube.cube[2][2][2].L_F_side == 'b' ||
              assembleCube.cube[2][2][2].L_F_side == 'r') &&
             (assembleCube.cube[2][2][2].L_R_side == 'y' ||
              assembleCube.cube[2][2][2].L_R_side == 'b' ||
              assembleCube.cube[2][2][2].L_R_side == 'r')))
        assembleCube.turn_clockwise('U');
    bool green = false;
    bool red = false;
    bool orange = false;
    while (true)
    {
        if (assembleCube.cube[0][2][1].L_L_side == assembleCube.cube[0][2][0].L_L_side)
        {
            orange = true;
            break;
        }
        else if (assembleCube.cube[2][2][0].L_R_side == assembleCube.cube[2][2][1].L_R_side)
        {
            red = true;
            break;
        }
        else if (assembleCube.cube[0][2][0].L_B_side == assembleCube.cube[1][2][0].L_B_side)
        {
            green = true;
            break;
        }
        assembleCube.turn_clockwise('R');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('R');
        assembleCube.turn_counterclockwise('U');

        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('U');

        assembleCube.turn_clockwise('R');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('R');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('R');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('R');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('R');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('R');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('R');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('R');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('R');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('R');
        assembleCube.turn_counterclockwise('U');

        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('U');
        assembleCube.turn_counterclockwise('L');
        assembleCube.turn_counterclockwise('U');
        assembleCube.turn_clockwise('L');
        assembleCube.turn_clockwise('U');

    }

    if (red)
    {
        while (assembleCube.cube[0][2][2].L_F_side != assembleCube.cube[1][2][2].L_F_side)
        {
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');

            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');

            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');

            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
        }

    }
    else if (green)
    {
        while (assembleCube.cube[0][2][2].L_F_side != assembleCube.cube[1][2][2].L_F_side)
        {
            assembleCube.turn_clockwise('L');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('L');
            assembleCube.turn_counterclockwise('U');

            assembleCube.turn_counterclockwise('R');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('R');
            assembleCube.turn_clockwise('U');

            assembleCube.turn_clockwise('L');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('L');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('L');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('L');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('L');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('L');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('L');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('L');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('L');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('L');
            assembleCube.turn_counterclockwise('U');

            assembleCube.turn_counterclockwise('R');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('R');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('R');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('R');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('R');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('R');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('R');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('R');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('R');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('R');
            assembleCube.turn_clockwise('U');
        }
    }
    else if (orange)
    {
        while (assembleCube.cube[0][2][2].L_F_side != assembleCube.cube[1][2][2].L_F_side)
        {
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');

            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');

            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('F');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('F');
            assembleCube.turn_counterclockwise('U');

            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
            assembleCube.turn_counterclockwise('B');
            assembleCube.turn_counterclockwise('U');
            assembleCube.turn_clockwise('B');
            assembleCube.turn_clockwise('U');
        }
    }
}

CRubicsCube AssemblingRubiksCube::assemble()
{
    assembling_cross();
    assembling_white_side();
    second_layer();
    assembling_yellow_cross();
    assembling_true_angle();
    turning_corners();
    final();
    return assembleCube;
}

bool AssemblingRubiksCube::invariance(CRubicsCube one)
{
    AssemblingRubiksCube check(one);
    if (one.cube[1][1][2].L_F_side != 'b')
        return false;
    else if (one.cube[2][1][1].L_R_side != 'r')
        return false;
    else if (one.cube[1][1][0].L_B_side != 'g')
        return false;
    else if (one.cube[0][1][1].L_L_side != 'o')
        return false;
    else if (one.cube[1][2][1].L_U_side != 'y')
        return false;
    else if (one.cube[1][0][1].L_D_side != 'w')
        return false;
    one = check.assemble();
    int position = 0;
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            if (one.cube[x][y][2].L_F_side == 'b')
                position++;

    for (int y = 0; y < 3; y++)
        for (int z = 0; z < 3; z++)
            if (one.cube[2][y][z].L_R_side == 'r')
                position++;

    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            if (one.cube[x][y][0].L_B_side == 'g')
                position++;

    for (int y = 0; y < 3; y++)
        for (int z = 0; z < 3; z++)
            if (one.cube[0][y][z].L_L_side == 'o')
                position++;

    for (int x = 0; x < 3; x++)
        for (int z = 0; z < 3; z++)
            if (one.cube[x][2][z].L_U_side == 'y')
                position++;

    for (int x = 0; x < 3; x++)
        for (int z = 0; z < 3; z++)
            if (one.cube[x][0][z].L_D_side == 'w')
                position++;

    if (position == 54)
        return true;
    else
        return false;
}