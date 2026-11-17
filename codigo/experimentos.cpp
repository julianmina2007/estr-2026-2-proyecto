
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <chrono>
#include <fstream>
#include <iomanip>

using namespace std;

struct Nodo {
    int codigo;
    string nombre;
    int cantidad;
    Nodo* siguiente;
};

// Busca un producto recorriendo una lista enlazada.
Nodo* buscar(Nodo* cabeza, int codigo) {
    Nodo* actual = cabeza;

    while (actual != NULL && actual->codigo != codigo) {
        actual = actual->siguiente;
    }

    return actual;
}

// Libera la memoria de una lista.
void liberarLista(Nodo* cabeza) {
    while (cabeza != NULL) {
        Nodo* siguiente = cabeza->siguiente;
        delete cabeza;
        cabeza = siguiente;
    }
}

int main() {
    int tamanos[] = {1000, 5000, 10000, 50000, 100000};

    const int tamanoHash = 5;
    const int repeticiones = 100;

    ofstream archivo("../datos/mediciones.csv");

    if (!archivo.is_open()) {
        cerr << "No se pudo crear mediciones.csv" << endl;
        return 1;
    }

    archivo << "productos,lista_us,hash_us,map_us\n";
    archivo << fixed << setprecision(6);

    for (int n : tamanos) {

        Nodo* lista = NULL;
        Nodo** tabla = new Nodo*[tamanoHash]();

        map<int, int> inventarioMap;

        // Construir las tres estructuras con los mismos productos.
        for (int codigo = 1; codigo <= n; codigo++) {

            Nodo* nuevo = new Nodo;
            nuevo->codigo = codigo;
            nuevo->nombre = "producto";
            nuevo->cantidad = 10;
            nuevo->siguiente = lista;
            lista = nuevo;

            int indice = codigo % tamanoHash;

            Nodo* nuevoHash = new Nodo;
            nuevoHash->codigo = codigo;
            nuevoHash->nombre = "producto";
            nuevoHash->cantidad = 10;
            nuevoHash->siguiente = tabla[indice];
            tabla[indice] = nuevoHash;

            inventarioMap[codigo] = codigo;
        }

        // Consultar los mismos diez productos en las tres estructuras.
        vector<int> consultas;

        for (int codigo = 1; codigo <= 10; codigo++) {
            consultas.push_back(codigo);
        }

        long long encontrados = 0;

        // Medir lista enlazada.
        auto inicioLista = chrono::steady_clock::now();

        for (int r = 0; r < repeticiones; r++) {
            for (int codigo : consultas) {
                if (buscar(lista, codigo) != NULL) {
                    encontrados++;
                }
            }
        }

        auto finLista = chrono::steady_clock::now();

        double tiempoLista =
            chrono::duration<double, micro>(
                finLista - inicioLista
            ).count() / (repeticiones * consultas.size());

        // Medir tabla hash.
        auto inicioHash = chrono::steady_clock::now();

        for (int r = 0; r < repeticiones; r++) {
            for (int codigo : consultas) {
                int indice = codigo % tamanoHash;

                if (buscar(tabla[indice], codigo) != NULL) {
                    encontrados++;
                }
            }
        }

        auto finHash = chrono::steady_clock::now();

        double tiempoHash =
            chrono::duration<double, micro>(
                finHash - inicioHash
            ).count() / (repeticiones * consultas.size());

        // Medir std::map.
        auto inicioMap = chrono::steady_clock::now();

        for (int r = 0; r < repeticiones; r++) {
            for (int codigo : consultas) {
                if (inventarioMap.find(codigo) != inventarioMap.end()) {
                    encontrados++;
                }
            }
        }

        auto finMap = chrono::steady_clock::now();

        double tiempoMap =
            chrono::duration<double, micro>(
                finMap - inicioMap
            ).count() / (repeticiones * consultas.size());

        // Guardar los resultados.
        archivo << n << ","
                << tiempoLista << ","
                << tiempoHash << ","
                << tiempoMap << "\n";

        cout << "Experimento terminado para " << n
             << " productos." << endl;

        // Liberar memoria.
        liberarLista(lista);

        for (int i = 0; i < tamanoHash; i++) {
            liberarLista(tabla[i]);
        }

        delete[] tabla;
    }

    archivo.close();

    cout << "Mediciones guardadas en datos/mediciones.csv"
         << endl;

    return 0;
}
