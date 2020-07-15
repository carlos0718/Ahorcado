#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

class Juego
{
    private:

        //participante;
        int cantidad;
        int idCategoria;

    public:

        void iniciarJuego();
        void iniciarUnJugador();
        void iniciarMultijugador();
        int ingresarCategoria();

        void setCantidad(int c){ cantidad=c;}
        int getCantidad(){return cantidad;}
};

#endif // JUEGO_H_INCLUDED
