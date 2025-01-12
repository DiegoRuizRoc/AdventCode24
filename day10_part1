#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

// Estructura para representar un punto (fila, columna)
struct Punto {
    int fila;
    int columna;
    
    // Constructor que inicializa las coordenadas del punto
    Punto(int f, int c) : fila(f), columna(c) {}
    
    // Operador de igualdad para comparar puntos
    bool operator == (const Punto& p) const {
        return fila == p.fila && columna == p.columna;
    }
    
    // Operador < para poder almacenar puntos en un contenedor como unordered_set
    bool operator < (const Punto& p) const {
        return fila < p.fila || (fila == p.fila && columna < p.columna);
    }
};

// Functor para usar la estructura Punto como clave en un unordered_set
struct Hasher {
    std::size_t operator () (const Punto& p) const {
        // Combina las coordenadas fila y columna para generar un hash único
        return std::hash<int>()(p.fila) ^ (std::hash<int>()(p.columna) << 1);
    }
};

// Función que verifica si un punto está dentro de los límites del mapa
bool esta_en_mapa(const Punto& p, const std::vector<std::string>& mapa ) {
    return p.fila >= 0 && p.fila < mapa.size() && p.columna >= 0 && p.columna < mapa[0].size();
}

// Vector de movimientos posibles: arriba, derecha, abajo, izquierda
const std::vector<Punto> movimientos = {
    Punto(1, 0),   // Movimiento hacia abajo
    Punto(0, 1),   // Movimiento hacia la derecha
    Punto(-1, 0),  // Movimiento hacia arriba
    Punto(0, -1)   // Movimiento hacia la izquierda
};

// Función recursiva para realizar una búsqueda en profundidad desde un punto
void buscar(const Punto& p, const std::vector<std::string>& mapa, std::unordered_set<Punto, Hasher>& visitados) {
    const auto valor = mapa[p.fila][p.columna];  // Valor del punto actual
    for (const auto& movimiento : movimientos) {
        // Calcula las nuevas coordenadas con el movimiento
        const auto nuevo_p = Punto(p.fila + movimiento.fila, p.columna + movimiento.columna);
        
        // Verifica si el nuevo punto está dentro del mapa
        if (!esta_en_mapa(nuevo_p, mapa)) continue;
        
        // Verifica si el valor del nuevo punto es el valor esperado (valor + 1)
        if (mapa[nuevo_p.fila][nuevo_p.columna] != valor + 1) continue;
        
        // Si encontramos un '9', marcamos el punto como visitado y continuamos
        if (mapa[nuevo_p.fila][nuevo_p.columna] == '9') {
            visitados.insert(nuevo_p);
            continue;
        }
        
        // Llamada recursiva para continuar la búsqueda desde el nuevo punto
        buscar(nuevo_p, mapa, visitados);
    }
}

int main(int argc, char* argv[]) {
    std::string entrada = "dia_10_input";  // Nombre del archivo por defecto
    if (argc > 1) {
        entrada = argv[1];  // Si se pasa un argumento, usarlo como nombre de archivo
    }

    std::ifstream archivo(entrada);  // Abrir el archivo de entrada
    std::string linea;
    int respuesta = 0;  // Variable para almacenar la respuesta
    std::vector<std::string> mapa;  // Vector para almacenar el mapa
    std::vector<Punto> puntos_inicio;  // Vector para almacenar los puntos iniciales (donde están los '0')

    // Leer el archivo línea por línea
    while (std::getline(archivo, linea)) {
        for (int idx = 0; idx < linea.size(); ++idx) {
            // Si encontramos un '0', agregar el punto a la lista de puntos de inicio
            if (linea[idx] == '0') puntos_inicio.emplace_back(mapa.size(), idx);
        }
        mapa.push_back(linea);  // Agregar la línea al mapa
    }

    // Para cada punto de inicio, realizamos una búsqueda en profundidad
    for (const auto& punto_inicio : puntos_inicio) {
        std::unordered_set<Punto, Hasher> visitados;  // Set para almacenar los puntos visitados
        buscar(punto_inicio, mapa, visitados);  // Realizamos la búsqueda desde el punto de inicio
        respuesta += visitados.size();  // Sumar la cantidad de puntos visitados en esta búsqueda
    }
    
    std::cout << respuesta << '\n';  // Imprimir la respuesta final

    return 0;
}
