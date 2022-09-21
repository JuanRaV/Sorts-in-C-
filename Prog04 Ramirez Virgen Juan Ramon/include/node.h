#ifndef NODE_H
#define NODE_H
#include "Producto.h"


class node
{
    public:
        node();
        node(Producto p){
            producto=p;
            sig=nullptr;
            ant=nullptr;
        }

    private:
        Producto producto;
        node *sig;
        node *ant;

    friend class Producto;
    friend class list;
};

#endif // NODE_H
