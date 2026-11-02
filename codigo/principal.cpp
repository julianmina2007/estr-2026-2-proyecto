// Autores: Julian Andres Mina Ospina 9028795, Cristian Muñoz Obando 9033692
#include <iostream>
#include <string>

using namespace std;

struct Nodo {
    int codigo;
    string nombre;
    int cantidad;
    Nodo* siguiente;
};


Nodo* buscar(Nodo* cabeza, int codigo) {
    Nodo* actual = cabeza;

    while (actual != NULL && actual->codigo != codigo) {
        actual = actual->siguiente;
    }

    return actual;
}


bool agregar(Nodo*& cabeza, int codigo, string nombre, int cantidad) {
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
  

int main() {
    Nodo* cabeza = NULL;

    int cantidadComandos;
    cin >> cantidadComandos;

    for (int i = 0; i < cantidadComandos; i++) {
        string operacion;
        cin >> operacion;

        if (operacion == "AGREGAR") {
            int codigo;
            string nombre;
            int cantidad;

            cin >> codigo >> nombre >> cantidad;

            if (agregar(cabeza, codigo, nombre, cantidad)) {
                cout << "ok" << endl;
            } else {
                cout << "repetido" << endl;
            }
        }

        else if (operacion == "CONSULTAR") {
            int codigo;
            cin >> codigo;

            consultar(cabeza, codigo);
        }
    }

    return 0;
}