#include <iostream>
#include <fstream>

int main() {
    // Abre el archivo de entrada en modo lectura y el archivo de salida en modo escritura
    std::ifstream archivoEntrada("HERALDOSNEGROS_Unicode8.txt", std::ios::in);
    std::ofstream archivoSalida("HERALDOSNEGROS_Unicode8230.txt", std::ios::out);

    if (!archivoEntrada.is_open() || !archivoSalida.is_open()) {
        std::cerr << "Error al abrir los archivos." << std::endl;
        return 1;
    }

    // Procesa el archivo de entrada carácter por carácter
    char caracter;
    while (archivoEntrada.get(caracter)) {
        // Convierte el carácter a su representación Unicode-8 y escribe en el archivo de salida
        archivoSalida << "\\u" << std::hex << static_cast<int>(caracter);
    }

    // Cierra los archivos
    archivoEntrada.close();
    archivoSalida.close();

    std::cout << "Archivo procesado exitosamente." << std::endl;

    return 0;
}
