/*
Alunni: Borroni-Balducci-Ruffino-Sinigallia
Data: 15-05-2024
Titolo esercizio: Battaglia navale compito finale
Comando di compilazione: v3.0
Note:
*/

#include <iostream>
#include <string>


#define N 9 //Dimensione griglia 

using namespace std;
/**
 * @brief Pulisce lo schermo del terminale
 * 
 */
void pulisci(){
   
    cout << "\x1B[2J\x1B[H";
    cin.clear();
}

/**
 * @brief Fa premere un tasto per continuare
 * 
 */
void premi(){
    char a;
    cout<<"\nPremere ENTER per proseguire";
    cin.ignore(100,'\n');
    cin.get();
    
}

/**
 * @brief Inizializza il campo di gioco 
 * 
 * @param campo sceglie il campo da inizializzare
 */
void inizializzacampo(char campo[N][N]){
    for (int x=0;x<N;x++){
        for (int y=0;y<N;y++){
            campo[x][y]=32;
        }
    }
}

/**
 * @brief Realizza la scritta iniziale del gioco
 * 
 */
void scritta(){


    cout<<"######     #    ####### #######    #     #####  #       ###    #    \n";
    cout<<"#     #   # #      #       #      # #   #     # #        #    # #   \n";
    cout<<"#     #  #   #     #       #     #   #  #       #        #   #   #  \n";
    cout<<"######  #     #    #       #    #     # #  #### #        #  #     # \n";
    cout<<"#     # #######    #       #    ####### #     # #        #  ####### \n";
    cout<<"#     # #     #    #       #    #     # #     # #        #  #     # \n";
    cout<<"######  #     #    #       #    #     #  #####  ####### ### #     # \n\n\n\n";
    cout<<"      #     #    #    #     #    #    #       ####### \n";
    cout<<"      ##    #   # #   #     #   # #   #       #       \n";
    cout<<"      # #   #  #   #  #     #  #   #  #       #       \n";
    cout<<"      #  #  # #     # #     # #     # #       #####   \n";
    cout<<"      #   # # #######  #   #  ####### #       #       \n";
    cout<<"      #    ## #     #   # #   #     # #       #       \n";
    cout<<"      #     # #     #    #    #     # ####### ####### \n";


}

/**
 * @brief Stampa sul terminale i 2 campi di gioco
 * 
 * @param campo1 campo di sinistra
 * @param campo2 campo di destra
 */
void stampacampo(char campo1[N][N],char campo2[N][N])
{
    pulisci();
    cout<<"\t\t**********************************************************\n";
    cout<<"\t\t**************   CAMPO BATTAGLIA      ********************\n";
    cout<<"\t\t**********************************************************\n\n\n";
    
    cout<<"\t\tCAMPO GIOCATORE"<<"\t\t\t CAMPO AVVERSARIO CPU\n\n";
    cout<<"\t   A B C D E F G H I  \t\t  A B C D E F G H I  \n";
    cout<<"\t ---------------------\t\t---------------------\n";
    
    for (int x=0;x<N;x++) {
        
        cout<<"      |"<<x+1<<"|  ";
        
        for(int y=0;y<N;y++){
            cout<<campo1[x][y]<<" ";
        }
        
        cout<<"\t     |"<<x+1<<"|  ";
        for(int y=0;y<N;y++){

            if (campo2[x][y]==49 || campo2[x][y]==50 ||campo2[x][y]==51 ||campo2[x][y]==52 ||campo2[x][y]==53){
            cout<<"  ";
            }
            
            else {
            cout<<campo2[x][y]<<" ";
            }
        }
        
        cout<<"\n";
    }
   cout<<"\n\n";
}

/**
 * @brief Inserisce nei campi di gioco le navi in modo da prepararsi al gioco
 * 
 * @param campo quale campo di gioco
 * @param coord coordinate della nave da posizionare
 * @param orient orientamento 0=orizz 1=vert
 * @param lun lunghezza della nave
 * @param numnave numeor della nave
 * @return true se la nave viene inserita
 * @return false se la nave non puo' essere inserita
 */
bool inseriscinave(char campo[N][N],char coord[2],int orient,int lun,int numnave){
    int y=(coord[0]%32)-1;
    int x=(coord[1]%48)-1;
    bool ok=0;
    
 // Verifica se le coordinate della nave e la lunghezza sono compatibilicon il campo

 if ((y+lun>N && orient==0) || (x+lun>N && orient==1)){
    ok=0;
    return ok;
 }   
// Verifica se le caselle per inserire la nave sono libere

    if (orient==0){
        for (int i=0;i<lun;i++){
            if (campo[x][y+i]==32){
                ok=1;
                }
            else {
                ok=0;
                break;
                }
                
        }
    }
    if(orient==1){
        for (int i=0;i<lun;i++){
            if (campo[x+i][y]==32){
                ok=1;
                }
            else {
                ok=0;
                break;
                }
                
            
        }
    }
    
    if (ok==1){
        for (int i=0;i<lun;i++){
            if (orient==0){
                campo[x][y+i]=numnave+48;
            }
            else if (orient==1){
                campo[x+i][y]=numnave+48;
                
            }
        }
    }
    
    return ok;
}


/**
 * @brief Procedura per colpire una casella
 * 
 * @param campo sul quale inviare il colpo
 * @param coord del colpo che spariamo
 * @param navecolpita array dell'elenco delle navi colpite
 */
void spara(char campo[N][N],char coord[2],int navecolpita[5]){
    int y=(coord[0]%32)-1;
    int x=(coord[1]%48)-1;
    int nave=campo[x][y]-48;
    if (campo[x][y]==32){
        cout<<"ACQUA!!!!!!!!\n";
        campo[x][y]=45;
    }
    else if (campo[x][y]==45 || campo[x][y]==35){
        cout<<"CASELLA GIA CHIAMATA...PECCATO\n";
        
    }
    else {
        cout<<" HAI COLPITO NAVE "<<nave<<" !!!!\n";
        navecolpita[nave]=1;
        for (int x=0;x<N;x++){
        for (int y=0;y<N;y++){
            if(campo[x][y]==(48+nave)){
                campo[x][y]=35;
            };
        }
    }
        
        campo[x][y]=35;
    }
}

/**
 * @brief Tabellino resoconto navi colpite
 * 
 * @param navicolpite1 del primo giocatore
 * @param navicolpite2 del secondo giocatore
 */
void tabellanavi(int navicolpite1[6],int navicolpite2[6]){
    cout<<"\n\t--------------------------------------------\n";
    cout<<"\tGIOVATORE1\tCOLPITA\t\tGIOCATORE2\tCOLPITA\n";

    for (int i=1;i<6;i++){
        cout<<"\tNAVE "<<i<<"\t\t ";
        if (navicolpite1[i]==1){
            cout<<"SI ";
        }
        else {
            cout<<"NO";
        }

        cout<<"\t\tNAVE "<<i<<"\t\t ";
        if (navicolpite2[i]==1){
            cout<<"SI\n";
            }
        else {
            cout<<"NO\n";
        }
    }
}

//**************************************************************
//INIZIO CODICE MAIN
//**************************************************************

/**
 * @brief Codice inizio gioco
 * 
 * @return int 
 */

int main(){
    srand(time(NULL));
    
//variabili principali
    
    char campo1[N][N]={};
    char campo2[N][N]={};
    char coord[2]={};
    int orientamento=0;
    int lunghezzanave[7]={0,5,4,3,3,2};
    int lung=0;
    bool ok=0;
    int navigiocatore1colpite[6]={0,0,0,0,0,0};
    int navigiocatore2colpite[6]={0,0,0,0,0,0};
    int vittoria=0;
    
//pulitura array campi    
    inizializzacampo(campo1);
    inizializzacampo(campo2);
    
//Prima schermata
    
    scritta();
    premi();
    pulisci();
    stampacampo(campo1,campo2);
    
//inizio
    cout<<"Benvenuti nella sfida della battaglia navale\n";
    cout<<"per prima cosa dobbiamo posizionare le 5 navi\n";
    cout<<"ti ricordo che per ogni nave devi indicare le coordinate iniziali (per esempio E2) e l'orientamento orizzontale (0) o verticale (1)\n";
    premi();
    stampacampo(campo1,campo2);
    
    cout<<"Inseriamo ora le navi... ti ricordo che dovrai inserire:\n";
    cout<<"1 nave da 5\n1 nave da 4\n2 navi da 3\n1 nave da 2\n";

    premi();
    
    
    for (int i=1;i<6;i++){

        do{
            stampacampo(campo1,campo2);
            cout<<"inserisce coordinate nave "<<i<<" ";
            cin>>coord;
            cout<<"\ninserire orientamento nave "<<i<<" (0=orizzontale 1=verticale)  ";
            cin>>orientamento;
            lung=lunghezzanave[i];
            ok=inseriscinave(campo1,coord,orientamento,lung,i);
                if (ok==0){
                cout<<"\n\acoordinate non compatibili per inserimento nave";
                premi();
                }
        }while (ok==0);
    
    }
    
    cout<<"\nOra devo inserire le navi avversarie....\n";
    premi();
 
/**
 * @brief INSERIMENTO NAVI AVVERSARIO
 * 
 */

    inizializzacampo(campo2);
    
    for (int i=1;i<6;i++){
    do{
        coord[0]=rand()%9+65;
        coord[1]=rand()%9+49;
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
    
    cout<<"Ora inizia il gioco... inserisci le coordiate del tuo colpo...\n";
    cout<<"Ricorda che per affondare una nave basta un solo colpo a segno...\n";
    tabellanavi(navigiocatore1colpite,navigiocatore2colpite);
    cout<<"\n\nINSERISCI COORDINATE DI TIRO...... ";
    cin>>coord;
    spara(campo2,coord,navigiocatore2colpite);
    
    cout<<"\n\nORA TOCCA AL COMPUTER.....\n";
    coord[0]=rand()%9+65;
    coord[1]=rand()%9+49;
    cout<<coord[0]<<coord[1]<<" ";
    spara(campo1,coord,navigiocatore1colpite);
    
    premi();
    if (navigiocatore1colpite[1]==1 && navigiocatore1colpite[2]==1 && navigiocatore1colpite[3]==1 && navigiocatore1colpite[4]==1 && navigiocatore1colpite[5]==1){
        vittoria=2;
        }
    if (navigiocatore2colpite[1]==1 && navigiocatore2colpite[2]==1 && navigiocatore2colpite[3]==1 && navigiocatore2colpite[4]==1 && navigiocatore2colpite[5]==1){
        vittoria=1;
        }
        
    } while (vittoria==0);

    cout<<"\n*****************************************************\n";
    cout<<"    GIOCATORE "<<vittoria<<" vince la partita!!!!\n";
    cout<<"*****************************************************\n";
    premi();
    
    return EXIT_SUCCESS;
    
    
   
}
