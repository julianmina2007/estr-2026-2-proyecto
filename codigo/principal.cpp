
#include <iostream>
#include <string>
#include <map>
#include "lista.h"
#include "lista.cpp"

using namespace std;

struct TablaHash {
    Nodo** posiciones;
    int tamano;
};

struct Producto {
    string nombre;
    int cantidad;
};

bool agregar(map<int, Producto>& inventario, int codigo, const string& nombre, int cantidad) {
    bool agregado = false;

    if (inventario.find(codigo) == inventario.end()) {
        Producto nuevo;

        nuevo.nombre = nombre;
        nuevo.cantidad = cantidad;

        inventario[codigo] = nuevo;
        agregado = true;
    }

    return agregado;
}

void consultar(map<int, Producto>& inventario, int codigo) {
    map<int, Producto>::iterator encontrado = inventario.find(codigo);

    if (encontrado != inventario.end()) {
        cout << encontrado->first << " "
             << encontrado->second.nombre << " "
             << encontrado->second.cantidad << endl;
    } else {
        cout << "no existe" << endl;
    }
}

void reponer(map<int, Producto>& inventario, int codigo, int cantidadAdicional) {
    map<int, Producto>::iterator encontrado = inventario.find(codigo);

    if (encontrado != inventario.end()) {
        encontrado->second.cantidad =
            encontrado->second.cantidad + cantidadAdicional;

        cout << "ok" << endl;
    } else {
        cout << "no existe" << endl;
    }
}

void eliminar(map<int, Producto>& inventario, int codigo) {
    map<int, Producto>::iterator encontrado = inventario.find(codigo);

    if (encontrado != inventario.end()) {
        inventario.erase(encontrado);
        cout << "ok" << endl;
    } else {
        cout << "no existe" << endl;
    }
}

void listar(map<int, Producto>& inventario) {
    map<int, Producto>::iterator actual = inventario.begin();

    while (actual != inventario.end()) {
        cout << actual->first << " "
             << actual->second.nombre << " "
             << actual->second.cantidad << endl;

        actual++;
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


bool agregarHash(Nodo** tabla, int tamano, int codigo, const string& nombre, int cantidad) {
    bool agregado = false;

    int indice = posicion(codigo, tamano);

    if (buscar(tabla[indice], codigo) == NULL) {
        Nodo* nuevo = new Nodo;

        nuevo->codigo = codigo;
        nuevo->nombre = nombre;
        nuevo->cantidad = cantidad;
        nuevo->siguiente = NULL;

        if (tabla[indice] == NULL) {
            tabla[indice] = nuevo;
        } else {
            Nodo* actual = tabla[indice];

            while (actual->siguiente != NULL) {
                actual = actual->siguiente;
            }

            actual->siguiente = nuevo;
        }

        agregado = true;
    }

    return agregado;
}

bool agregar(TablaHash& tabla, int codigo, const string& nombre, int cantidad) {
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

void consultar(TablaHash& tabla, int codigo) {
    consultarHash(tabla.posiciones, tabla.tamano, codigo);
}

void reponer(TablaHash& tabla, int codigo, int cantidad) {
    reponerHash(tabla.posiciones, tabla.tamano, codigo, cantidad);
}

void eliminar(TablaHash& tabla, int codigo) {
    eliminarHash(tabla.posiciones, tabla.tamano, codigo);
}

void listar(TablaHash& tabla) {
    listarHash(tabla.posiciones, tabla.tamano);
}

int main() {
    string estructura = "hash";
    int tamanoHash = 5;

    Lista inventarioLista;
    inventarioLista.cabeza = NULL;

    TablaHash inventarioHash;
    inventarioHash.tamano = tamanoHash;
    inventarioHash.posiciones = crearTabla(inventarioHash.tamano);

    map<int, Producto> inventarioMap;

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

            bool agregado = false;

            if (estructura == "lista") {
                agregado = agregar(inventarioLista, codigo, nombre, cantidad);
            }
            else if (estructura == "hash") {
                agregado = agregar(inventarioHash, codigo, nombre, cantidad);
            }
            else if (estructura == "map") {
                agregado = agregar(inventarioMap, codigo, nombre, cantidad);
            }

            if (agregado) {
                cout << "ok" << endl;
            } else {
                cout << "repetido" << endl;
            }
        }
        else if (operacion == "CONSULTAR") {
            int codigo;
            cin >> codigo;

            if (estructura == "lista") {
                consultar(inventarioLista, codigo);
            }
            else if (estructura == "hash") {
                consultar(inventarioHash, codigo);
            }
            else if (estructura == "map") {
                consultar(inventarioMap, codigo);
            }
        }
        else if (operacion == "REPONER") {
            int codigo;
            int cantidad;

            cin >> codigo >> cantidad;

            if (estructura == "lista") {
                reponer(inventarioLista, codigo, cantidad);
            }
            else if (estructura == "hash") {
                reponer(inventarioHash, codigo, cantidad);
            }
            else if (estructura == "map") {
                reponer(inventarioMap, codigo, cantidad);
            }
        }
        else if (operacion == "ELIMINAR") {
            int codigo;
            cin >> codigo;

            if (estructura == "lista") {
                eliminar(inventarioLista, codigo);
            }
            else if (estructura == "hash") {
                eliminar(inventarioHash, codigo);
            }
            else if (estructura == "map") {
                eliminar(inventarioMap, codigo);
            }
        }
        else if (operacion == "LISTAR") {
            if (estructura == "lista") {
                listar(inventarioLista);
            }
            else if (estructura == "hash") {
                listar(inventarioHash);
            }
            else if (estructura == "map") {
                listar(inventarioMap);
            }
        }
    }

    Nodo* actual = inventarioLista.cabeza;

    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }

    liberarTabla(inventarioHash.posiciones, inventarioHash.tamano);

    return 0;
}
