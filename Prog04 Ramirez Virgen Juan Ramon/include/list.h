#ifndef LIST_H
#define LIST_H

#include"node.h"
#include"Producto.h"

class list
{
    public:
        list();
        void addFront(Producto);
        void print();
        int tamanio();
        void burbuja();
        void selectSort();
        void insertSort();
        void quickSort(list *);
        void mergeSort(int, list *);


    private:
        node *h;
        node *t;

    friend class Producto;
    friend class node;
};

#endif // LIST_H
