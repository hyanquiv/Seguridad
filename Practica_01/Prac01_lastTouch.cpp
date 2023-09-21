#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Nombre del archivo de entrada y salida
    const std::string inputFileName = "HERALDOSNEGROS_Unicode8230.txt";
    const std::string outputFileName = "HERALDOSNEGROS_final.txt";

    // Abre el archivo de entrada
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
        return 1;
    }

    // Lee el contenido del archivo de entrada en una cadena
    std::string contenido;
    char ch;
    int charCount = 0; // Contador de caracteres leídos

    while (inputFile.get(ch)) {
        // Inserta "AQUÍ" cada 20 caracteres
        if (charCount == 20) {
            contenido += "AQUÍ";
            charCount = 0;
        }
        contenido += ch;
        charCount++;
    }

    // Calcula la cantidad de caracteres que faltan para que sea múltiplo de 4
    int padding = 4 - (contenido.length() % 4);

    // Rellena con caracteres 'X' si es necesario
    for (int i = 0; i < padding; i++) {
        contenido += 'X';
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
