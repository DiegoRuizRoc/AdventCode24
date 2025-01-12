#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

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

// Encuentra el mayor subgrafo completamente conectado (clique máximo) comenzando desde un nodo dado
vector<string> encontrarCliqueDesdeNodo(const string& nodoInicial, const unordered_map<string, unordered_set<string>>& grafo) {
    vector<string> cliqueActual = { nodoInicial };

    // Iterar sobre todos los nodos del grafo
    for (const auto& par : grafo) {
        const string& nodo = par.first;
        if (nodo == nodoInicial) continue;

        // Verificar si el nodo está conectado con todos los nodos en el clique actual
        bool conectadoATodos = true;
        for (const string& miembro : cliqueActual) {
            if (!grafo.at(miembro).count(nodo)) {
                conectadoATodos = false;
                break;
            }
        }

        // Si está conectado a todos, añadirlo al clique actual
        if (conectadoATodos) {
            cliqueActual.push_back(nodo);
        }
    }

    return cliqueActual;
}

int main() {
    string nombreArchivo = "dia_23_input";

    // Leer el grafo desde el archivo
    auto grafo = leerGrafo(nombreArchivo);

    vector<string> mejorClique;

    // Encontrar el mayor clique iterando sobre cada nodo
    for (const auto& par : grafo) {
        vector<string> clique = encontrarCliqueDesdeNodo(par.first, grafo);
        if (clique.size() > mejorClique.size()) {
            mejorClique = clique;
        }
    }

    // Ordenar alfabéticamente el clique máximo
    sort(mejorClique.begin(), mejorClique.end());

    // Generar la contraseña
    string password;
    for (size_t i = 0; i < mejorClique.size(); ++i) {
        if (i > 0) password += ",";
        password += mejorClique[i];
    }

    cout << "Contraseña para la LAN party: " << password << endl;

    return 0;
}
