#include <iostream>
#include "inizializza_campo.h"
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
