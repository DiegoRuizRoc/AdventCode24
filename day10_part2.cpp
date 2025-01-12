#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

// Estructura para representar un punto en el mapa (fila, columna)
struct Punto {
    int fila;
    int columna;
    
    // Constructor que inicializa las coordenadas del punto
    Punto(int f, int c) : fila(f), columna(c) {}
    
    // Operador de igualdad para comparar dos puntos
    bool operator == (const Punto& p) const {
        return fila == p.fila && columna == p.columna;
    }
    
    // Operador < para permitir que los puntos se almacenen en estructuras como unordered_set
    bool operator < (const Punto& p) const {
        return fila < p.fila || (fila == p.fila && columna < p.columna);
    }
};

// Functor para proporcionar una función hash para el tipo Punto, necesario para usarlo en unordered_set
struct Hasher {
    std::size_t operator () (const Punto& p) const {
        // Combinamos las coordenadas fila y columna para generar un hash único para el punto
        return std::hash<int>()(p.fila) ^ (std::hash<int>()(p.columna) << 1);
    }
};

// Función que verifica si un punto está dentro de los límites del mapa
bool esta_en_mapa(const Punto& p, const std::vector<std::string>& mapa ) {
    return p.fila >= 0 && p.fila < mapa.size() && p.columna >= 0 && p.columna < mapa[0].size();
}

// Definimos los posibles movimientos en el mapa: abajo, derecha, arriba, izquierda
const std::vector<Punto> movimientos = {
    Punto(1, 0),   // Movimiento hacia abajo
    Punto(0, 1),   // Movimiento hacia la derecha
    Punto(-1, 0),  // Movimiento hacia arriba
    Punto(0, -1)   // Movimiento hacia la izquierda
};

// Función recursiva que busca a partir de un punto en el mapa y cuenta cuántos puntos se visitan
void buscar(const Punto& p, const std::vector<std::string>& mapa, int& cuenta) {
    // Obtenemos el valor en la celda actual
    const auto valor = mapa[p.fila][p.columna];
    
    // Recorremos todos los movimientos posibles (abajo, derecha, arriba, izquierda)
    for (const auto& movimiento : movimientos) {
        // Calculamos el nuevo punto después de realizar el movimiento
        const auto nuevo_p = Punto(p.fila + movimiento.fila, p.columna + movimiento.columna);
        
        // Verificamos si el nuevo punto está dentro del mapa
        if (!esta_en_mapa(nuevo_p, mapa)) continue;
        
        // Verificamos si el valor del nuevo punto es el esperado (valor + 1)
        if (mapa[nuevo_p.fila][nuevo_p.columna] != valor + 1) continue;
        
        // Si encontramos un '9', incrementamos la cuenta y seguimos con el siguiente movimiento
        if (mapa[nuevo_p.fila][nuevo_p.columna] == '9') {
            cuenta++;  // Aumentamos la cuenta de puntos visitados
            continue;  // Continuamos con el siguiente movimiento
        }
        
        // Llamada recursiva para continuar la búsqueda desde el nuevo punto
        buscar(nuevo_p, mapa, cuenta);
    }
}

int main(int argc, char* argv[]) {
    // Nombre del archivo de entrada, por defecto "dia_10_input"
    std::string entrada = "dia_10_input";
    
    // Si se pasa un argumento, lo usamos como nombre de archivo
    if (argc > 1) {
        entrada = argv[1];
    }

    std::ifstream archivo(entrada);  // Abrimos el archivo de entrada
    std::string linea;
    int respuesta = 0;  // Variable para almacenar el resultado final
    std::vector<std::string> mapa;  // Mapa que contiene el mapa de caracteres
    std::vector<Punto> puntos_inicio;  // Puntos donde encontramos un '0'

    // Leemos el archivo línea por línea
    while (std::getline(archivo, linea)) {
        for (int idx = 0; idx < linea.size(); ++idx) {
            // Si encontramos un '0', lo añadimos como punto de inicio
            if (linea[idx] == '0') puntos_inicio.emplace_back(mapa.size(), idx);
        }
        mapa.push_back(linea);  // Añadimos la línea al mapa
    }

    // Para cada punto de inicio encontrado, realizamos la búsqueda recursiva
    for (const auto& punto_inicio : puntos_inicio) {
        buscar(punto_inicio, mapa, respuesta);  // Llamada a la función de búsqueda
    }
    
    // Imprimimos la respuesta final que es la cantidad total de puntos visitados
    std::cout << respuesta << '\n';

    return 0;
}
