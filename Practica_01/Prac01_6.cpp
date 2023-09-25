#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

// Función para encontrar trigramas repetidos y calcular sus distancias
std::map<std::string, std::vector<int>> encontrarTrigramasRepetidos(const std::string &textoCifrado) {
    std::map<std::string, std::vector<int>> trigramas;
    int trigramLength = 3;  // Tamaño del trigrama

    // Iterar a través del texto cifrado para encontrar trigramas
    for (int i = 0; i <= textoCifrado.length() - trigramLength; i++) {
        std::string trigram = textoCifrado.substr(i, trigramLength);
        for (int j = i + 1; j <= textoCifrado.length() - trigramLength; j++) {
            if (textoCifrado.substr(j, trigramLength) == trigram) {
                int distancia = j - i;
                trigramas[trigram].push_back(distancia);
            }
        }
    }

    return trigramas;
}

int main() {
    std::ifstream archivoCifrado("HERALDOSNEGROS_pre.txt");  // Nombre del archivo de texto cifrado
    if (!archivoCifrado.is_open()) {
        std::cerr << "No se pudo abrir el archivo cifrado." << std::endl;
        return 1;
    }

    std::string textoCifrado;
    char caracter;
    while (archivoCifrado.get(caracter)) {
        textoCifrado += caracter;
    }

    archivoCifrado.close();

    // Llamar a la función para encontrar trigramas repetidos y sus distancias
    std::map<std::string, std::vector<int>> trigramasDistancias = encontrarTrigramasRepetidos(textoCifrado);

    // Crear y abrir el archivo "trigramas.txt" para escritura
    std::ofstream archivoTrigramas("trigramas.txt");
    if (!archivoTrigramas.is_open()) {
        std::cerr << "No se pudo abrir el archivo trigramas.txt." << std::endl;
        return 1;
    }

    // Escribir los resultados en el archivo "trigramas.txt"
    for (const auto &entry : trigramasDistancias) {
        archivoTrigramas << "Trigrama: " << entry.first << std::endl;
        archivoTrigramas << "Distancias: ";
        for (const int distancia : entry.second) {
            archivoTrigramas << distancia << " ";
        }
        archivoTrigramas << std::endl;
    }

    archivoTrigramas.close();

    std::cout << "Los resultados se han guardado en trigramas.txt." << std::endl;

    return 0;
}