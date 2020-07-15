#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <windows.h>

#include "Menu.h"
#include "Juego.h"
#include "Palabra.h"
#include "Jugador.h"

using namespace std;
void puntajeTotal(int );
/******************************************/
/**OPCIONES DE  LOS MENÚS ********/
/******************************************/
int opcion(const char *titulo,char opciones[][20], int n)
{
    int op=1;
    int tecla;
    bool repite = true;

    while(repite)
    {
        gotoxy(3,1);cout<<"\t =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        gotoxy(15,2); cout<<titulo;
        gotoxy(5,3+op);cout << " ->";
        gotoxy(3,4+n);cout<<"\t =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        for(int i=0; i<n;i++)
         {
             gotoxy(10,4+i);cout <<i+1<<".-"<<opciones[i]; ///muestra nosmbres de las opciones
         }
        tecla=getch();
        while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER)
         {
             tecla=getch();
         }
        switch (tecla)
        {
            case TECLA_ARRIBA:
            {
                op--;
                if(op<1)
                    op=n;
            }break;
             case TECLA_ABAJO:
            {
                op++;
                if(op>n)
                    op=1;
            }break;
             case ENTER:
            {
                repite = false;
            }break;
        }
        system("cls");
    }
    return op;
}
/*************************************/
/*********MENU PRINCUPAL*********/
/*************************************/
void menu()
{
    ocultarCursor();
    const char *titulo = "A  L A  H O R C A ";
    char opciones[][20] = {" Player "," Multiplayer ", " Ranking "," Salir "};
    int n= 4;
    int op;
    bool salir = false;
    while(!salir)
   {
        op=opcion(titulo,opciones, n);
        system("cls");
        switch(op)
        {
            case 1:
            {
                system("cls");
                Juego x;
                x.iniciarUnJugador();

            }break;
            case 2:
            {
                system("cls");
                Juego x;
                x.iniciarMultijugador();

            }break;
            case 3:
            {
                system("cls");
                Jugador j;
                j.leerNombreYPuntajeDeDisco();
                cin.ignore();
            }break;
            case 4:
            {
                salir=true;
            }break;
        }
        system("cls");
    }
}
/**********************************************************/
/*********MENU DE CATEGORIAS DE PALABRAS*********/
/********************************************************/
void menuCategorias(int &a)
{
    Palabra p;
    int puntaje;
    ocultarCursor();
    const char *titulo = " C A T E G O R Í A S ";
    char opciones[][20] = {" Paises "," Ciudades ", " Colores "," Animales "," Frutas  y Verduras", " Electrodomésticos ", " Peliculas y Series", " Salir "};
    int n= 8;///cantidad de opciones para seleccionar.
    int op;
    bool salir = false;
    while(!salir)
   {
        op=opcion(titulo,opciones, n);
        system("cls");
        if(op==8)
                salir=true;
        else
         {
             cout<<"\t   ADIVINA LA PALABRA. CADA LINEA REPRESANTA UNA LETRA :"<<endl;
             cout<<"\t";
             cout<<endl;
             int i=0;
             while(i<5)
             {
                 cout <<"\t "<< i +1<<"° "<<" PALBARA"<<endl;
                 if(p.leerPalabraDeDisco(op))
                    a++;///cuenta cuantas palabras fueron adiviandas por el jugador.
                 system("cls");
                 i++;
             }
            puntajeTotal(a);
            cin.ignore();
         }
        system("cls");
    }
}
/*void menuCategorias_2()
{
    Palabra p;
    ocultarCursor();
    const char *titulo = " C A T E G O R Í A S ";
    char opciones[][20] = {" Paises "," Ciudades ", " Colores "," Animales "," Frutas  y Verduras", " Electrodomésticos ", " Peliculas y Series", " Salir "};
    int n= 8;///cantidad de opciones para seleccionar.
    int op;
    int a=0;///cuenta cuantas palabras fueron adiviandas por el jugador.
    bool salir = false;
    while(!salir)
   {
        op=opcion(titulo,opciones, n);
        system("cls");
        if(op==8)
                salir=true;
        else
         {
             cout<<"\t   ADIVINA LA PALABRA. CADA LINEA REPRESANTA UNA LETRA :"<<endl;
             cout<<"\t";
             cout<<endl;
             int i=0;
             while(i<5 )
             {
                 cout <<"\t "<< i +1<<"° "<<" PALBARA"<<endl;
                 if(p.leerPalabraDeDisco(op))
                    a++;
                 system("cls");
                 i++;
             }
            cin.ignore();
         }
        system("cls");
    }
}*/
void gotoxy(int x, int y)
{
   HANDLE hCon;
   hCon = GetStdHandle(STD_OUTPUT_HANDLE);

   COORD dwPos;
   dwPos.X=x;
   dwPos.Y=y;
   SetConsoleCursorPosition(hCon,dwPos);
}

/*char getch1()
{
    char c=0;
    DWORD modo, contador;
    HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

    SetConsoleMode(h,modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));
    ReadConsoleA(h,&c,1,&contador,NULL);

    if(c==0)
        ReadConsoleA(h,&c,1,&contador,NULL);
    SetConsoleMode(h,modo);

    return c;
}*/
void ocultarCursor()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 50;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);

}

/*void inicia_allegro(int ANCHO_ , int ALTO_){
   allegro_init();
   install_keyboard();

   set_color_depth(32);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO_, ALTO_, 0, 0);
}
int inicia_audio(int izquierda, int derecha){
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }

	set_volume(izquierda, derecha);
    return 0;
}

void menu()
{
   inicia_allegro(500,500);
    inicia_audio(70,70);
    install_mouse();

    BITMAP *cursor=load_bitmap("cursor.bmp",NULL);
    BITMAP *buffer= create_bitmap(500,500);
    BITMAP *fondo1=load_bitmap("menu1.bmp",NULL);
    BITMAP *fondo2=load_bitmap("menu2.bmp",NULL);
    BITMAP *fondo3=load_bitmap("menu3.bmp",NULL);

    bool salida=false;

    while(!salida)
    {
        if(mouse_x >300 && mouse_x<430 && mouse_y>240 && mouse_y<275 )
        {
            blit(fondo2,buffer,0,0,0,0,550,550);
            if(mouse_b & 1)
                salida=true;
        }
        else if(mouse_x>302 && mouse_x<405 && mouse_y>295 && mouse_y<330)
        {
                blit(fondo3,buffer,0,0,0,0,550,550);
                if(mouse_b & 1) salida=true;
        }
        else
            blit(fondo1,buffer,0,0,0,0,550,550);
        masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
        blit(buffer,screen,0,0,0,0,550,550);
    }
    destroy_bitmap(buffer);

}
//END_OF_MAIN();*/
