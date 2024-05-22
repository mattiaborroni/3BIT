#include <iostream>
#include "campo.h"
using namespace std;





#define N 9
void inizializzacampo(char campo[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            campo[x][y] = 32;
        }
    }
}

void pulisci()
{

    cout << "\x1B[2J\x1B[H";
    cin.clear();
}


void stampacampo(char campo1[N][N], char campo2[N][N])
{
    pulisci();
    cout << "\t\t**********************************************************\n";
    cout << "\t\t**************   CAMPO BATTAGLIA      ********************\n";
    cout << "\t\t**********************************************************\n\n\n";

    cout << "\t\tCAMPO GIOCATORE" << "\t\t\t CAMPO AVVERSARIO CPU\n\n";
    cout << "\t   A B C D E F G H I  \t\t  A B C D E F G H I  \n";
    cout << "\t ---------------------\t\t---------------------\n";

    for (int x = 0; x < N; x++)
    {

        cout << "      |" << x + 1 << "|  ";

        for (int y = 0; y < N; y++)
        {
            cout << campo1[x][y] << " ";
        }

        cout << "\t     |" << x + 1 << "|  ";
        for (int y = 0; y < N; y++)
        {

            if (campo2[x][y] == 49 || campo2[x][y] == 50 || campo2[x][y] == 51 || campo2[x][y] == 52 || campo2[x][y] == 53)
            {
                cout << "  ";
            }

            else
            {
                cout << campo2[x][y] << " ";
            }
        }

        cout << "\n";
    }
    cout << "\n\n";
}
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


