#include<iostream>
#include "ListSingle.h"
using namespace std;
int main() {
    S_list lista1;
    int opcion = -1;
    while(opcion != 0) {
        cout << "\nMENU:\n1.- Imprimir\n2.- Insertar inicio\n3.- Buscar\n4.- Insertar final\n5.- Eliminar\n0.- Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;
        cout << endl;
        if(opcion == 1) {
            lista1.imprimir();
        } else if(opcion == 2) {
            int x;
            cout << "Ingrese el dato que quiera insertar: ";
            cin >> x;
            lista1.insertar_inicio(x);
        } else if(opcion == 3) {
            int x;
            cout << "Ingrese el valor a buscar: ";
            cin >> x;
            if(lista1.buscar(x) != NULL) {
                cout << "Si esta\n";
            } else cout << "No esta en la lista\n";
        } else if(opcion == 4) {
            int x;
            cout << "Ingrese el dato que quiera insertar: ";
            cin >> x;
            lista1.insertar_final(x);
        } else if(opcion == 5) {
            int x;
            cout << "Ingrese el valor que quiera eliminar: ";
            cin >> x;
            lista1.eliminar(x);
        }
    }
    return 0;
}
