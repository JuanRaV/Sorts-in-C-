#include "list.h"
#include"node.h"
#include"Producto.h"
#include<iostream>

using namespace std;
list::list()
{
    h=nullptr;
    t=nullptr;
}
void list::addFront(Producto p)
{
    node *tmp=new node(p);
    if(h==nullptr and t==nullptr){
        h=tmp;
        t=tmp;
    }else{
        tmp->sig=h;
        h->ant=tmp;
        h=h->ant;
    }
    tmp->producto.setId(tmp->producto.getId()+1);
}

void list::print()
{
    node *aux=h;
    if(!h)
        cout<<"Empty list..."<<endl;
    else{
        while(aux){
            cout<<"--------------------------------"<<endl;
            cout<<"Precio: $"<<aux->producto.getPrecio()<<"\nProducto: "<<aux->producto.getNombre()<<"\nId: "<<aux->producto.getId()<<endl;
            aux=aux->sig;
        }

    }
}

int list::tamanio()
{
    int cont=0;
    node *aux=h;
    while(aux){
        cont ++;
        aux=aux->sig;
    }
    return cont;
}
//Burbuja
void list::burbuja(){
    node *aux=h;
    bool band=true;
    int tmp=0,i=0,j=0;
    int tam=tamanio();
    int m=tam;
    while(i<m and band){
        band=false;
        aux=h;
        j=0;
        while(j<m-i-1){
            if(aux->producto.getPrecio()>aux->sig->producto.getPrecio()){
                tmp=aux->producto.getPrecio();
                aux->producto.setPrecio(aux->sig->producto.getPrecio());
                aux->sig->producto.setPrecio(tmp);
                band=true;
            }
            aux=aux->sig;
            j++;
        }
        i++;
    }
}
//InsertSort
void list::insertSort(){
    node *aux=h->sig;
    bool band;

    while(aux){
        band=true;
        float refval=aux->producto.getPrecio();
        node *refNodePrev=aux->ant;
        while(refNodePrev!=nullptr and band){
            if(refNodePrev->producto.getPrecio()<refval){
                refNodePrev->sig->producto.setPrecio(refNodePrev->producto.getPrecio());
                refNodePrev->producto.setPrecio(refval);
            }else
                band=false;
            refNodePrev=refNodePrev->ant;
        }
        aux=aux->sig;
    }
}
//Select
void list::selectSort(){
    node *aux=h;
    node *menor=h;
    node *pos=h;
    float tmp;

    while(pos){
        aux=pos;
        menor=pos;
        while(aux){
            if(menor->producto.getPrecio()>aux->producto.getPrecio())
                menor=aux;
            aux=aux->sig;
        }
        tmp=pos->producto.getPrecio();
        pos->producto.setPrecio(menor->producto.getPrecio());
        menor->producto.setPrecio(tmp);
        pos=pos->sig;
    }
}
//QuickSort
void list::quickSort(list *l){
    node *piv;
    node *pivSave;
    node *aux;

    list *upper=new list;
    list *lower = new list;

    if(l->h){
        piv=l->h;
        pivSave=new node(l->h->producto);
        aux=l->h->sig;

        while(aux){
            if(aux->producto.getPrecio()< piv->producto.getPrecio())
                lower->addFront(aux->producto);
            else
                upper->addFront(aux->producto);
            aux=aux->sig;
        }
        quickSort(lower);
        quickSort(upper);

        //Lower
        aux=l->h;
        node *low=lower->h;
        while(low){
            aux->producto.setPrecio(low->producto.getPrecio());
            aux=aux->sig;
            low=low->sig;
        }
        //Pivote
        {
            aux->producto.setPrecio(pivSave->producto.getPrecio());
            aux=aux->sig;
        }

        //Upper
        node *up=upper->h;
        while(up){
            aux->producto.setPrecio(up->producto.getPrecio());
            aux=aux->sig;
            up=up->sig;
        }
    }
}

//Merge Sort
void list::mergeSort(int tam, list *l){
    list *derecha=new list;
    list *izquierda = new list;

    node *aux=l->h;
    int med=tam/2;
    int dif=tam%2;
    int i,j;

    if(l->tamanio()>1){
        i=0;
        while(aux and i<med){
            izquierda->addFront(aux->producto);
            i++;
            aux=aux->sig;
        }
        j=0;
        while(aux and j<med+dif){
            derecha->addFront(aux->producto);
            j++;
            aux=aux->sig;
        }
        mergeSort(izquierda->tamanio(),izquierda);
        mergeSort(derecha->tamanio(),derecha);

        node *iz=izquierda->h;
        node *de= derecha->h;
        aux=l->h;
        i=0;

        while(iz and de){
            if(iz->producto.getPrecio()> de->producto.getPrecio()){
                aux->producto.setPrecio(iz->producto.getPrecio());
                iz=iz->sig;
                aux=aux->sig;
            }
            else{
                aux->producto.setPrecio(de->producto.getPrecio());
                de=de->sig;
                aux=aux->sig;
            }
        }
        if(iz){
            while(iz){
                aux->producto.setPrecio(iz->producto.getPrecio());
                iz=iz->sig;
                aux=aux->sig;
            }
        }if(de){
            while(de){
                aux->producto.setPrecio(de->producto.getPrecio());
                de=de->sig;
                aux=aux->sig;
            }
        }
    }
}

