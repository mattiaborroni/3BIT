#include <iostream>
#include "vittoria.h"
using namespace std;
#define N 9

void spara(char campo[N][N], char coord[2], int navecolpita[5])
{
    int y = (coord[0] % 32) - 1;
    int x = (coord[1] % 48) - 1;
    int nave = campo[x][y] - 48;
    if (campo[x][y] == 32)
    {
        cout << "ACQUA!!!!!!!!\n";
        campo[x][y] = 45;
    }
    else if (campo[x][y] == 45 || campo[x][y] == 35)
    {
        cout << "CASELLA GIA CHIAMATA...PECCATO\n";
    }
    else
    {
        cout << " HAI COLPITO NAVE " << nave << " !!!!\n";
        navecolpita[nave] = 1;
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (campo[x][y] == (48 + nave))
                {
                    campo[x][y] = 35;
                };
            }
        }

        campo[x][y] = 35;
    }
}