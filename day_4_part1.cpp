#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Direcciones posibles: horizontal, vertical, diagonal y su versiones inversa
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

// Palabra objetivo
const string TARGET = "XMAS";

// Función para buscar "XMAS" con programación dinámica
bool search_in_direction(const vector<string>& grid, vector<vector<vector<int>>>& dp, int x, int y, int d, int pos) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    // Si hemos completado la palabra, devolver true
    if (pos == TARGET.size()) return true;

    // Si estamos fuera de los límites, devolver false
    if (x < 0 || x >= rows || y < 0 || y >= cols) return false;

    // Si el carácter no coincide, devolver false
    if (grid[x][y] != TARGET[pos]) return false;

    // Si ya hemos calculado este caso, devolver el resultado 
    if (dp[x][y][d] != -1) return dp[x][y][d];

    // Continuar buscando en la dirección actual
    int nx = x + dx[d];
    int ny = y + dy[d];

    // Almacenar el resultado en dp[x][y][d]
    dp[x][y][d] = search_in_direction(grid, dp, nx, ny, d, pos + 1);

    return dp[x][y][d];
}

// Función principal para contar todas las veces que está la palabra "XMAS"
int count_xmas_occurrences(const vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    // Crear una matriz de memoria para cada dirección (8 direcciones)
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(8, -1)));

    // Recorremos toda la cuadrícula
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            // Si la celda contiene la primera letra de "XMAS"
            if (grid[x][y] == TARGET[0]) {
                // Intentar buscar en todas las direcciones
                for (int d = 0; d < 8; ++d) {
                    if (search_in_direction(grid, dp, x, y, d, 0)) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    ifstream file("input4.txt");
    if (!file) {
        cerr << "Error al abrir el archivo input2.txt\n";
        return 1;
    }

    vector<string> grid;
    string line;

    // Leer la cuadrícula del archivo
    while (getline(file, line)) {
        grid.push_back(line);
    }

    // Contar las ocurrencias de "XMAS"
    int result = count_xmas_occurrences(grid);

    cout << "Número total de ocurrencias de 'XMAS': " << result << '\n';

    return 0;
}

