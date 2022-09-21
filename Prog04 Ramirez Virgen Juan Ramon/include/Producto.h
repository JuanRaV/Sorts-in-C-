#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<iostream>
using namespace std;

class Producto
{
    private:

        string nombre;
        float precio;
        int id;

    public:
        Producto();
        void setNombre(string);
        string getNombre();

        void setPrecio(float);
        float getPrecio();

        void setId(int);
        int getId();


    friend class node;
    friend class list;
};

#endif // PRODUCTO_H
