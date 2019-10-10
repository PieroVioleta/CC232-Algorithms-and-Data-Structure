#include<iostream>
using namespace std;
struct nodo {
    int dato;
    nodo *sig;
};

typedef nodo *pnodo;
class Stack {
private:
    pnodo head;
public:
    Stack();
    void push(int x);
    void imprimir();
    void pop();
    bool isEmpty();
    int peek();
};

Stack::Stack() {
    head = NULL;
}

void Stack::push(int x) {
    pnodo p;
    p = new nodo;
    p->dato = x;
    p->sig = head;
    head = p;
}

void Stack::imprimir() {
    pnodo p = head;
    if(p == NULL) {
        cout << "Vacio" << endl;
        return;
    }
    cout << "Head: \n";
    while(p != NULL){
        cout << "\t" << p->dato << endl;
        p = p->sig;
    }
    cout << "NULL" << endl;
}

void Stack::pop() {
    pnodo p = head;
    head = head->sig;
    delete p;
}

int Stack::peek() {
    return head->dato;
}

bool Stack::isEmpty() {
    if(head != NULL) return false;
    return true;    
}
