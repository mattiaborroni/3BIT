/*
Alunni: Borroni-Balducci-Ruffino-Sinigallia
Data: 06-05-2024
Titolo esercizio: Battaglia navale compito finale
Comando di compilazione:
Note: VERSIONE 1.4
*/

#include <iostream>
#include <string>
#include <stdlib.h>

#define N 10 //Dimensione griglia 

using namespace std;

void pulisci(){

    cout << "\x1B[2J\x1B[H";
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
    cout<<"      #     # #     #    #    #     # ####### ####### \n";

}

void stampacampo(char campo1[N][N],char campo2[N][N])
{
    
    cout<<"\t*******************************************************\n";
    cout<<"\t**************   CAMPO BATTAGLIA      *****************\n";
    cout<<"\t*******************************************************\n";
    
    cout<<"\t***********************\t *******************************\n";
    cout<<"\tA B C D E F G H I J   |\t|\tA B C D E F G H I J    |\n";
    cout<<"\t-------------------\t------------------------------\n";
    
    for (int x=0;x<N;x++) {
        
        cout<<"    |"<<x+1<<"\t|  ";
        
        for(int y=0;y<N;y++){
            cout<<campo1[x][y]<<" ";
        }
        
        cout<<"                      |"<<x+1<<"\t| ";
        for(int y=0;y<N;y++){
            cout<<campo2[x][y]<<" ";
        }
        
        cout<<endl;
    }
    
}

int main()
{
    srand(time(NULL));
    
//variabili principali
    
    char campo1[N][N]={"1","2","3","4","5","6","7","8","9","0"};
    char campo2[N][N]={"a","b","b","b","b","b","b","g"};
    
   
    
//Prima schermata
    
    scritta();
    
    cout<<"\n Premere ENTER per proseguire";
    cin.get();

    pulisci();
    stampacampo(campo1,campo2);


    

//inizio

  
    
    
//mettere  le navi 





//generatore del campo navale



    
 
// inserimento coordinate

}


}

