#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>

#include "Jugador.h"
#include "Funciones.h"

const char *JUGADOR ="JUGADOR.dat";

using namespace std;

bool Jugador::validarNombre(char *n, int tam)
{
    int ban=0;
    for(int i=0;i<tam;i++)
    {
        if(n[i]==' ')
            ban++;
    }
    if(ban==tam)
        return true;
    return false;
}

 void Jugador::ingresarNombre()
{
    char n[20];
    cout<<"\t NOMBRE : ";
    cin.getline(n,20);
    int tam=strlen(n);
    //cout<<tam<<endl;

    while(validarNombre(n,tam))
    {
        system("cls");
        cout<<"\t NOMBRE : ";
        cin.getline(n,20);
        //tam=strlen(n);
    }
    setNombre(n);
    setPuntaje(0);
    guardarNombreYPuntajeEnDisco();
}
/**FUNCIONES DE GUARDAR Y LEER DE DISCO SE DEBE IMPLEMENTAR**
 **AL MOMENTO DE REGISTRAR LOS PUNTAJES DE CADA JUGADOR**
 **AL TÉRMINO DEL JUEGO*/

bool Jugador::guardarNombreYPuntajeEnDisco()
{
    FILE *p;
    p=fopen(JUGADOR,"ab");
    if(p==NULL)
        return false;
    fwrite(this,sizeof(Jugador),1,p);
    fclose(p);
    return true;
}
void Jugador::leerNombreYPuntajeDeDisco()
{
    FILE *p;
    p=fopen(JUGADOR, "rb");
    if(p==NULL)
    {
          cout<<"Error: Archivo no existe"<<endl;
          return;
    }
    cout<<"\t\t   R A N K I N G "<<endl;
    while(fread(this,sizeof(Jugador),1,p))
        mostrarNombreYPuntaje();
    fclose(p);
    return;
}

void Jugador::mostrarNombreYPuntaje()
{
    cout<<"\n\t"<<"  "<<getNombre()<<"\t\t "<<getPunatje()<<endl;
}
void Jugador::mostrarNombre()
{
    banner();
    cout<<"\t\tNOMBRE: "<<getNombre()<<endl;

}
