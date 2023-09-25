#include <iostream>
#include <fstream>
#include <string>

// Función para reemplazar caracteres en un string por Unicode-8230 (Horizontal Ellipsis)
std::string replace_with_ellipsis(const std::string& input) {
    std::string processed;
    char ellipsis = '\u2026';  // Carácter Unicode-8230 (Horizontal Ellipsis)
    
    for (char c : input) {
        processed += ellipsis;
    }
    
    return processed;
}

int main() {
    // Nombre del archivo de entrada y salida
    std::string input_filename = "HERALDOSNEGROS_pre.txt";
    std::string output_filename = "HERALDOSNEGROS_Unicode8230.txt";

    // Abrir el archivo de entrada
    std::ifstream input_file(input_filename);
    
    if (!input_file) {
        std::cerr << "No se pudo abrir el archivo de entrada: " << input_filename << std::endl;
        return 1;
    }

    // Leer el contenido del archivo de entrada
    std::string input_content((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    
    // Procesar el contenido reemplazando caracteres
    std::string processed_content = replace_with_ellipsis(input_content);

    // Abrir el archivo de salida
    std::ofstream output_file(output_filename);
    
    if (!output_file) {
        std::cerr << "No se pudo crear el archivo de salida: " << output_filename << std::endl;
        return 1;
    }

    // Escribir el contenido procesado en el archivo de salida
    output_file << processed_content;
    
    std::cout << "Procesamiento completado. El resultado se ha guardado en " << output_filename << std::endl;

    return 0;
}
