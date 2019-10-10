#include<iostream>
using namespace std;
struct nodo {
    int dato;
    nodo *sig;
};
typedef nodo *pnodo;
class S_list{
    private:
        pnodo pL;
        pnodo buscar_anterior(int x);
        pnodo buscar_posterior(int x);
    public:
        S_list();
        void insertar_inicio(int x);
        void insertar_final(int x);
        void imprimir();
        pnodo buscar(int x);
        void eliminar(int x);
};
S_list::S_list(){
    pL = NULL;
}
void S_list::insertar_inicio(int x){
    pnodo p;
    p = new nodo;
    p->dato = x;
    p->sig = pL;
    pL = p;
}
void S_list::insertar_final(int x){
    pnodo p, q = pL;
    p = new nodo;
    p->dato = x;
    p->sig = NULL;
    if(pL == NULL) pL = p;
    else {
        while(q->sig != NULL){
            q = q->sig;
        }
        q->sig = p;
    }
}
void S_list::imprimir(){
    pnodo p;
    p = pL;
    if(p != NULL){
        while(p != NULL) {
            cout << p->dato << " -> ";
            p = (*p).sig;
        }
        cout << "NULL" << endl;
    } else cout << "Lista Vacia\n";
}
pnodo S_list::buscar(int x){
    pnodo p = pL;
    while(p != NULL) {
        if(p->dato == x) return p;
        else p = (*p).sig;
    }
    return NULL;
}
pnodo S_list::buscar_anterior(int x) {
    pnodo p = buscar(x), q = pL;
    if(p == NULL) return NULL;
    else{
        while(q != NULL){
            if(q->sig == p) {
                return q;
            } else q = q->sig;
        }
    }
}
pnodo S_list::buscar_posterior(int x){
    pnodo p = buscar(x);
    if(p == NULL) {
        return NULL;
    } else return p->sig;
}
void S_list::eliminar(int x) {
    pnodo p = buscar_anterior(x), q = buscar_posterior(x), z = buscar(x);
    if(p != NULL && q != NULL) {
        p->sig = q;
        delete z    ;
    }
}
