
#ifndef LISTA_H
#define LISTA_H

#include <string>

using namespace std;

struct Nodo {
    int codigo;
    string nombre;
    int cantidad;
    Nodo* siguiente;
};

struct Lista {
    Nodo* cabeza;
};

Nodo* buscar(Nodo* cabeza, int codigo);

bool agregar(Nodo*& cabeza, int codigo, const string& nombre, int cantidad);
bool agregar(Lista& lista, int codigo, const string& nombre, int cantidad);

void consultar(Nodo* cabeza, int codigo);
void consultar(Lista& lista, int codigo);

void reponer(Nodo* cabeza, int codigo, int cantidadAdicional);
void reponer(Lista& lista, int codigo, int cantidad);

void eliminar(Nodo*& cabeza, int codigo);
void eliminar(Lista& lista, int codigo);

void listar(Nodo* cabeza);
void listar(Lista& lista);

#endif
