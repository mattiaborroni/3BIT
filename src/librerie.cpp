#include <iostream>
#include <string>
#include "librerie.h" // Include il file header con le dichiarazioni

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
 * @param colpi massimo numero dei colpi
 * @param coord del colpo che spariamo
 * @param navecolpita array dell'elenco delle navi colpite
 */
void spara(char campo[N][N],char coord[2],int navecolpita[5]){
    int colpi = 7; 
    int y=(coord[0]%32)-1;
    int x=(coord[1]%48)-1;
    int nave=campo[x][y]-48;
    if (campo[x][y]==32){
        cout<<"ACQUA!!!!!!!!\n";
        campo[x][y]=45;
        colpi = colpi - 1;
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
                colpi = colpi - 1;
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
    cout<<"\tGIOCATORE1\tCOLPITA\t\tGIOCATORE2\tCOLPITA\n";

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


