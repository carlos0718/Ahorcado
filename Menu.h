#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define  TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

void opcion(const char *titulo,char *opciones[], int n);

void menu();

void gotoxy(int x, int y);

char getch1();

void ocultarCursor();

void menuCategorias(int &);

void menuCategorias_2();

#endif // MENU_H_INCLUDED
