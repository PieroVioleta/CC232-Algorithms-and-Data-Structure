#include<iostream>
#include "Stack.h"
using namespace std;
int main() {
    Stack pila1;
    int opcion = -1;
    while(opcion != 0) {
        cout << "\nMENU:\n1.- Imprimir\n2.- Apilar\n3.- Desapilar\n4.- Peek\n5.- Verificar si esta vacio\n0.- Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;
        cout << endl;
        if(opcion == 1) {
            pila1.imprimir();
        } else if(opcion == 2) {
            int x;
            cout << "Ingrese el dato que quiera apilar: ";
            cin >> x;
            pila1.push(x);
        } else if(opcion == 3) {
            pila1.pop();
        } else if(opcion == 4) {
            if(pila1.isEmpty()) cout << "Pila vacia" << endl;
            else cout << "El ultimo elemento apilado es: " << pila1.peek() << endl;
        } else if(opcion == 5) {
            if(pila1.isEmpty()) cout << "Pila vacia" << endl;
            else cout << "No esta vacia " << endl;
        }
    }
    return 0;
}
