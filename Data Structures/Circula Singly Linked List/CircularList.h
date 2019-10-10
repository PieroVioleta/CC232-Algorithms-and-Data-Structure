#include<iostream>
using namespace std;
struct nodo{
  int dato;
  nodo *sig;
};
typedef nodo *pnodo;

class CSList{
private:
  pnodo pL;
  pnodo buscar_anterior(int x);
  pnodo buscar_posterior(int x);
public:
  CSList();
  void insertar_inicio(int x);
  void imprimir();
  void insertar_final(int x);
  pnodo buscar(int x);
  void eliminar(int x);
};

CSList::CSList() {
  pL = NULL;
}
void CSList::insertar_inicio(int x) {
  pnodo p = new nodo;
  p->dato = x;
  if(pL == NULL) {
    p->sig = p;
    pL = p;
  } else {
    pnodo q = pL;
    do{
      q = q->sig;
    } while(q->sig != pL);
    p->sig = pL;
    pL = p;
    q->sig = pL;
  }
}
void CSList::insertar_final(int x) {
  pnodo p = new nodo;
  p->dato = x;
  p->sig = pL;
  if(pL == NULL) {
    p->sig = p;
    pL = p;
  }
  else{
    pnodo q = pL;
    p->sig = pL;
    do{
      q = q->sig;
    } while(q->sig != pL);
    q->sig = p;
  }
}
void CSList::imprimir() {
  if(pL == NULL) {
    cout << "Lista Vacia " << endl;
    return;
  }
  pnodo p = pL;
  cout << "pL: ";
  do{
    cout << p->dato << " -> ";
    p = p->sig;
  } while(p != pL);
  cout << "pL" << endl;
}
pnodo CSList::buscar(int x) {
  pnodo p = pL;
  if(pL == NULL) return NULL;
  else {
    do{
      if(p->dato == x) return p;
      else p = p->sig;
    } while(p != pL);
  }
  return NULL;
}
pnodo CSList::buscar_anterior(int x) {
  if(buscar(x) == NULL) return NULL;
  else{
    pnodo p = pL;
    do{
      if((p->sig)->dato == x) return p;
      else p = p->sig;
    } while(p != pL);
  }
}
pnodo CSList::buscar_posterior(int x) {
  pnodo p = buscar(x);
  if(p == NULL) return NULL;
  else return p->sig;
}
void CSList::eliminar(int x) {
  pnodo p = buscar_anterior(x), q = buscar_posterior(x), r = buscar(x);
  if(r == NULL) cout << "El elemento no se encuentra en la lista" << endl;
  else{
    if(r != pL) {
      p->sig = q;
      delete r;
      return;
    } else {
      if(pL->sig == pL) delete r;
      else {
        p->sig = q;
        pL = pL->sig;
        delete r;
      }
    }
  }
}
