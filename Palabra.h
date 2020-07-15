#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

const int CANTIDAD_VIDAS= 7;

class Palabra
{
    private:

        char palabra[30];
        int idCategoria;

    public:

        void ingresarPalabra();
        void guardarPalabraEnDisco();

        bool leerPalabraDeDisco(int);
        bool mostrarPalabraAlHazar(int, Palabra * );
        bool contarLetras(char *);
        bool adivinarLetra(char *,int);
        void ingresarLetra(int, int &, int &, char *p);


        bool leerPalabraDeDisco_2(int, int);
        bool mostrarPalabraAlHazar_2(int, Palabra *, int );
        bool contarLetras_2(char *, int);
        bool adivinarLetra_2(char *,int, int);
        void ingresarLetra_2(int, int &, int &, char *p, int);

        void setPalabra(const char *pal) { strcpy(palabra,pal);}
        char *getPalabra(){ return palabra; }

        void setCategoria(int id) {idCategoria=id; }
        int getCategoria(){ return idCategoria; }
};
#endif // LISTA_H_INCLUDED
