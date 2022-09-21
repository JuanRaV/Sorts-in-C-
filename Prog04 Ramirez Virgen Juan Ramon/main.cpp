#include <iostream>
#include <windows.h>

#include"list.h"
#include"node.h"
#include"Producto.h"

using namespace std;
void gotoxy(int x,int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
    }
int main()
{
    list *lis=new list();
    Producto p;
    int tam,id=0;
    int opc;
    float precio;
    string nombre;

    do{
        system("cls");
        cout<<"==ORDENAMIENTOS PRODUCTOS=="<<endl;
        cout<<"1.-Agregar\n2.-Imprimir\n3.-Select Sort(Ascendente)\n4.-Insert Sort(Descendente)\n5.-Quick Sort(Ascendente)\n6.-Merge Sort(Descendente)\n7.-Salir: ";cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            cout<<"Escriba el nombre del producto: ";cin>>nombre;
            p.setNombre(nombre);
            cout<<"Escriba el precio: ";cin>>precio;
            p.setPrecio(precio);
            p.setId(id);
            lis->addFront(p);
            id++;
            tam++;
            break;
        case 2:
            lis->print();
            system("pause");
            break;

        case 3:
            /*cout<<"DESORDENADO"<<endl;
            lis->print();
            cout<<endl<<endl<<endl;*/

            lis->selectSort();
            cout<<"ORDENADO"<<endl;
            lis->print();
            system("pause"); break;
        case 4:
            /*cout<<"DESORDENADO"<<endl;
            lis->print();
            cout<<endl<<endl<<endl;*/

            lis->insertSort();
            cout<<"ORDENADO"<<endl;
            lis->print();
            system("pause"); break;
        case 5:
            /*cout<<"DESORDENADO"<<endl;
            lis->print();
            cout<<endl<<endl<<endl;*/
            lis->quickSort(lis);
            cout<<"ORDENADO"<<endl;
            lis->print();
            system("pause"); break;
        case 6:
           /* cout<<"DESORDENADO"<<endl;
            lis->print();
            cout<<endl<<endl<<endl;*/
            lis->mergeSort(tam, lis);
            cout<<"ORDENADO"<<endl;
            lis->print();
            system("pause"); break;
        default:
            cout<<"Escriba opcion valida"<<endl;
            system("pause"); break;
        }

    }while(opc!=7);
    return 0;
}
