// Verifica se il file header è già stato incluso
#ifndef LIBRERIE_H
#define LIBRERIE_H
#define N 9
// Dichiarazione delle funzioni per l'uso in altri file

void pulisci();
void premi();
void inizializzacampo(char campo[N][N]);
void scritta();
void stampacampo(char campo1[N][N],char campo2[N][N]);
bool inseriscinave(char campo[N][N],char coord[2],int orient,int lun,int numnave);
void spara(char campo[N][N],char coord[2],int navecolpita[5]);
void tabellanavi(int navicolpite1[6],int navicolpite2[6]);


#endif // Fine del controllo di inclusione CALCOLI_H
