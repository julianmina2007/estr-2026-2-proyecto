// Autores: Julian Andres Mina Ospina 9028795, Cristian Muñoz Obando 9033692
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Nodo {
    int codigo;
    string nombre;
    int cantidad;
    Nodo* siguiente;
};

struct Producto {
    string nombre;
    int cantidad;
};

bool agregar(map<int, Producto>& inventario,
             int codigo, string nombre, int cantidad) {

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
        cout << codigo << " "
             << encontrado->second.nombre << " "
             << encontrado->second.cantidad << endl;
    } else {
        cout << "no existe" << endl;
    }
}

void reponer(map<int, Producto>& inventario,
             int codigo, int cantidad) {

    map<int, Producto>::iterator encontrado = inventario.find(codigo);

    if (encontrado != inventario.end()) {
        encontrado->second.cantidad += cantidad;
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
    for (map<int, Producto>::iterator actual = inventario.begin();
         actual != inventario.end(); ++actual) {

        cout << actual->first << " "
             << actual->second.nombre << " "
             << actual->second.cantidad << endl;
    }
}
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


int main(int argc, char* argv[]) {

    string estructura = "hash";

    if (argc > 1) {
        estructura = argv[1];
    }

    if (estructura != "lista" &&
        estructura != "hash" &&
        estructura != "map") {
        cerr << "Estructura invalida. Use: lista, hash o map" << endl;
        return 1;
    }

    Lista inventarioLista;
    inventarioLista.cabeza = NULL;

    TablaHash inventarioHash;
    inventarioHash.tamano = 5;
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
            else {
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
            else {
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
            else {
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
            else {
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
            else {
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
