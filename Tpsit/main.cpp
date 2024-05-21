/*
Alunni: Borroni-Balducci-Ruffino-Sinigallia
Data: 15-05-2024
Titolo esercizio: Battaglia navale compito finale
Comando di compilazione: v3.0
Note:
*/

#include <iostream>
#include <string>
#include "pulisci.h"
#include "premi.h"
#include "scritta.h"
#include "spara.h"
#include "stampa_campo.h"
#include "tabella_navi.h"
#include "vittoria.h"
#include "inizializza_campo.h"
#include "inserisci_nave.h"







using namespace std;

int main()
{
    srand(time(NULL));

    // variabili principali

    char campo1[N][N] = {};
    char campo2[N][N] = {};
    char coord[2] = {};
    int orientamento = 0;
    int lunghezzanave[7] = {0, 5, 4, 3, 3, 2};
    int lung = 0;
    bool ok = 0;
    int navigiocatore1colpite[6] = {0, 0, 0, 0, 0, 0};
    int navigiocatore2colpite[6] = {0, 0, 0, 0, 0, 0};
    int win = 0;

    // pulitura array campi
    inizializzacampo(campo1);
    inizializzacampo(campo2);

    // Prima schermata

    scritta();
    premi();
    pulisci();
    stampacampo(campo1, campo2);

    // inizio
    cout << "Benvenuti nella sfida della battaglia navale\n";
    cout << "per prima cosa dobbiamo posizionare le 5 navi\n";
    cout << "ti ricordo che per ogni nave devi indicare le coordinate iniziali (per esempio E2) e l'orientamento orizzontale (0) o verticale (1)\n";
    premi();
    stampacampo(campo1, campo2);

    cout << "Inseriamo ora le navi... ti ricordo che dovrai inserire:\n";
    cout << "1 nave da 5\n1 nave da 4\n2 navi da 3\n1 nave da 2\n";

    premi();

    for (int i = 1; i < 6; i++)
    {

        do
        {
            stampacampo(campo1, campo2);
            cout << "inserisce coordinate nave " << i << " ";
            cin >> coord;
            cout << "\ninserire orientamento nave " << i << " (0=orizzontale 1=verticale)  ";
            cin >> orientamento;
            lung = lunghezzanave[i];
            ok = inseriscinave(campo1, coord, orientamento, lung, i);
            if (ok == 0)
            {
                cout << "\n\acoordinate non compatibili per inserimento nave";
                premi();
            }
        } while (ok == 0);
    }

    cout << "\nOra devo inserire le navi avversarie....\n";
    premi();

    /**
     * @brief INSERIMENTO NAVI AVVERSARIO
     *
     */

    inizializzacampo(campo2);

    for (int i = 1; i < 6; i++)
    {
        do
        {
            coord[0] = rand() % 9 + 65;
            coord[1] = rand() % 9 + 49;
            orientamento = rand() % 2;
            lung = lunghezzanave[i];
            ok = inseriscinave(campo2, coord, orientamento, lung, i);

        } while (ok == 0);
    }

    do
    {
        stampacampo(campo1, campo2);

        /**
         * @brief Inizio della sfida vera e propria
         *
         */

        cout << "Ora inizia il gioco... inserisci le coordiate del tuo colpo...\n";
        cout << "Ricorda che per affondare una nave basta un solo colpo a segno...\n";
        tabellanavi(navigiocatore1colpite, navigiocatore2colpite);
        cout << "\n\nINSERISCI COORDINATE DI TIRO...... ";
        cin >> coord;
        spara(campo2, coord, navigiocatore2colpite);

        cout << "\n\nORA TOCCA AL COMPUTER.....\n";
        coord[0] = rand() % 9 + 65;
        coord[1] = rand() % 9 + 49;
        cout << coord[0] << coord[1] << " ";
        spara(campo1, coord, navigiocatore1colpite);

        premi();
        if (navigiocatore1colpite[1] == 1 && navigiocatore1colpite[2] == 1 && navigiocatore1colpite[3] == 1 && navigiocatore1colpite[4] == 1 && navigiocatore1colpite[5] == 1)
        {
            win = 2;
        }
        if (navigiocatore2colpite[1] == 1 && navigiocatore2colpite[2] == 1 && navigiocatore2colpite[3] == 1 && navigiocatore2colpite[4] == 1 && navigiocatore2colpite[5] == 1)
        {
            win = 1;
        }

    } while (win == 0);

    cout << "\n*****************************************************\n";
    cout << "    GIOCATORE " << win << " vince la partita!!!!\n";
    cout << "*****************************************************\n";
    vittoria();
    premi();

    return EXIT_SUCCESS;
}