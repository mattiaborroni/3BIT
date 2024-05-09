/*
Alunni: Borroni-Balducci-Ruffino-Sinigallia
Data: 06-05-2024
Titolo esercizio: Battaglia navale compito finale
Comando di compilazione: v2.1
Note:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#define N 9 //Dimensione griglia 

using namespace std;

void pulisci(){
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\x1B[2J\x1B[H";
}

void premi(){
    cout<<"\nPremere ENTER per proseguire";
    cin.get();
    
}

void inizializzacampo(char campo[N][N]){
    for (int x=0;x<N;x++){
        for (int y=0;y<N;y++){
            campo[x][y]=32;
        }
    }
}

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
    cout<<"      #     # #     #    #    #     # ####### ####### \n\a";

}

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
            cout<<campo2[x][y]<<" ";
        }
        
        cout<<"\n";
    }
   cout<<"\n\n";
}

bool inseriscinave(char campo[N][N],char coord[2],int orient,int lun,int numnave){
    int y=(coord[0]%32)-1;
    int x=(coord[1]%48)-1;
    bool ok=0;
    
 // Verifica se le coordinate della nave e la lunghezza sono compatibilicon il campo

 if (y+lun>N+1 || x+lun>N+1){
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
void posizionaNavi(char coord[9][9])
{
    srand(time(NULL));
    int nave1Orizz = rand() % 7;
    int nave1Vert = rand() % 7;
    int nave2Orizz = rand() % 7;
    int nave2Vert = rand() % 7;

    // Posiziona nave 1
    coord[nave1Orizz][nave1Vert] = '1';
    coord[nave1Orizz + 1][nave1Vert] = '1';
    coord[nave1Orizz][nave1Vert + 1] = '1';
    coord[nave1Orizz + 1][nave1Vert + 1] = '1';

    // Posiziona nave 2
    do
    {
        nave2Orizz = rand() % 7;
        nave2Vert = rand() % 7;
    } while (coord[nave2Orizz][nave2Vert] == '1' || coord[nave2Orizz + 1][nave2Vert] == '1' || coord[nave2Orizz][nave2Vert + 1] == '1' || coord[nave2Orizz + 1][nave2Vert + 1] == '1');

    coord[nave2Orizz][nave2Vert] = '2';
    coord[nave2Orizz + 1][nave2Vert] = '2';
    coord[nave2Orizz][nave2Vert + 1] = '2';
    coord[nave2Orizz + 1][nave2Vert + 1] = '2';
}
int main()
{
    srand(time(NULL));
    
//variabili principali
    
    char campo1[N][N]={ };
    char campo2[N][N]={ };
    char coord[2]={};
    int orientamento=0;
    int lunghezzanave[7]={0,5,4,3,3,2};
    int lung=0;
    bool ok=0;
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
    
        cout<<"\ninserire orientamento nave "<<i<<" ";
        cin>>orientamento;
    
        lung=lunghezzanave[i];
    
        ok=inseriscinave(campo1,coord,orientamento,lung,i);
        
        if (ok==0){
            cout<<"\n\acoordinate non compatibili per inserimento nave";
            cin.get();
            premi();
            }
        
    }while (ok==0);
    
    
    }
   
    

    
    
    

    
    
//mettere  le navi 





//generatore del campo navale



    
 
// inserimento coordinate

}void posizionaNavi(char coord[9][9])
{
    srand(time(NULL));
    int nave1Orizz = rand() % 7;
    int nave1Vert = rand() % 7;
    int nave2Orizz = rand() % 7;
    int nave2Vert = rand() % 7;

    // Posiziona nave 1
    coord[nave1Orizz][nave1Vert] = '1';
    coord[nave1Orizz + 1][nave1Vert] = '1';
    coord[nave1Orizz][nave1Vert + 1] = '1';
    coord[nave1Orizz + 1][nave1Vert + 1] = '1';

    // Posiziona nave 2
    do
    {
        nave2Orizz = rand() % 7;
        nave2Vert = rand() % 7;
    } while (coord[nave2Orizz][nave2Vert] == '1' || coord[nave2Orizz + 1][nave2Vert] == '1' || coord[nave2Orizz][nave2Vert + 1] == '1' || coord[nave2Orizz + 1][nave2Vert + 1] == '1');

    coord[nave2Orizz][nave2Vert] = '2';
    coord[nave2Orizz + 1][nave2Vert] = '2';
    coord[nave2Orizz][nave2Vert + 1] = '2';
    coord[nave2Orizz + 1][nave2Vert + 1] = '2';
}
