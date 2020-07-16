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
    cout<<"\n\t ADIVINA LAS 5 PALABRAS DE ESTA RONDA PARA ALCANZAR EL PUNTAJE MÁXIMO DE 300 ptos "<<endl;
    cout<<"\t\t\tPONE A PRUEBA TUS CONOCIMIENTOS ! ! !  "<<endl;
    g.ingresarNombre();
    system("cls");
    g.mostrarNombre();
    cin.ignore();
    system("cls");
    cout<<"\t   Selecciona la categoria para empezar a jugar"<<endl;
    menuCategorias(a);
    int r= a*50;
    g.setPuntaje(r);
    g.guardarNombreYPuntajeEnDisco();

 }

void Juego::iniciarMultijugador()
{
    Jugador *g;
    int tam;
    int a=0;
    cout<<"INGRESE LA CANTIDAD DE PARTICIPANTES: ";
    tam=cantidadParticipantes();
    setCantidad(tam);
    //tam = getCantidad();
    g=new Jugador[tam];
    if(g==NULL) return;
    ingresarParticipantes(g, tam);
    mostrarParticipantes(g,tam);
    cout<<"\n\t   El  primer jugador selecciona la categoria para empezar a jugar"<<endl;
    cin.ignore();
    system("cls");
    menuCategorias_2(a,tam);



    delete(g);
}
