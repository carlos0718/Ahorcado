#ifndef JUEGO_H
#define JUEGO_H


class Jugador
{
    private:

        char nombre[20];
        int puntaje;

    public:
        void ingresarNombre( );
        bool guardarNombreYPuntajeEnDisco();
        void leerNombreYPuntajeDeDisco();
        void mostrarNombre();
        void mostrarNombreYPuntaje();

        bool validarNombre(char *, int);

        void setNombre(char name[20]){ strcpy(nombre, name);}
        char *getNombre(){return nombre;}

        void setPuntaje(int p){puntaje=p;}
        int getPunatje(){ return puntaje;}
};

#endif // JUEGO_H
