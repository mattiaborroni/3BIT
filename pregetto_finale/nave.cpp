
#include <iostream>
#include "nave.h"
#define N 9
using namespace std;

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
void tabellanavi(int navicolpite1[6], int navicolpite2[6])
{
    cout << "\n\t--------------------------------------------\n";
    cout << "\tGIOVATORE1\tCOLPITA\t\tGIOCATORE2\tCOLPITA\n";

    for (int i = 1; i < 6; i++)
    {
        cout << "\tNAVE " << i << "\t\t ";
        if (navicolpite1[i] == 1)
        {
            cout << "SI ";
        }
        else
        {
            cout << "NO";
        }

        cout << "\t\tNAVE " << i << "\t\t ";
        if (navicolpite2[i] == 1)
        {
            cout << "SI\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
