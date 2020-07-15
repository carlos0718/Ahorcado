#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

class Categoria
{
    private:
        int id;
        char categoria[10];

    public:
        void ingresarCategoria();
        void guardarCategoriaEnDisco();
        void leerCategoriaDeDisco();

        void setId(int id) { this->id = id;}
        int getId(){ return id;}

        void setCategoria(char nombreCategoria[10]) { strcpy(categoria,nombreCategoria);}
        char *getCategoria(){ return categoria; }
};


#endif // CATEGORIA_H_INCLUDED
