#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

// Función para leer el grafo desde el archivo
unordered_map<string, unordered_set<string>> leerGrafo(const string& nombreArchivo) {
    unordered_map<string, unordered_set<string>> grafo;
    ifstream archivo(nombreArchivo);
    string linea;
    while (getline(archivo, linea)) {
        string nodo1 = linea.substr(0, 2);
        string nodo2 = linea.substr(3, 2);
        grafo[nodo1].insert(nodo2);
        grafo[nodo2].insert(nodo1);
    }
    return grafo;
}

// Función para verificar si tres nodos forman un triángulo
bool esTriangulo(const unordered_map<string, unordered_set<string>>& grafo, const string& a, const string& b, const string& c) {
    return grafo.at(a).count(b) && grafo.at(b).count(c) && grafo.at(c).count(a);
}

// Función principal
int main() {
    string nombreArchivo = "dia_23_input";

    // Leer el grafo desde el archivo
    auto grafo = leerGrafo(nombreArchivo);

    // Almacenar todos los nodos
    vector<string> nodos;
    for (const auto& par : grafo) {
        nodos.push_back(par.first);
    }

    int contador = 0;

    // Fuerza bruta: probar todos los tríos de nodos
    for (size_t i = 0; i < nodos.size(); ++i) {
        for (size_t j = i + 1; j < nodos.size(); ++j) {
            for (size_t k = j + 1; k < nodos.size(); ++k) {
                const string& a = nodos[i];
                const string& b = nodos[j];
                const string& c = nodos[k];

                // Verificar si forman un triángulo
                if (esTriangulo(grafo, a, b, c)) {
                    // Verificar si al menos uno empieza con 't'
                    if (a[0] == 't' || b[0] == 't' || c[0] == 't') {
                        ++contador;
                        cout << "Trio: " << a << ", " << b << ", " << c << endl;
                    }
                }
            }
        }
    }

    cout << "Total de tríos encontrados: " << contador << endl;

    return 0;
}
