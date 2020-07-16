#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>


const char *PALABRA = "PALABRA.dat";


#include "Palabra.h"
int cantidadParticipantes();

using namespace std;

void gotoxy(int x, int y);
bool verificar(int *vec,int pos, int j);
int puntajeParcial(int );
void puntajeTotal(int , int, int);

void Palabra::ingresarPalabra()
{
    int id=0;
    char pal[30];
    cout<<"Para terminar de ingresar nombres debe ingresar ' 0 ' "<<endl;
    cout<<"id: ";
    cin>>id;

    while(id!=0)
    {
        cin.ignore();
        setCategoria(id);
        cout<<"palabra: ";
        cin.getline(pal,30);
        setPalabra(pal);
        guardarPalabraEnDisco();
        cout<<"id: ";
        cin>>id;
    }
}

void Palabra::guardarPalabraEnDisco()
{
    FILE *p;
    p=fopen(PALABRA,"ab");
    if(p==NULL) return;

    fwrite(this,sizeof(Palabra),1,p);
    fclose(p);
}
bool Palabra::leerPalabraDeDisco(int id)
{
    Palabra aux[300];
    int tam;
    int cont=0;
    FILE *p;
    p=fopen(PALABRA,"rb");
    if(p==NULL) return false;
    while(fread(this,sizeof(Palabra),1,p))
    {
        /* Lee sólo las palabras de la categoria "id" */
        if(getCategoria()==id )
        {
            /* guarda en vector Palabra las palabras de esa categoria*/
            aux[cont].setPalabra(getPalabra());
            cont++;//cuenta la cantidad de palabras que hay con ese "id"
        }
    }
    tam=cont;
    //for(int j=0;j<tam;j++)
        //cout<<"palabra: "<<aux[j].getPalabra()<<endl;
    if(mostrarPalabraAlHazar(tam,aux))
    {
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}
bool Palabra::mostrarPalabraAlHazar(int tam, Palabra *aux)
{
    int j;
    int vec[tam];
    srand(time(NULL));
    int i;
    for(i=0;i<tam;i++)
    {
        j=rand() % tam;
        while(verificar(vec, i, j))
            j=rand() % tam;
        vec[i]=j;
        //cout<<"La palabra al hazar es: "<<endl;
        cout<<endl;
        //cout<<aux[vec[i]].getPalabra();
        cout<<endl;
        if(contarLetras(aux[vec[i]].getPalabra()))
            return true;
        return false;
    }
}
bool Palabra::contarLetras(char *p)
{
    int tam=strlen(p);
    int n=0;
    cout<<endl;
    //cout<<p<<endl;
    int i=0;
     gotoxy(8,6);
    while(i<tam)
    {
        if(p[i] != ' ')
            cout<<"_ ";
        else
        {
            cout <<"- ";
             n++;
        }
        i++;
    }
    //cout<<tse<<endl;
    if(adivinarLetra(p,tam))
        return true;
    return false;
}

bool Palabra::adivinarLetra(char *p, int tam)
{
    int c = CANTIDAD_VIDAS;
    int i=0;
    gotoxy(10,10);cout<<"letras erradas: ";
    //cout<<tam;
    ingresarLetra(tam, c,i, p);

    if(i==tam)
    {
        gotoxy(9,12);
        cout<<" FELICITACIONES ! ! ! "<<endl;
        cin.get();
        cin.ignore();
        return true;
    }
    if(c >= 0 )
    {
        gotoxy(9,12);
        cout<<" PERDISTE ! ! ! "<<endl;
        cin.get();
        cin.ignore();
        return false;
    }
}///Esta funcion se encarga de llevar la cuenta de las vidas y de las letras acertadas.
///Al tener que usar la variable de vidas "c" y la de letras " i ", y seguir usandolas fuera de esat funcion
///es por ello que se pasan las variables por referencia.
void Palabra::ingresarLetra(int tam, int &c,int &i, char *p)
{
    char letra;
    char aux[tam];
    for(int j=0;j<tam;j++)
        aux[j]=' ';
    int m=0,pos=0;
    //este ciclo cuenta los espacios si la palabra es compuesta, y sumarlo a las letras ingresadas.
    for(int j=0;j<tam;j++)
    {
        if(p[j]==' ')
            i++;
    }
    //iteracion de la cantidad de oportunidad que tiene cada jugador o hasta completar la palabra.
    while(c>0 && i<tam)
    {
        bool existe=false;
        //va imprimiendo en tiempo real la cantidad de vidas que le va quedando en cada palabra.
        gotoxy(25,4);cout<<" VIDAS : "<< c;

        gotoxy(3,3);cout<<"-> ";
        cin>>letra;

        //TOLOWER para convertir cada letra a minisculas, y no sea key sensitive.
        letra=tolower(letra);
        gotoxy(5,3);cout<<"  ";

        for(int j=0;j<tam;j++)
        {
            if(aux[j]==letra)
                existe=true;
        }
        //esta bandera se pone en cero por cada pedido de letra que se hace
        //si llega al final en cero es por que letra no existe en el palabra.
        int ban=0;

        //recorre la palabra para comparar con la letra ingresada e imprimre las veces que existe esa letra.
        if(existe==false)
        {
            for(int j=0; j<tam; j++)
            {
                if(letra==p[j])
                {
                    gotoxy(8+(j*2),6);
                    cout<<p[j];
                    ban++;
                    i++;
                    aux[pos]=letra;
                    pos++;
                }
            }

        }
        //acá se imprime cada letra errada
        if(ban==0&&existe==false)
        {
            gotoxy(25+(m*2),10);
            cout<<letra;
            c--;
            m++;
        }
    }
}

//FUNCIONES PARA OPCION MULTIJUGADOR

bool Palabra::leerPalabraDeDisco_2(int id, int cantidad_jugadores)
{
    Palabra aux[300];
    int tam;
    int cont=0;
    FILE *p;
    p=fopen(PALABRA,"rb");
    if(p==NULL) return false;
    while(fread(this,sizeof(Palabra),1,p))
    {
        /* Lee sólo las palabras de la categoria "id" */
        if(getCategoria()==id )
        {
            /* guarda en vector Palabra las palabras de esa categoria*/
            aux[cont].setPalabra(getPalabra());
            cont++;//cuenta la cantidad de palabras que hay con ese "id"
        }
    }
    tam=cont;
    //for(int j=0;j<tam;j++)
        //cout<<"palabra: "<<aux[j].getPalabra()<<endl;
    if(mostrarPalabraAlHazar_2(tam,aux, cantidad_jugadores))
    {
        fclose(p);
        return true;
    }
    fclose(p);
    return true;
}
bool Palabra::mostrarPalabraAlHazar_2(int tam, Palabra *aux, int cantidad_jugadores)
{
    int j;
    int vec[tam];
    srand(time(NULL));
    int i;
    for(i=0;i<tam;i++)
    {
        j=rand() % tam;
        while(verificar(vec, i, j))
            j=rand() % tam;
        vec[i]=j;
        //cout<<"La palabra al hazar es: "<<endl;
        cout<<endl;
        //cout<<aux[vec[i]].getPalabra();
        cout<<endl;
        if(contarLetras_2(aux[vec[i]].getPalabra(),cantidad_jugadores))
            return true;
        return false;
    }
}
bool Palabra::contarLetras_2(char *p, int cantidad_jugadores)
{
    int tam=strlen(p);
    int n=0;
    cout<<endl;
    //cout<<p<<endl;
    int i=0;
     gotoxy(8,6);
    while(i<tam)
    {
        if(p[i] != ' ')
            cout<<"_ ";
        else
        {
            cout <<"- ";
             n++;
        }
        i++;
    }

    if(adivinarLetra_2(p,tam,cantidad_jugadores))
        return true;
    return false;
}

bool Palabra::adivinarLetra_2(char *p, int tam, int cantidad_jugadores)
{
    //" c" es la cantidad de vidas que se pasa por referencia en la funcio
    // ingresarLetras()
    int c = CANTIDAD_VIDAS;

    // " i " es el contador de letras que se pasa por referencia en la funcion
    // ingresarLetra();
    int i=0;

    //en esta posición se imprime las letras erradas
    gotoxy(10,10);cout<<"letras erradas: ";
    //cout<<tam;

    ingresarLetra_2(tam,c, i,p,cantidad_jugadores);

    //esta condicion es validad siempre y cuando la cantidad de letras acertadas
    //es igual al tamaño de la palabra y no haya acabado sus vidas
    // y retorna TRUE para que sea contada como palabra adivinada.
    if(i==tam )
    {
        gotoxy(9,12);
        cout<<" FELICITACIONES ! ! ! "<<endl;
        cin.get();
        cin.ignore();
        return true;
    }
    //esta codicion es verdadera siempre y cuando la cantidad de vidas es cero y
    //no haya completado la palabra.
    //retorna FALSE para que no sea contada la palabra al momento del puntaje.
    if(c == 0 )
    {
        gotoxy(9,12);
        cout<<" PERDISTE ! ! ! "<<endl;
        cin.get();
        cin.ignore();
        return false;
    }
}
void Palabra::ingresarLetra_2(int tam, int &c,int &i, char *p,int cantidad_jugadores)
{
    char letra;
    int m=0,pos=0, cont=0;
    char aux[tam];
    for(int j=0;j<tam;j++)
        aux[j]=' ';

    int *vec;
    vec =new int[cantidad_jugadores];
    int jugador=1;
    for(int j=0;j<tam;j++)
    {
        if(p[j]==' ')
            i++;
    }
    for(int j=0;j<cantidad_jugadores;j++)
        vec[j]=c;

    for(int j=0; j<cantidad_jugadores; j++)
    {
        gotoxy(13+(j*20),4);
        cout<<" VIDAS J"<<j +1<<": "<< vec[j];
    }
    gotoxy(25,13);cout<<" TURNO DEL JUGADOR "<<jugador;

    //iteracion de la cantidad de oportunidad que tiene cada jugador o hasta completar la palabra.
    while( i<tam)
    {
        while(vec[jugador -1]>0)
        {
            bool existe=false;
            gotoxy(3,3);
            cout<<"-> ";
            cin>>letra;
            //TOLOWER para convertir cada letra a minisculas, y no sea key sensitive.
            letra=tolower(letra);
            gotoxy(5,3);
            cout<<"  ";
            for(int j=0;j<tam;j++)
            {
                if(aux[j]==letra)
                    existe=true;
            }
            //esta bandera se pone en cero por cada pedido de letra que se hace
            //si llega al final en cero es por que letra no existe en el palabra.
            int ban=0;
            if(existe==false)
            {
                //recorre la palabra para comparar con la letra ingresada e imprimre las veces que existe esa letra.
                for(int j=0; j<tam; j++)
                {
                    if(letra==p[j])
                    {
                        gotoxy(8+(j*2),6);
                        cout<<p[j];
                        ban++;
                        i++;
                        aux[pos]=letra;
                        pos++;
                    }
                }
            }
            //acá se imprime cada letra errada
            if(ban==0&&existe==false)
            {
                vec[jugador-1]=c--;
                //va imprimiendo en tiempo real la cantidad de vidas que le va quedando en cada palabra.
                /*for(int j=0; j<cantidad_jugadores; j++)
                {
                    gotoxy(13+(j*20),4);
                    cout<<" VIDAS J"<<j+1<<": "<< vec[j];
                }*/
                int j=jugador-1;
                gotoxy(13+(j*20),4);
                cout<<" VIDAS J"<<jugador<<": "<< vec[jugador-1];
                if(jugador==cantidad_jugadores)
                {
                    jugador=jugador - cont;
                    gotoxy(25,13);cout<<" TURNO DEL JUGADOR "<<jugador;
                }
                else
                {
                    cont++;
                    jugador =jugador+1;
                    gotoxy(25,13);cout<<" TURNO DEL JUGADOR "<<jugador;
                }
                gotoxy(25+(m*2),10);
                cout<<letra;
                m++;//variable para aumentar la separacion entre letras.
            }
        }
    }
    delete(vec);
}
