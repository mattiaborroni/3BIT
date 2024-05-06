/*
Alunni: Borroni-Balducci-Ruffino-Sinigallia
Data: 06-05-2024
Titolo esercizio: Battaglia navale compito finale
Comando di compilazione:
Note:
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void Scritta{
    cout<<" ____       ______      ______    ______    ______      ____       __         ______      ______     "<<endl;
    cout<<"/\  _`\    /\  _  \    /\__  _\  /\__  _\  /\  _  \    /\  _`\    /\ \       /\__  _\    /\  _  \    "<<endl;
    cout<<"\ \ \L\ \  \ \ \L\ \   \/_/\ \/  \/_/\ \/  \ \ \L\ \   \ \ \L\_\  \ \ \      \/_/\ \/    \ \ \L\ \   "<<endl;
    cout<<" \ \  _ <'  \ \  __ \     \ \ \     \ \ \   \ \  __ \   \ \ \L_L   \ \ \  __    \ \ \     \ \  __ \  "<<endl;
    cout<<"  \ \ \L\ \  \ \ \/\ \     \ \ \     \ \ \   \ \ \/\ \   \ \ \/, \  \ \ \L\ \    \_\ \__   \ \ \/\ \ "<<endl;
    cout<<"   \ \____/   \ \_\ \_\     \ \_\     \ \_\   \ \_\ \_\   \ \____/   \ \____/    /\_____\   \ \_\ \_\"<<endl;
    cout<<"    \/___/     \/_/\/_/      \/_/      \/_/    \/_/\/_/    \/___/     \/___/     \/_____/    \/_/\/_/"<<endl<<endl<<endl<<endl;
    cout<<"                       __  __      ______      __  __     ______      __         ____      "<<endl;
    cout<<"                      /\ \/\ \    /\  _  \    /\ \/\ \   /\  _  \    /\ \       /\  _`\    "<<endl;
    cout<<"                      \ \ `\\ \   \ \ \L\ \   \ \ \ \ \  \ \ \L\ \   \ \ \      \ \ \L\_\  "<<endl;
    cout<<"                       \ \ , ` \   \ \  __ \   \ \ \ \ \  \ \  __ \   \ \ \  __  \ \  _\L  "<<endl;
    cout<<"                        \ \ \`\ \   \ \ \/\ \   \ \ \_/ \  \ \ \/\ \   \ \ \L\ \  \ \ \L\ \"<<endl;
    cout<<"                         \ \_\ \_\   \ \_\ \_\   \ `\___/   \ \_\ \_\   \ \____/   \ \____/"<<endl;
    cout<<"                          \/_/\/_/    \/_/\/_/    `\/__/     \/_/\/_/    \/___/     \/___/ "<<endl;
}

void Stampacampi {
    
    cout<<"*******************************************************\n";
    cout<<"*****************   CAMPO 1  **************************\n";
    cout<<"*******************************************************\n";
    
    cout<<"********************* \n\n";
    cout<<"   0 1 2 3 4 5 6 7\n";
    cout<<"---------------------\n";
    
    for (int x=0;x<8;x++) {
        
        cout<<x<<"| ";
        
        for(int y=0;y<8;y++){
            cout<<campo1[x][y]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    srand(time(NULL));
    
//variabili principali
    
    char campo1 [10][10]={};
    char campo2 [10][10]={};
    
   
    
//Cancella schermo
    clrscr();


    

//inizio

  
    
    
//mettere  le navi 





//generatore del campo navale



    
 
// inserimento coordinate

do {
    cout<<"\nInserire coordinata orizzontale ";
    cin>>oriz;
    if (oriz>10) {cout<<"valore fuori portata riprova.....\n";}
}
while (oriz>10); 
   
do{
    cout<<"Inserire coordinata verticale ";
    cin>>vert;
    if (vert>10){ cout<<"valore fuori portata riprova.....\n";}
    }
while (vert>10); 


if (coord[oriz][vert]==0) {
    
    if (nave1aff=0){
    cout<<"\n***************************\nNAVE 1 AFFONDATA!!!!!!!!!!!!!!!!!!!\n******************************\n";
    coord[oriz][vert]='1';
    nave1aff=1;
    }
    else {
        cout<<"\n***************************\nNAVE 1 GIA COLPITA!!!!!!!!!!!!!!!!!!!\n******************************\n";
        coord[oriz][vert]='1';
        }
}
else if (coord[oriz][vert]==15){
        if (nave2aff=0){
            cout<<"\n***************************\nNAVE 2 AFFONDATA!!!!!!!!!!!!!!!!!!!\n******************************\n";
            coord[oriz][vert]='2';
            nave2aff=1;
            }
        else {
            cout<<"\n***************************\nNAVE 2 GIA COLPITA !!!!!!!!!!!!!!!!!!!\n******************************\n";
            coord[oriz][vert]='2';
            }
    }
else if (coord[oriz][vert]==49){
    cout<<"\n***************************\nNAVE 1 GIA COLPITA\n******************************\n";
    }
else if (coord[oriz][vert]==50){
    cout<<"\n***************************\nNAVE 2 GIA COLPITA\n******************************\n";
    }  

else {
    coord[oriz][vert]=65;
    cout<<"\n***************************\nMANCATO!!!!!!\n************************************************\n";
    }

if (nave1aff==1 && nave2aff==1){
    cout<<"\n\n******************************\n************************\n\nHAI VINTO***************\n\n";
    return 0;
}




}
cout<<"\n\n************************************\n*********HAI PERSO!!!!********************\n***************************\n";
return 0;

}

