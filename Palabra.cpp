#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>


const char *PALABRA = "PALABRA.dat";


#include "Palabra.h"

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
    int tse;//tamaño sin espacio
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
    tse=tam-n;
    //cout<<tse<<endl;
    if(adivinarLetra(p,tam,tse))
        return true;
    return false;
}

bool Palabra::adivinarLetra(char *p, int tam,int tse)
{
    int c = CANTIDAD_VIDAS;
    int i=0, x=0, ban2=0;
    gotoxy(10,10);cout<<"letras erradas: ";
    //cout<<tam;
    ingresarLetra(tam,tse, c,i, p);

    if(i==tam)
    {
        //ban2=1;///esta bandera indica que al menos adivinó una palabra aunque halla terminado con todas sus vidas.
        gotoxy(9,12);
        cout<<" FELICITACIONES ! ! ! "<<endl;
        //x++;///solo para verificar las 5 veces de la función palabra y para usarlo en la funcion de puntajeTatal
        cin.get();
        cin.ignore();
        return true;
    }
    if(c >= 0 )//&& ban2 == 0 )
    {
        gotoxy(9,12);
        cout<<" PERDISTE ! ! ! "<<endl;
        cin.get();
        cin.ignore();
        x++;
        return false;
    }
}
bool Palabra::leerPalabraDeDisco_2(int id)
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
    if(mostrarPalabraAlHazar_2(tam,aux))
    {
        fclose(p);
        return true;
    }
    fclose(p);
    return true;
}
bool Palabra::mostrarPalabraAlHazar_2(int tam, Palabra *aux)
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
        if(contarLetras_2(aux[vec[i]].getPalabra()))
            return true;
        return false;
    }
}
bool Palabra::contarLetras_2(char *p)
{
    int tam=strlen(p);
    int tse;//tamaño sin espacio
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
    tse=tam-n;//no va
    //cout<<tse<<endl;
    if(adivinarLetra_2(p,tam,tse))
        return true;
    return false;
}

bool Palabra::adivinarLetra_2(char *p, int tam,int tse)
{
    int c = CANTIDAD_VIDAS;
    int i=0, x=0, ban2=0;
    gotoxy(10,10);cout<<"letras erradas: ";
    //cout<<tam;
    ingresarLetra(tam,tse,c, i,p);
    if(i==tam )
    {
        //ban2=1;///esta bandera indica que al menos adivinó una palabra aunque halla terminado con todas sus vidas.
        gotoxy(9,12);
        cout<<" FELICITACIONES ! ! ! "<<endl;
        //x++;///solo para verificar las 5 veces de la función palabra y para usarlo en la funcion de puntajeTatal
        cin.get();
        cin.ignore();
        return true;
    }
    if(c >= 0 )//&& ban2 == 0 )
    {
        gotoxy(9,12);
        cout<<" PERDISTE ! ! ! "<<endl;
        cin.get();
        cin.ignore();
        x++;
        return false;
    }
}
void Palabra::ingresarLetra(int tam,int tse, int &c,int &i, char *p)
{
    char letra;
    int m=0;
    for(int j=0;j<tam;j++)
    {
        if(p[j]==' ')
            i++;
    }
    while(c>0 && i<tam)//iteracion de la cantidad de oportunidad que tiene cada jugador o hasta completar la palabra.
    {
        //char corazon;
        gotoxy(25,4);cout<<" VIDAS : "<< c;
        gotoxy(3,3);cout<<"-> ";
        cin>>letra;
        //TOLOWER para convertir cada letra a minisculas, y no sea key sensitive.
        letra=tolower(letra);
        gotoxy(5,3);cout<<"  ";
        int ban=0;
        for(int j=0; j<tam; j++) //recorre la palabra para comparar con la letra ingresada e imprimre las veces que existe esa letra.
        {
            if(letra==p[j])
            {
                gotoxy(8+(j*2),6);
                cout<<p[j];
                ban++;
                i++;
            }
        }
        if(ban==0)//acá se imprime cada letra errada
        {
            gotoxy(25+(m*2),10);
            cout<<letra;
            c--;
            m++;
        }
    }
}
