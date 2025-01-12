#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <sstream>

constexpr int n_level = 25; // Número máximo de parpadeos (profundidad máxima del árbol)

struct TreeNode {
    long long engraving; // Número grabado en la piedra (valor de este nodo)
    TreeNode* left; 
    TreeNode* right; 

    // Constructor que inicializa el valor del nodo y pone los hijos como null
    TreeNode(long long engraving) : engraving(engraving), left(nullptr), right(nullptr) {}
};

// Función para calcular el número de dígitos de un número
int count_digits(long long number) {
    return number == 0 ? 1 : static_cast<int>(std::log10(number)) + 1;
}

// Función recursiva para construir el árbol desde un nodo raíz
void build_tree(TreeNode* node, int level, int max_level) {
    // Si hemos alcanzado la profundidad máxima, no hacemos más subdivisiones
    if (level >= max_level) return;

    // Calculamos la cantidad de dígitos del valor del nodo
    int n_digits = count_digits(node->engraving);

    if (node->engraving == 0) {
        // Si el valor del nodo es 0, solo creamos el hijo izquierdo con valor 1
        node->left = new TreeNode(1);
        build_tree(node->left, level + 1, max_level);
    } else if (n_digits % 2 == 0) {
        // Si el número de dígitos es par, dividimos el número por la mitad
        long long power = static_cast<long long>(std::pow(10, n_digits / 2)); // Potencia de 10
        long long left_value = node->engraving / power; // Valor para el hijo izquierdo
        long long right_value = node->engraving % power; // Valor para el hijo derecho

        // Creamos los hijos izquierdo y derecho con los valores calculados
        node->left = new TreeNode(left_value);
        node->right = new TreeNode(right_value);

        // Llamamos recursivamente para construir los subárboles
        build_tree(node->left, level + 1, max_level);
        build_tree(node->right, level + 1, max_level);
    } else {
        // Si el número de dígitos es impar, multiplicamos el valor por 2024
        node->left = new TreeNode(node->engraving * 2024);
        build_tree(node->left, level + 1, max_level); 
    }
}

// Función recursiva para contar el número de piedras en el árbol después de n_level parpadeos
long long count_stones(TreeNode* node, int level) {
    // Si hemos llegado al nivel máximo de parpadeos, devolvemos 1
    if (level == n_level) return 1;

    long long total = 0;

    // Si hay un hijo izquierdo, contamos las piedras en ese subárbol
    if (node->left) total += count_stones(node->left, level + 1);

    // Si hay un hijo derecho, contamos las piedras en ese subárbol
    if (node->right) total += count_stones(node->right, level + 1);

    return total; // devolvemos el total de piedras encontradas
}

// Función recursiva para liberar la memoria ocupada por el árbol 
void delete_tree(TreeNode* node) {
    if (!node) return;

    // Llamadas recursivas para liberar la memoria de los subárboles izquierdo y derecho
    delete_tree(node->left);
    delete_tree(node->right);

    // Finalmente, liberamos la memoria del nodo actual
    delete node;
}

int main() {
    std::ifstream file("dia_11_input"); // Abrimos el archivo de entrada
    if (!file) {
        std::cerr << "Error al abrir el archivo input.txt\n";
        return 
