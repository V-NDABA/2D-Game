#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
#include <sstream>
#include <cctype>
#include <iostream>
#include <stdlib.h>


using namespace std;
namespace OceanSpace
{
    ///Exit Points
    enum Stops
    {
        ARG_ERR,
        CONV_ERR,
        DONE
    };

    ///FEATURES
    enum Feats
    {
        SPACE,
        ROBOTS,
        GARBAGE
    };

    enum Direction
    {
        N,
        S,
        W,
        E
    };

    const char chFeats[] = {'.','@','!'};
    const Direction chDir[] = {N, S, W, E};

    typedef int* OneArray;
    typedef OneArray* TwoArray;

    TwoArray CreateWorld(int intRows,int intCols,int intRob,int intGar,int intNewGar);
    int toInt(string strNumber);
    int getRandom(int intMin,int intMax);
    void displayOcean(int intRows, int intCols, TwoArray &OceanArray);
    void deleteSpace(TwoArray &OceanArray, int intRows);
    void PlaceRobot(TwoArray& WaterArray,int intRows,int intCols,int intRob);
    void PlaceGarbage(TwoArray& WaterArray,int intRows,int intCols,int intGar);
    void MoveRobot(TwoArray& WaterArray,int intRows,int intCols);
}
#endif // LIBRARY_H_INCLUDED
