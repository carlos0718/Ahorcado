#include <iostream>
#include <cstdio>
#include <cstring>

#include "Jugador.h"
#include "Menu.h"
#include "Juego.h"
#include "Funciones.h"
#include "Palabra.h"

using namespace std;

void Juego::iniciarJuego()
{
    menu();
}
 void Juego::iniciarUnJugador()
 {
    Jugador g;
    int a =0;///cuenta cuantas palabras fueron adiviandas por el jugador.
    g.ingresarNombre();
    system("cls");
    g.mostrarNombre();
    cin.ignore();
    system("cls");
    cout<<"\t   Selecciona la categoria para empezar a jugar"<<endl;
    menuCategorias(a);
    g.setPuntaje(a*50);
    g.guardarNombreYPuntajeEnDisco();

 }

void Juego::iniciarMultijugador()
{
    Jugador *g;
    Palabra p;
    int tam;
    int a=0;
    tam=cantidadParticipantes();
    setCantidad(tam);

    tam = getCantidad();
    g=new Jugador[tam];
    if(g==NULL) return;
    ingresarParticipantes(g, tam);
    mostrarParticipantes(g,tam);
    cout<<"\t   El  primer jugador selecciona la categoria para empezar a jugar"<<endl;
    cin.ignore();
    system("cls");
    menuCategorias(a);



    delete(g);
}
