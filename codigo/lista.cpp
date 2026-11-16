
#include <iostream>
#include "lista.h"

using namespace std;

Nodo* buscar(Nodo* cabeza, int codigo) {
    Nodo* actual = cabeza;

    while (actual != NULL && actual->codigo != codigo) {
        actual = actual->siguiente;
    }

    return actual;
}

bool agregar(Nodo*& cabeza, int codigo, const string& nombre, int cantidad) {
    bool agregado = false;

    if (buscar(cabeza, codigo) == NULL) {
        Nodo* nuevo = new Nodo;

        nuevo->codigo = codigo;
        nuevo->nombre = nombre;
        nuevo->cantidad = cantidad;

        nuevo->siguiente = cabeza;
        cabeza = nuevo;

        agregado = true;
    }

    return agregado;
}

bool agregar(Lista& lista, int codigo, const string& nombre, int cantidad) {
    return agregar(lista.cabeza, codigo, nombre, cantidad);
}

void consultar(Nodo* cabeza, int codigo) {
    Nodo* encontrado = buscar(cabeza, codigo);

    if (encontrado != NULL) {
        cout << encontrado->codigo << " "
             << encontrado->nombre << " "
             << encontrado->cantidad << endl;
    } else {
        cout << "no existe" << endl;
    }
}

void consultar(Lista& lista, int codigo) {
    consultar(lista.cabeza, codigo);
}

void reponer(Nodo* cabeza, int codigo, int cantidadAdicional) {
    Nodo* encontrado = buscar(cabeza, codigo);

    if (encontrado != NULL) {
        encontrado->cantidad = encontrado->cantidad + cantidadAdicional;
        cout << "ok" << endl;
    } else {
        cout << "no existe" << endl;
    }
}

void reponer(Lista& lista, int codigo, int cantidad) {
    reponer(lista.cabeza, codigo, cantidad);
}

void eliminar(Nodo*& cabeza, int codigo) {
    Nodo* actual = cabeza;
    Nodo* anterior = NULL;

    while (actual != NULL && actual->codigo != codigo) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual != NULL) {
        if (anterior == NULL) {
            cabeza = actual->siguiente;
        } else {
            anterior->siguiente = actual->siguiente;
        }

        delete actual;
        cout << "ok" << endl;
    } else {
        cout << "no existe" << endl;
    }
}

void eliminar(Lista& lista, int codigo) {
    eliminar(lista.cabeza, codigo);
}

void listar(Nodo* cabeza) {
    Nodo* actual = cabeza;

    while (actual != NULL) {
        cout << actual->codigo << " "
             << actual->nombre << " "
             << actual->cantidad << endl;

        actual = actual->siguiente;
    }
}

void listar(Lista& lista) {
    listar(lista.cabeza);
}
