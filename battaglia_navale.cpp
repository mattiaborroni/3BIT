#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


void inizializza_griglia(char coord[9][9]);
void posiziona_navi(char coord[9][9]);
void stampa_campo(char coord[9][9]);
bool controllo_coordinate(int x, int y);
bool se_colpita(char coord[9][9], int x, int y);
void gioco(char coord[9][9]);
void rivela_navi(char coord[9][9]);

int main() {
    char coord[9][9];
    inizializza_griglia(coord);
    posiziona_navi(coord);
    gioco(coord);
    return 0;
}


void inizializza_griglia(char coord[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            coord[i][j] = ' ';
        }
    }
}


void posiziona_navi(char coord[9][9]) {
    srand(time(NULL));
    int ship1oriz = rand() % 7;
    int ship1vert = rand() % 7;
    int ship2oriz = rand() % 7;
    int ship2vert = rand() % 7;

    // posiziona nave 1
    coord[ship1oriz][ship1vert] = '1';
    coord[ship1oriz + 1][ship1vert] = '1';
    coord[ship1oriz][ship1vert + 1] = '1';
    coord[ship1oriz + 1][ship1vert + 1] = '1';

    //posiziona nave  2
    do {
        ship2oriz = rand() % 7;
        ship2vert = rand() % 7;
    } while (coord[ship2oriz][ship2vert] == '1' || coord[ship2oriz + 1][ship2vert] == '1' || coord[ship2oriz][ship2vert + 1] == '1' || coord[ship2oriz + 1][ship2vert + 1] == '1');

    coord[ship2oriz][ship2vert] = '2';
    coord[ship2oriz + 1][ship2vert] = '2';
    coord[ship2oriz][ship2vert + 1] = '2';
    coord[ship2oriz + 1][ship2vert + 1] = '2';
}


void stampa_campo(char coord[9][9]) {
    cout << "   BATTAGLIA NAVALE \n\n";
    cout << "********************* \n\n";
    cout << "   0 1 2 3 4 5 6 7\n";
    cout << "---------------------\n";
    for (int x = 0; x < 8; x++) {
        cout << x << "| ";
        for (int y = 0; y < 8; y++) {
            cout << coord[x][y] << " ";
        }
        cout << endl;
    }
}

// Function to check if a coordinate is valid
bool controllo_coordinate(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

// Function to check if a coordinate is a hit
bool se_colpita(char coord[9][9], int x, int y) {
    return (coord[x][y] == '1' || coord[x][y] == '2');
}

// Function to play the game
void gioco(char coord[9][9]) {
    int attempts = 8;
    while (attempts > 0) {
        cout << "*******************************************************\n";
        cout << "Hai ancora " << attempts << " tentativi per vincere la partita\n";
        cout << "*******************************************************\n";
        stampa_campo(coord);
        int x, y;
        do {
            cout << "\nInserire coordinata orizzontale: ";
            cin >> x;
            if (!controllo_coordinate(x, 0)) {
                cout << "Valore fuori portata, riprova.\n";
            }
        } while (!controllo_coordinate(x, 0));

        do {
            cout << "Inserire coordinata verticale: ";
            cin >> y;
            if (!controllo_coordinate(0, y)) {
                cout << "Valore fuori portata, riprova.\n";
            }
        } while (!controllo_coordinate(0, y));

        if (se_colpita(coord, x, y)) {
            cout << "\n***************************\nHAI COLPITO UNA NAVE!\n***************************\n";
            coord[x][y] = 'X'; // Mark hit on the grid
        } else {
            cout << "\n***************************\nACQUA! Nessuna nave qui.\n***************************\n";
            coord[x][y] = 'O'; // Mark miss on the grid
        }

        attempts--;

        // Check for victory condition
        if (coord[x][y] == '1' && coord[x][y] == '2') {
            cout << "\n\n***************************\nHAI VINTO LA PARTITA!\n***************************\n";
            return;
        }
    }

    // If the loop completes, the player has run out of attempts
    cout << "\n\n***************************\nHAI PERSO! Hai esaurito tutti i tentativi.\n***************************\n";
    char response;
    cout << "\nVuoi vedere dove erano le navi? (s/n): ";
    cin >> response;
    if (response == 's' || response == 'S') {
        rivela_navi(coord);
    }
}

// Function to reveal the ships' positions
void rivela_navi(char coord[9][9]) {
    cout << "********************* \n\n";
    cout << "   0 1 2 3 4 5 6 7\n";
    cout << "---------------------\n";
    for (int x = 0; x < 8; x++) {
        cout << x << "| ";
        for (int y = 0; y < 8; y++) {
            cout << coord[x][y] << " ";
        }
        cout << endl;
    }
}
