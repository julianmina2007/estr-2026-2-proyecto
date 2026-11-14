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

struct Lista {
    Nodo* cabeza;
};

struct TablaHash {
    Nodo** posiciones;
    int tamano;
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

bool agregar(Lista& lista, int codigo, string nombre, int cantidad) {
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

void reponer(Nodo* cabeza, int codigo, int cantidadAdicional) {
    Nodo* encontrado = buscar(cabeza, codigo);

    if (encontrado != NULL) {
        encontrado->cantidad = encontrado->cantidad + cantidadAdicional;
        cout << "ok" << endl;
    } else {
        cout << "no existe" << endl;
    }
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

void listar(Nodo* cabeza) {
    Nodo* actual = cabeza;

    while (actual != NULL) {
        cout << actual->codigo << " "
             << actual->nombre << " "
             << actual->cantidad << endl;

        actual = actual->siguiente;
    }
}

int posicion(int codigo, int tamano) {
    return codigo % tamano;
}

Nodo** crearTabla(int tamano) {
    Nodo** tabla = new Nodo*[tamano];

    for (int i = 0; i < tamano; i++) {
        tabla[i] = NULL;
    }

    return tabla;
}

bool agregarHash(Nodo** tabla, int tamano, int codigo, string nombre, int cantidad) {
    bool agregado = false;

    int indice = posicion(codigo, tamano);

    if (buscar(tabla[indice], codigo) == NULL) {
        Nodo* nuevo = new Nodo;

        nuevo->codigo = codigo;
        nuevo->nombre = nombre;
        nuevo->cantidad = cantidad;

        nuevo->siguiente = tabla[indice];
        tabla[indice] = nuevo;

        agregado = true;
    }

    return agregado;
}

bool agregar(TablaHash& tabla, int codigo, string nombre, int cantidad) {
    return agregarHash(tabla.posiciones, tabla.tamano, codigo, nombre, cantidad);
}

void consultarHash(Nodo** tabla, int tamano, int codigo) {
    int indice = posicion(codigo, tamano);

    consultar(tabla[indice], codigo);
}

void reponerHash(Nodo** tabla, int tamano, int codigo, int cantidadAdicional) {
    int indice = posicion(codigo, tamano);

    reponer(tabla[indice], codigo, cantidadAdicional);
}

void eliminarHash(Nodo** tabla, int tamano, int codigo) {
    int indice = posicion(codigo, tamano);

    eliminar(tabla[indice], codigo);
}

void listarHash(Nodo** tabla, int tamano) {
    for (int i = 0; i < tamano; i++) {
        listar(tabla[i]);
    }
}

void liberarTabla(Nodo** tabla, int tamano) {
    for (int i = 0; i < tamano; i++) {
        Nodo* actual = tabla[i];

        while (actual != NULL) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    delete[] tabla;
}

void consultar(Lista& lista, int codigo) {
    consultar(lista.cabeza, codigo);
}

void consultar(TablaHash& tabla, int codigo) {
    consultarHash(tabla.posiciones, tabla.tamano, codigo);
}

void reponer(Lista& lista, int codigo, int cantidad) {
    reponer(lista.cabeza, codigo, cantidad);
}

void reponer(TablaHash& tabla, int codigo, int cantidad) {
    reponerHash(tabla.posiciones, tabla.tamano, codigo, cantidad);
}

void eliminar(Lista& lista, int codigo) {
    eliminar(lista.cabeza, codigo);
}

void eliminar(TablaHash& tabla, int codigo) {
    eliminarHash(tabla.posiciones, tabla.tamano, codigo);
}

void listar(Lista& lista) {
    listar(lista.cabeza);
}

void listar(TablaHash& tabla) {
    listarHash(tabla.posiciones, tabla.tamano);
}

int main() {
    TablaHash inventario;

    inventario.tamano = 5;
    inventario.posiciones = crearTabla(inventario.tamano);

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

            if (agregar(inventario, codigo, nombre, cantidad)) {
                cout << "ok" << endl;
            } else {
                cout << "repetido" << endl;
            }
        }

        else if (operacion == "CONSULTAR") {
            int codigo;
            cin >> codigo;

            consultar(inventario, codigo);
        }

        else if (operacion == "REPONER") {
            int codigo;
            int cantidad;

            cin >> codigo >> cantidad;

            reponer(inventario, codigo, cantidad);
        }

        else if (operacion == "ELIMINAR") {
            int codigo;
            cin >> codigo;

            eliminar(inventario, codigo);
        }

        else if (operacion == "LISTAR") {
            listar(inventario);
        }
    }

    liberarTabla(inventario.posiciones, inventario.tamano);

    return 0;
}