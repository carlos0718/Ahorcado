#include <iostream>
#include <cstdlib>
#include <clocale>
#include <cstring>

#include "Juego.h"
#include "Jugador.h"
#include "Funciones.h"
#include "Menu.h"
#include "Palabra.h"
#include "Categoria.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"spanish");

   Juego x;
   x.iniciarJuego();
   Palabra p;
    //p.ingresarPalabra();
    //p.leerPalabraDeDisco(4);
    cin.ignore();
    return 0;
}
