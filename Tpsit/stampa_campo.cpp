#include <iostream>
#include "stampa_campo.h"
#include "pulisci.h"
using namespace std;

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