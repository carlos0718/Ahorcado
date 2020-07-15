#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>


const char *NOMBRE_AUX=" NOMBRE_AUX.dat";


#include "NombresAux.h"

using namespace std;

void NombresAux::guardarEnDisco()
 {
     FILE *p;
     p=fopen(NOMBRE_AUX,"wr");
     if(p==NULL) return;

     fwrite(this,sizeof(NombresAux),1,p);
     fclose(p);
 }
 void NombresAux::leerDeDisco(int pos)
 {
     FILE *p;
     p=fopen(NOMBRE_AUX,"rb");
     if(p==NULL)
        return;
     fseek(p,pos*sizeof(NombresAux),0);
     fread(this,sizeof(NombresAux),1,p);
     fclose(p);
 }
int NombresAux::contarNombres()
{
    int cont=0;
    FILE *p;
    p=fopen(NOMBRE_AUX,"rb");
    if(p==NULL) return 0;
    while(fread(this,sizeof(NombresAux),1,p))
        cont++;
    return cont;
}
