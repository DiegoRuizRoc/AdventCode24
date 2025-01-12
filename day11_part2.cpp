#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <sstream>
#include <unordered_map>
#include <functional>

constexpr int n_level = 75; // Número máximo de parpadeos

struct TreeNode {
    long long engraving; // Número grabado en la piedra
    TreeNode* left;      // Apunta al hijo izquierdo
    TreeNode* right;     // Apunta al hijo derecho

    TreeNode(long long engraving) : engraving(engraving), left(nullptr), right(nullptr) {}
};

// Función para calcular el número de dígitos de un número
int count_digits(long long number) {
    return number == 0 ? 1 : static_cast<int>(std::log10(number)) + 1;
}

// Función hash para std::pair
struct PairHash {
    size_t operator()(const std::pair<long long, int>& p) const {
        return std::hash<long long>()(p.first) ^ std::hash<int>()(p.second);
    }
};

// Función para contar piedras en el árbol con generación perezosa
long long count_stones(TreeNode* node, int level, int max_level,
                       std::unordered_map<std::pair<long long, int>, long long, PairHash>& memo) {
    // Si hemos alcanzado el nivel deseado, contamos una piedra
    if (level == max_level) return 1;

    // Revisar en la memoria si ya hemos calculado este nodo en este nivel
    auto key = std::make_pair(node->engraving, level);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    long long total = 0;
    int n_digits = count_digits(node->engraving);

    // Generar hijos de manera perezosa si es necesario
    if (node->engraving == 0) {
        if (!node->left) node->left = new TreeNode(1);
        total += count_stones(node->left, level + 1, max_level, memo);
    } else if (n_digits % 2 == 0) {
        long long power = static_cast<long long>(std::pow(10, n_digits / 2));
        long long left_value = node->engraving / power;
        long long right_value = node->engraving % power;

        if (!node->left) node->left = new TreeNode(left_value);
        if (!node->right) node->right = new TreeNode(right_value);

        total += count_stones(node->left, level + 1, max_level, memo);
        total += count_stones(node->right, level + 1, max_level, memo);
    } else {
        if (!node->left) node->left = new TreeNode(node->engraving * 2024);
        total += count_stones(node->left, level + 1, max_level, memo);
    }

    // Almacenar el resultado en memoria para evitar cálculos repetidos
    memo[key] = total;
    return total;
}

// Liberar la memoria del árbol
void delete_tree(TreeNode* node) {
    if (!node) return;

    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

int main() {
    std::ifstream file("dia_11_input");
    if (!file) {
        std::cerr << "Error al abrir el archivo input.txt\n";
        return 1;
    }

    std::vector<long long> stones;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;

        while (iss >> token) {
            try {
                stones.push_back(std::stoll(token));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Advertencia: Entrada inválida encontrada, ignorando: " << token << '\n';
            } catch (const std::out_of_range& e) {
                std::cerr << "Advertencia: Número fuera de rango encontrado, ignorando: " << token << '\n';
            }
        }
    }

    long long total_stones = 0;

    for (long long stone : stones) {
        TreeNode* root = new TreeNode(stone);

        // Memoria para resultados calculados
        std::unordered_map<std::pair<long long, int>, long long, PairHash> memo;

        total_stones += count_stones(root, 0, n_level, memo);

        delete_tree(root); // Limpiar la memoria del árbol
    }

    std::cout << "Total de piedras después de " << n_level << " parpadeos: " << total_stones << '\n';

    return 0;
}
