#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Nombre del archivo de entrada y salida
    const std::string inputFileName = "HERALDOSNEGROS_pre.txt";
    const std::string outputFileName = "HERALDOSNEGROS_procesado.txt";

    // Abre el archivo de entrada
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
        return 1;
    }

    // Lee el contenido del archivo de entrada en una cadena
    std::string contenido;
    char ch;
    while (inputFile.get(ch)) {
        // Reemplaza cada carácter por "…" (UNICODE-8230)
        contenido += (ch == '.') ? '…' : ch;
    }

    // Cierra el archivo de entrada
    inputFile.close();

    // Abre el archivo de salida
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return 1;
    }

    // Escribe el contenido modificado en el archivo de salida
    outputFile << contenido;

    // Cierra el archivo de salida
    outputFile.close();

    std::cout << "Archivo procesado exitosamente." << std::endl;

    return 0;
}
