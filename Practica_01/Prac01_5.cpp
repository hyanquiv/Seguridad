#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

// Función para calcular la tabla de frecuencias
std::map<char, int> frecuencias(const std::string &archivo) {
    std::map<char, int> tabla_frecuencias;

    std::ifstream input(archivo);
    if (!input.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return tabla_frecuencias;
    }

    char caracter;
    while (input.get(caracter)) {
        // Convertir el caracter a mayúscula si es una letra
        if (std::isalpha(caracter)) {
            caracter = std::toupper(caracter);
            tabla_frecuencias[caracter]++;
        }
    }

    input.close();
    return tabla_frecuencias;
}

int main() {

    std::string archivo = "HERALDOSNEGROS_pre.txt";
    std::map<char, int> tabla = frecuencias(archivo);

    // Ordenar la tabla de frecuencias en orden descendente
    std::vector<std::pair<char, int>> sorted_tabla(tabla.begin(), tabla.end());
    std::sort(sorted_tabla.begin(), sorted_tabla.end(),
              [](const std::pair<char, int> &a, const std::pair<char, int> &b) {
                  return a.second > b.second;
              });

    // Imprimir la tabla de frecuencias
    std::cout << "Tabla de frecuencias:" << std::endl;
    for (const auto &entry : sorted_tabla) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    // Mostrar los cinco caracteres de mayor frecuencia
    std::cout << "Los cinco caracteres de mayor frecuencia:" << std::endl;
    for (int i = 0; i < std::min(5, static_cast<int>(sorted_tabla.size())); i++) {
        std::cout << sorted_tabla[i].first << ": " << sorted_tabla[i].second << std::endl;
    }

    return 0;
}
