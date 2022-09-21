#include "Producto.h"

Producto::Producto()
{
    string nombre;
    float precio;
    id=0;
}
void Producto::setNombre(string nombre)
{
    this->nombre=nombre;
}

string Producto::getNombre()
{
    return nombre;
}

void Producto::setPrecio(float precio)
{
    this->precio=precio;
}

float Producto::getPrecio()
{
    return precio;
}

void Producto::setId(int id)
{
    this->id=id;
}

int Producto::getId()
{
    return id;
}
