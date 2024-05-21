/*
Alunni: Borroni-Balducci-Ruffino-Sinigallia
Data: 15-05-2024
Titolo esercizio: Battaglia navale compito finale
Comando di compilazione: v3.0
Note:
*/

#include <iostream>
#include <string>
#include "librerie.h"

#define N 9 //Dimensione griglia 

using namespace std;



//**************************************************************
//INIZIO CODICE MAIN
//**************************************************************

/**
 * @brief Codice main del gioco
 * 
 * @return int per fine del gioco
 */

int main(){

/**
 * @brief Inizializzo il generatore di numeri casuali
 * 
 */
    srand(time(NULL));
    
/**
 * @brief inizializzazioni delle variabili del gioco
 * 
 */
    
    char campo1[N][N]={}; //creazione matrice campo 1
    char campo2[N][N]={};  //creazione matrice campo 2
    char coord[2]={}; //definizione variabile coordinate xy
    int orientamento=0; //variabile per contenere l'orientamento della nave
    int lunghezzanave[7]={0,5,4,3,3,2}; //array  per indicare la lunghezza di ognuna delle 5 navi
    int lung=0;
    bool ok=0;
    int navigiocatore1colpite[6]={0,0,0,0,0,0}; //array usato per identificare le navi colpite del 1 giocatore
    int navigiocatore2colpite[6]={0,0,0,0,0,0}; //array usato per identificare le navi colpite del 1 giocatore
    int vittoria=0;
    
/**
 * @brief Pulitura dei 2 array dei campi in modo da avere matrici pulite
 * 
 */
    inizializzacampo(campo1);
    inizializzacampo(campo2);
    
/**
 * @brief Prima schermata del gioco
 * 
 */
    
    scritta();
    premi();
    pulisci();
    stampacampo(campo1,campo2);
    
/**
 * @brief Istruzioni di gioco
 * 
 */
    cout<<"Benvenuti nella sfida della battaglia navale! \n";
    cout<<"per prima cosa dobbiamo posizionare le 5 navi\n";
    cout<<"ti ricordo che per ogni nave devi indicare le coordinate iniziali (per esempio E2) e l'orientamento orizzontale (0) o verticale (1)\n";
    premi();
    stampacampo(campo1,campo2);

    
    cout<<"Inseriamo ora le navi... ti ricordo che dovrai inserire:\n";
    cout<<"1 nave da 5\n1 nave da 4\n2 navi da 3\n1 nave da 2\n";

    premi();
    
/**
 * @brief CIclo inserimento navi in griglia
 * 
 */
    
    for (int i=1;i<6;i++){ //contatore per l'inserimento delle 5 navi 

        do{
            stampacampo(campo1,campo2);
            cout<<"inserisce coordinate nave "<<i<<" ";
            cin>>coord;
            cout<<"\ninserire orientamento nave "<<i<<" (0=orizzontale 1=verticale)  ";
            cin>>orientamento;
            lung=lunghezzanave[i];
            ok=inseriscinave(campo1,coord,orientamento,lung,i); //passiamo la nave con lunghezza alla prodedura di inserimento, se ritorna ok la nave viene inserita e ricomincia il ciclo
                if (ok==0){
                cout<<"\n\acoordinate non compatibili per inserimento nave";
                premi();
                }
        }while (ok==0);
    
    }
    
    cout<<"\nOra devo inserire le navi avversarie....\n";
    premi();
 
/**
 * @brief Inserimento navi avversario automatico
 * 
 */

    inizializzacampo(campo2); 
    
    for (int i=1;i<6;i++){   //contatore per l'inserimento delle 5 navi , il ciclo viene ripetuto fino a quando le 5 navi non sono inseite correttamente
    do{
        coord[0]=rand()%9+65;  //generatore di una ccordinata x casuale
        coord[1]=rand()%9+49;    //generatore di una ccordinata y casuale
        orientamento=rand()%2;
        lung=lunghezzanave[i];
        ok=inseriscinave(campo2,coord,orientamento,lung,i);
        
    }while (ok==0);
    
    }
    
    
    do{
    stampacampo(campo1,campo2);

/**
 * @brief Inizio della sfida vera e propria
 * 
 */

    cout<<"Ora inizia il gioco... inserisci le coordiate del tuo colpo, ATTENZIONE, hai colpi limitati!\n";
    cout<<"Ricorda che per affondare una nave basta un solo colpo a segno...\n";
    tabellanavi(navigiocatore1colpite,navigiocatore2colpite);
    cout<<"\n\nINSERISCI COORDINATE DI TIRO...... ";
    cin>>coord;
    spara(campo2,coord,navigiocatore2colpite); //la procedura verifica se le coordinate colpiscono la nave avversaria
    
    cout<<"\n\nORA TOCCA AL COMPUTER.....\n";
    coord[0]=rand()%9+65;    //coordinate x y casuali del computer
    coord[1]=rand()%9+49;
    cout<<coord[0]<<coord[1]<<" ";
    spara(campo1,coord,navigiocatore1colpite); //la procedura verifica se le coordinate colpiscono la nave avversaria
    
    premi();

/**
 * @brief verifica se uno dei due giocatori ha vinto
 * 
*/
    if (navigiocatore1colpite[1]==1 && navigiocatore1colpite[2]==1 && navigiocatore1colpite[3]==1 && navigiocatore1colpite[4]==1 && navigiocatore1colpite[5]==1){
        vittoria=2;
        }
    if (navigiocatore2colpite[1]==1 && navigiocatore2colpite[2]==1 && navigiocatore2colpite[3]==1 && navigiocatore2colpite[4]==1 && navigiocatore2colpite[5]==1){
        vittoria=1;
        }
        
    } while (vittoria==0);

/**
 * @brief Schermata che identifica il vincitore
 * 
 */


    cout<<"\n*****************************************************\n";
    cout<<"    GIOCATORE "<<vittoria<<" vince la partita!!!!\n";
    cout<<"*****************************************************\n";
    
cout<<"       ▄█    █▄   ▄█      ███         ███      ▄██████▄     ▄████████  ▄█     ▄████████ \n";
cout<<"       ███    ███ ███  ▀█████████▄ ▀█████████▄ ███    ███   ███    ███ ███    ███    ███ \n";
cout<<"       ███    ███ ███▌    ▀███▀▀██    ▀███▀▀██ ███    ███   ███    ███ ███▌   ███    ███ \n";
cout<<"       ███    ███ ███▌     ███   ▀     ███   ▀ ███    ███  ▄███▄▄▄▄██▀ ███▌   ███    ███ \n";
cout<<"       ███    ███ ███▌     ███         ███     ███    ███ ▀▀███▀▀▀▀▀   ███▌ ▀███████████ \n";
cout<<"       ███    ███ ███      ███         ███     ███    ███ ▀███████████ ███    ███    ███ \n";
 cout<<"      ███    ███ ███      ███         ███     ███    ███   ███    ███ ███    ███    ███ \n";
 cout<<"       ▀██████▀  █▀      ▄████▀      ▄████▀    ▀██████▀    ███    ███ █▀     ███    █▀  \n";
 cout<<"                                                           ███    ███                   \n" ;  

    premi();
    
    return EXIT_SUCCESS;
    
    
   
}
