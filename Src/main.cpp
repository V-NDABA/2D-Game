#include <iostream>
#include "LIBRARY.h"
using namespace std;
using namespace OceanSpace;
int main(int argc, char* argv[])
{
    if(argc != 6)
    {
        cerr << "Invalid number of command line arguments";
        exit(ARG_ERR);
    }
    int intORows = toInt(argv[1]);
    int intOCols = toInt(argv[2]);
    int intRobots = toInt(argv[3]);
    int intGarbage = toInt(argv[4]);
    int intGarChance = toInt(argv[5]);

    TwoArray OceanArray = CreateWorld(intORows,intOCols,intRobots,intGarbage,intGarChance);
    bool blnContinue = true;
    char chOption = '/o';

    do
        {
        system("cls");
        displayOcean(intORows,intOCols,OceanArray);
        cin >> chOption;
        switch(chOption)
        {
        case 'q':
        case 'Q':
            MoveRobot(OceanArray, intORows, intOCols);
        case 'p':
        case 'P':
            {
                blnContinue = false;
                break;
            }
        default:
            {
                cout << "done" << endl;
                system("pause");
                break;
            }
        }
    }while(blnContinue);
    deleteSpace(OceanArray, intORows);
}
