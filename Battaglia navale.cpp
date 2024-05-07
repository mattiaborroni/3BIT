/*
Alunni: Borroni-Balducci-Ruffino-Sinigallia
Data: 06-05-2024
Titolo esercizio: Battaglia navale compito finale
Comando di compilazione:
Note: v2.0
*/

#include <iostream>
#include <string>
#include <stdlib.h>

#define N 10 //Dimensione griglia 

using namespace std;

void pulisci(){
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\x1B[2J\x1B[H";
}

void premi(){
    cout<<"\n\nPremere ENTER per proseguire";
    cin.get();
    
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
    
    cout<<"\t\tCAMPO GIOCATORE"<<"\t\t\t   CAMPO AVVERSARIO CPU\n\n";
    cout<<"\t   A B C D E F G H I J |\t\t  A B C D E F G H I J |\n";
    cout<<"\t------------------------\t\t-----------------------\n";
    
    for (int x=0;x<N;x++) {
        
        cout<<"    |"<<x+1<<"\t|  ";
        
        for(int y=0;y<N;y++){
            cout<<campo1[x][y]<<" ";
        }
        
        cout<<"                      |"<<x+1<<"\t| ";
        for(int y=0;y<N;y++){
            cout<<campo2[x][y]<<" ";
        }
        
        cout<<"\n";
    }
   cout<<"\n\n";
}

void inseriscinave(char campo1[N][N],char coord[2],int orien,int lung){
    int x=coord [0]-30;
    int y=coord [1]-30;
    cout<<"X="<<x<<endl;
    cout<<"y="<<y<<endl;
    
    campo1[x][y]=42;
    premi();
}

int main()
{
    srand(time(NULL));
    
//variabili principali
    
    char campo1[N][N]={};
    char campo2[N][N]={};
    char coord[2]={};
    int orientamento=0;
    int lunghezzanave[8]={0,5,4,4,3,3,2};
    int lung=0;
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
    cout<<"1 nave da 5\n2 navi da 4\n2navi da 3\n1 nave da2\n";
    premi();
    
    
for (int i=1;i<6;i++){
    stampacampo(campo1,campo2);
    
    cout<<"inserisce coordinate nave "<<i<<" ";
    cin>>coord;
    
    cout<<"\ninserire orientamento nave "<<i<<" ";
    cin>>orientamento;
    
    lung=lunghezzanave[i];
    
    inseriscinave(campo1,coord,orientamento,lung);
        
    }
   
    

    
    
    

    
    
//mettere  le navi 





//generatore del campo navale



    
 
// inserimento coordinate

}
