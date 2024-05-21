#include <iostream>
#include "vittoria.h"
using namespace std;
void tabellanavi(int navicolpite1[6], int navicolpite2[6])
{
    cout << "\n\t--------------------------------------------\n";
    cout << "\tGIOVATORE1\tCOLPITA\t\tGIOCATORE2\tCOLPITA\n";

    for (int i = 1; i < 6; i++)
    {
        cout << "\tNAVE " << i << "\t\t ";
        if (navicolpite1[i] == 1)
        {
            cout << "SI ";
        }
        else
        {
            cout << "NO";
        }

        cout << "\t\tNAVE " << i << "\t\t ";
        if (navicolpite2[i] == 1)
        {
            cout << "SI\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
