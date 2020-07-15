#ifndef NOMBRESAUX_H_INCLUDED
#define NOMBRESAUX_H_INCLUDED

class NombresAux
{
    private:
        char nombre[20];
    public:
        void setNombreAux(const char n[20]){ strcpy(nombre,n);}
        const char *getNombreAux(){ return nombre;}

        void guardarEnDisco();
        void leerDeDisco(int);
        int contarNombres();

        void mostrarNombreAux();

};
#endif // NOMBRESAUX_H_INCLUDED
