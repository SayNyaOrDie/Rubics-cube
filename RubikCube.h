#ifndef RUBIK__S_CUBE_CRUBICSCUBE_H
#define RUBIK__S_CUBE_CRUBICSCUBE_H

#include "SmallCube.h"
#include <fstream>
class CRubicsCube
{
public:
    std::vector<std::vector<std::vector<CSmallCube>>> cube;
    CRubicsCube();

    CRubicsCube &operator=(const CRubicsCube &other);

    void default_colors();
    void positionCubes(char side);//Расстановка позиций для кубика

    void printCube();
    void turn_clockwise(char side);

    void random_turn();

    void turn_counterclockwise(char side);

    void writing_file();//Запись состояния в файл
    void read_file(); //Считывание состояния с файла

};


#endif
