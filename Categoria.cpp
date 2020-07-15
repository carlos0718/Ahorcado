#include <iostream>
#include <cstdio>
#include <cstring>

const char *CATEGORIA = "CATEGORIA.dat";

#include "Categoria.h"

using namespace std;

void Categoria::ingresarCategoria()
{
    int id;
    char nombre[10];
    cout<<"Para terminar de ingresar nombres debe ingresar ' 0' "<<endl;
    cout<<"ID :";
    cin>>id;

    while(id !=0)
    {
        cin.ignore();
        cout<<" Nombre de Categoría : ";
        cin.getline(nombre, 10);

        setCategoria(nombre);
        guardarCategoriaEnDisco();

        cout<<"ID :";
        cin>>id;
    }
}
void Categoria::guardarCategoriaEnDisco()
{

}
void Categoria::leerCategoriaDeDisco()
{

}
