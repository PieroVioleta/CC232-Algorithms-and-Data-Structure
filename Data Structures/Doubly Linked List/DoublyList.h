#include<iostream>
using namespace std;
struct nodo{
    int dato;
    nodo *sig;
    nodo *ant;
};
typedef nodo *pnodo;
class D_list{
    private:
        pnodo pL;
        pnodo buscar_anterior(int x);
        pnodo buscar_posterior(int x);
    public:
        D_list();
        void insertar_final(int x);
        void insertar_inicio(int x);
        pnodo buscar(int x);
        void imprimir();
        void eliminar(int x);
};

D_list::D_list() {
    pL = NULL;
}
void D_list::insertar_inicio(int x) {
    pnodo p;
    p = new nodo;
    p->dato = x;
    p->sig = pL;
    p->ant = NULL;
    if(pL != NULL) {
        pL->ant = p;
    }
    pL = p;
}
void D_list::imprimir() {
    pnodo p = pL;
    if(p == NULL) cout << "Lista vacia" << endl;
    else{
        cout << "NULL <-> ";
        while(p != NULL) {
            cout << p->dato << " <-> ";
            p = p->sig;
        }
        cout << "NULL" << endl;
    }
}

void D_list::insertar_final(int x) {
    pnodo p, q = pL;
    p = new nodo;
    p->dato = x;
    p->sig = NULL;
    if(q != NULL){
        while(q -> sig != NULL) {
            q = q->sig;
        }
        p->ant = q;
        q->sig = p;
    } else {
        insertar_inicio(x);
    }
}
pnodo D_list::buscar(int x) {
    pnodo p = pL;
    if(p == NULL) cout << "Lista vacia" << endl;
    else {
        while(p != NULL) {
            if(p->dato == x) return p;
            else p = p->sig;
       }
       return NULL;
    }
}
pnodo D_list::buscar_anterior(int x){
    pnodo p = buscar(x);
    if(p == NULL) return NULL;
    else {
        return p->ant;
    }
}
pnodo D_list::buscar_posterior(int x){
    pnodo p = buscar(x);
    if(p == NULL) return NULL;
    else {
        return p->sig;
    }
}
void D_list::eliminar(int x) {
    pnodo p = buscar(x), q = buscar_anterior(x), r = buscar_posterior(x);
    if(p == NULL) cout << "El elemento no se encuentra en la lista";
    else{
        if(q != NULL && r != NULL) {
            q->sig = r;
            r->ant = q;
            delete p;
        } else if(q != NULL && r == NULL) {
            q->sig = r;
            delete p;
        } else if(q == NULL && r != NULL) {
            pL = pL->sig;
            delete p;
        } else delete p;
    }
}
