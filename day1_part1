#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <limits>

// Estructura para almacenar la cantidad de veces que ocurre una operación en el lado izquierdo y derecho
typedef struct recurrent {
    int number_of_times_left_side;
    int number_of_times_right_side;
} recurrent;

// Función para fusionar dos subarreglos ordenados en un arreglo principal
void merge(std::vector<int>& array, int ini, int fin) {
    // Encontramos el índice medio para dividir el arreglo en dos partes
    int medio = ini + (fin - ini) / 2;

    // Calculamos los tamaños de las dos partes
    int n1 = medio - ini + 1;
    int n2 = fin - medio;

    // Creamos dos vectores temporales para almacenar los valores de las dos partes
    std::vector<int> left(n1), right(n2);

    // Copiamos los elementos del arreglo original en los vectores temporales
    for (int i = 0; i < n1; i++) {
        left[i] = array[ini + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = array[medio + 1 + i];
    }

    // Variables para recorrer los subarreglos
    int i = 0, j = 0, k = ini;

    // Comenzamos la fusión de los dos subarreglos
    while (i < n1 && j < n2) {
        // Si el elemento en 'left' es menor o igual que en 'right', lo colocamos en el arreglo principal
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            // Si no, colocamos el elemento de 'right'
            array[k] = right[j];
            j++;
        }
        k++;
    }

    // Si quedan elementos en el arreglo izquierdo, los copiamos al arreglo principal
    while (i < n1) {
        array[k] = left[i];
        k++;
        i++;
    }

    // Si quedan elementos en el arreglo derecho, los copiamos al arreglo principal
    while (j < n2) {
        array[k] = right[j];
        k++;
        j++;
    }
}

// Función recursiva de mergesort para ordenar el arreglo
void mergesort(std::vector<int>& array, int ini, int fin) {
    // Solo seguimos si el índice inicial es menor que el índice final (es decir, el subarreglo tiene más de un elemento)
    if (ini < fin) {
        // Calculamos el índice medio para dividir el arreglo
        int medio = ini + (fin - ini) / 2;

        // Llamamos recursivamente a mergesort para las dos mitades del arreglo
        mergesort(array, ini, medio);
        mergesort(array, medio + 1, fin);

        // Fusionamos las dos mitades ordenadas
        merge(array, ini, fin);
    }
}

int main() {
    // Abrimos el archivo que contiene los datos de entrada
    std::ifstream file("dia_1_input");
    if (!file) {
        // Si no se puede abrir el archivo, mostramos un error y terminamos el programa
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    // Vectores para almacenar los valores del lado izquierdo y derecho
    std::vector<int> left_side = {};
    std::vector<int> right_side;
    
    // Línea para leer cada línea del archivo
    std::string line;
    int number1, number2;

    // Leemos cada línea del archivo
    while (std::getline(file, line)) {
        std::istringstream iss(line);

        // Leemos dos números por línea y los almacenamos en los vectores correspondientes
        if (iss >> number1 >> number2) {
            left_side.push_back(number1);
            right_side.push_back(number2);
        }
    }

    // Ordenamos los vectores de los lados izquierdo y derecho utilizando mergesort
    mergesort(left_side, 0, left_side.size() - 1);
    mergesort(right_side, 0, right_side.size() - 1);

    // Variable para almacenar la distancia total calculada
    int distance = 0;

    // Calculamos la distancia entre los valores correspondientes de los dos vectores
    for (int i = 0; i < left_side.size(); i++) {
        // Si el valor del lado izquierdo es menor que el valor del lado derecho, sumamos la diferencia
        if (left_side[i] < right_side[i]) {
            distance += right_side[i] - left_side[i];
        } else {
            // Si no, sumamos la diferencia en sentido contrario
            distance += left_side[i] - right_side[i];
        }
    }

    // Mostramos el valor total de la distancia
    std::cout << distance;

    return 0;
}
