#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "Jugador.h"
#include "Juego.h"
#include "Funciones.h"
#include "NombresAux.h"

using namespace std;

const int PUNTOS_TOTALES = 250;
const int PUNTOS_POR_PALABRA = 50;

void gotoxy(int , int);

void puntajeTotal(int a)
{
    cout<<"\n\n\t  PUNTOS GANADOS EN LA RONDA ";
    for(int i=0;i<5;i++)
    {
        if(a==i)
        {
            gotoxy(4,20);
            cout<<"PUNTAJE TOTAL:  "<< a * 50 << " pts"<<endl;
            return;
        }
    }
    if(a==5)
    {
         gotoxy(4,20);
        /*PUNTAJE DE 300 AL QUE ADIVINA SIN ERRAR NI UNA LETRA EN TODA LA RONDA*/
        cout<<"PUNTAJE TOTAL:  "<< PUNTOS_TOTALES + 50<<endl;
        return;
    }
}

int cantidadParticipantes()
{
    int c;
    cin>>c;
     if(c<2 || c>4)
    {
        system("cls");
        cout<<" [ Esta partida permite 2 jugadores como mínimo y 4 como máximo]"<<endl;
        cout<<" INGRESE LA CANTIDAD DE PARTICIPANTES: ";
        cin>>c;
    }
    return c;
}
/***** FUNCION QUE PIDE EL INGRESO DE CADA PARTICIPANTE*****/
void ingresarParticipantes(Jugador *g, int tam)
{
    cin.ignore();
    for(int i=0;i<tam;i++)
    {
        g[i].ingresarNombre();
    }
}
void mostrarParticipantes(Jugador *g, int tam)
{
    system("cls");

    banner();
    turnoDeParticipantes(g, tam);

}

void turnoDeParticipantes(Jugador *g, int tam)
{
    NombresAux aux;
    int j;
    int *vec = new int[tam];
    srand(time(NULL));

    for(int i=0;i<tam;i++)
    {
        j=rand() % tam;
        while(verificar(vec, i, j))
            j=rand() % tam;
        vec[i]=j;

    }
    for(int i=0;i<tam;i++)
    {
        cout<<"\t\tPLAYER "<<i+1<<":";
        cout<<g[vec[i]].getNombre();
        aux.setNombreAux(g[vec[i]].getNombre());
        aux.guardarEnDisco();
        cout<<endl;
    }
    delete(vec);
}

bool verificar(int *vec,int pos, int j)
{
    for(int i=0; i < pos;i++)
    {
        if(vec[i]== j) return true;
    }
    return false;
}

/*void mostrarNombre(char vec_nombres, tam)
{

}*/

void banner()
{
    cout<<" \t B I E N V E N I D O   A L   J U E G O,  Y A   N O   P U E D E S   E S C A P A R"<<endl<<endl;
    cout<<" \t      A D I V I N A   L A S   P A L A B R A S   Y   T E   S A L V A R Á S,"<<endl<<endl;
    cout <<" \t               S I N O   T E   I R Á S   A   L A   H O R C A"<<endl<<endl;
}

/**FUNCIONES PARA GUARDAR Y LEER PARTICIPANTES EN DISCO Y ****/

void guardarParticipantesEnDisco(Jugador *g, int tam)
{
    cin.ignore();
    for(int i=0;i<tam;i++)
    {
        g[i].ingresarNombre();
        g[i].guardarNombreYPuntajeEnDisco();
    }
}

void leerParticipantesDeDisco(Jugador *g, int tam)
{
    system("cls");

    banner();
    for(int i=0;i<tam;i++)
    {
        g[i].leerNombreYPuntajeDeDisco();
    }
}
