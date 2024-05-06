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

int main()
{
    
//variabili
    srand(time(NULL));
    
    int nave1oriz=rand()%10+1;
    int nave1vert=rand()%10+1;
    int nave2oriz=rand()%10+1;
    int nave2vert=rand()%6+1;
    int nave1aff=0;
    int nave2aff=0;
    
    char coord [9][9]={{"        "},{"        "},{"        "},{"        "},{"        "},{"        "},{"        "},{"        "}};
    int oriz=0;
    int vert=0;


//Cancella schermo
    clrscr();


    

//inizio

  
    
    
//mette la prima nave


coord [nave1oriz][nave1vert]=0 ;
coord [nave1oriz+1][nave1vert]=0 ;
coord [nave1oriz][nave1vert+1]=0 ;
coord [nave1oriz+1][nave1vert+1]=0 ;

//inserire la seconda nave senza toccare la prima

while (coord[nave2oriz][nave2vert]==0 | coord[nave2oriz+1][nave2vert]==0 | coord[nave2oriz][nave2vert+1]==0 | coord[nave2oriz+1][nave2vert+1]==0){
    nave2oriz=rand()%6+1;
    nave2vert=rand()%6+1;
    }

//visualizza nave 2 sulla griglia
coord [nave2oriz][nave2vert]=15 ;
coord [nave2oriz+1][nave2vert]=15 ;
coord [nave2oriz][nave2vert+1]=15 ;
coord [nave2oriz+1][nave2vert+1]=15 ;

//generatore del campo navale

for (int t=0;t<8;t++){

    cout<<"*******************************************************\n";
    cout<<"Hai ancora "<<8-t<<" tentativi per vincere la partita\n";
    cout<<"*******************************************************\n";
    cout<<"   BATTAGLIA NAVALE \n\n";
    cout<<"********************* \n\n";
    cout<<"   0 1 2 3 4 5 6 7\n";
    cout<<"---------------------\n";
    
    for (int x=0;x<8;x++) {
        
        cout<<x<<"| ";
        
        for(int y=0;y<8;y++){
            cout<<coord[x][y]<<" ";
        }
        cout<<endl;
    }
 
// inserimento coordinate

do {
    cout<<"\nInserire coordinata orizzontale ";
    cin>>oriz;
    if (oriz>7) {cout<<"valore fuori portata riprova.....\n";}
}
while (oriz>7); 
   
do{
    cout<<"Inserire coordinata verticale ";
    cin>>vert;
    if (vert>7){ cout<<"valore fuori portata riprova.....\n";}
    }
while (vert>7); 


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

