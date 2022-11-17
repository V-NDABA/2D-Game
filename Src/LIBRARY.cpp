#include "LIBRARY.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cassert>

using namespace std;
namespace OceanSpace
{
    ///Getting a random number
    int getRandom(int intMin, int intMax)
    {
        int intRange = intMax - intMin+1;
        return rand()%intRange + intMin;
    }

    ///Converting a string into an integer
    int toInt(string strNumber)
    {
        int intArg = -1;
        stringstream ss (strNumber);
        ss >> intArg;
        if(ss.fail())
        {
            cerr << "String to integer conversion failed!";
            exit(CONV_ERR);
        }
    }

    ///Creating a gameworld
    TwoArray CreateWorld(int intRows,int intCols,int intRob,int intGar, int intNewGar)
    {
        TwoArray OceanArray;
        assert(OceanArray != nullptr);
        OceanArray = new OneArray[intRows];
        for(int r =0; r<intRows;r++)
        {
            OceanArray[r] = new int[intCols];
            for(int c = 0; c<intCols;c++)
            {
              OceanArray[r][c] = SPACE;
            }
        }
        return OceanArray;
    }

    ///Displaying the game world
    void displayOcean(int intRows, int intCols, TwoArray &OceanArray)
    {
        assert(OceanArray != nullptr);
        for(int r=0; r<intRows;r++)
        {
            for(int c=0;c<intCols;r++)
            {
                  cout << ".";
            }
            cout << endl;
        }
    }

    ///Placing the robot features
    void PlaceRobot(TwoArray& WaterArray,int intRows,int intCols,int intRob)
    {
        while(intRob > 0)
        {
            ///Generate a possible location
            int r = getRandom(0,intRows);
            int c = getRandom(0,intCols);
            if(WaterArray[r][c] == SPACE)
            {
                WaterArray[r][c] = ROBOTS;
            }
        }
    }

    ///Placing the garbage features
    void PlaceGarbage(TwoArray& WaterArray,int intRows,int intCols,int intGar)
    {
        while(intGar > 0)
        {
        ///Generate a possible location
            int r = getRandom(0,intRows);
            int c = getRandom(0,intCols);
            if(WaterArray[r][c] == SPACE)
                {
                    WaterArray[r][c] = GARBAGE;
                }
        }
    }

    ///Moving the Robots
    void MoveRobot(TwoArray& WaterArray,int intRows,int intCols)
    {
        int intMove = getRandom(0,4);

        Direction Dir = chDir[intMove];

        int intDR = intRows, intDC = intCols;

        switch(Dir)
        {
        case N:
            intDC--;
            break;
        case S:
            intDC++;
            break;
        case W:
            intDR--;
            break;
        case E:
            intDR++;
            break;
        }
        ///Check if it is out of the game world
         if(intDR < 0 || intDR > intRows ||
            intDC < 0 || intDC > intCols)
         {
             WaterArray[intRows][intCols] = SPACE;
             WaterArray[intDR][intDC] = ROBOTS;
         }
    }

    ///Deleting space in the heap
    void deleteSpace(TwoArray &OceanArray, int intRows)
    {
        for(int r =0; r<intRows;r++)
        {
            delete[] OceanArray[r];
        }
        delete OceanArray;
    }
}
