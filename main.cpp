#include <iostream>
#include "Assemble.h"
#include "RubikCube.h"


int main()
{
    std::string command;
    CRubicsCube one;

    std::cout << "Input a command";
    std::cout << std::endl;
    std::cout << "'help' - list of commands";
    std::cout << std::endl;
    while (std::cin >> command)
    {
        if (command == "help")
        {
            std::cout << "'re' - Reading from a file" << std::endl;
            std::cout << "'wr' - writing to a file"<< std::endl;
            std::cout << "'cw_up[down, left, right, front, back]' - clockwise rotation of each face"<< std::endl;
            std::cout << "'ccw_up[down, left, right, front, back]' - counterclockwise rotation of each face"<< std::endl;
            std::cout << "'pr' - output of the current state"<< std::endl;
            std::cout << "'ass' - assembly of the cube"<< std::endl;
            std::cout << "'rand' - random combination of the cube"<< std::endl;
            std::cout << "'inv' - check if cube is correct"<< std::endl;
            std::cout << "'q' - finish program" << std::endl;
        }
        else if (command == "pr")
            one.printCube();
        else if (command == "cw_up")
            one.turn_clockwise('U');
        else if (command == "cw_down")
            one.turn_clockwise('D');
        else if (command == "cw_left")
            one.turn_clockwise('L');
        else if (command == "cw_right")
            one.turn_clockwise('R');
        else if (command == "cw_back")
            one.turn_clockwise('B');
        else if (command == "cw_front")
            one.turn_clockwise('F');
        else if (command == "ccw_up")
            one.turn_counterclockwise('U');
        else if (command == "ccw_down")
            one.turn_counterclockwise('D');
        else if (command == "ccw_left")
            one.turn_counterclockwise('L');
        else if (command == "ccw_right")
            one.turn_counterclockwise('R');
        else if (command == "ccw_back")
            one.turn_counterclockwise('B');
        else if (command == "ccw_front")
            one.turn_counterclockwise('F');
        else if (command == "re")
            one.read_file();
        else if (command == "wr")
            one.writing_file();
        else if (command == "ass")
        {
            AssemblingRubiksCube check(one);
            one = check.assemble();
            std::cout<<"cube successfully assembled" << std::endl;
        }
        else if (command == "rand")
            one.random_turn();
        else if (command == "inv")
        {
            AssemblingRubiksCube check(one);
            std::cout << check.invariance(one) << std::endl;
        }
        else if(command == "q")
        {
            std::cout <<"thank you for using this program!";
            return 0;
        }

    }


};