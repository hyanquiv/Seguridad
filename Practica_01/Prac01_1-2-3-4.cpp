#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

// Función para realizar las sustituciones
std::wstring sustituirCaracteres(std::wstring texto) { // Cambiar de std::string a std::wstring
    // Realizar las sustituciones especificadas
    for (size_t i = 0; i < texto.length(); ++i) {
        wchar_t c = texto[i]; // Cambiar char a wchar_t
        if (c == L'j' || c == L'h') { // Cambiar 'j' y 'h' a L'j' y L'h'
            texto[i] = L'i'; // Cambiar 'i' a L'i'
        } else if (c == L'ñ') { // Cambiar 'ñ' a L'ñ'
            texto[i] = L'n'; // Cambiar 'n' a L'n'
        } else if (c == L'k') { // Cambiar 'k' a L'k'
            texto[i] = L'l'; // Cambiar 'l' a L'l'
        } else if (c == L'u' || c == L'w') { // Cambiar 'u' y 'w' a L'u' y L'w'
            texto[i] = L'v'; // Cambiar 'v' a L'v'
        } else if (c == L'y') { // Cambiar 'y' a L'y'
            texto[i] = L'z'; // Cambiar 'z' a L'z'
        }
    }
    return texto;
}

// Función para eliminar las tildes
std::wstring eliminarTildes(std::wstring texto) { // Cambiar de std::string a std::wstring
    for (size_t i = 0; i < texto.length(); ++i) {
        wchar_t c = texto[i]; // Cambiar char a wchar_t
        if (c == L'á') { // Cambiar 'á' a L'á'
            texto[i] = L'a'; // Cambiar 'a' a L'a'
        } else if (c == L'é') { // Cambiar 'é' a L'é'
            texto[i] = L'e'; // Cambiar 'e' a L'e'
        } else if (c == L'í') { // Cambiar 'í' a L'í'
            texto[i] = L'i'; // Cambiar 'i' a L'i'
        } else if (c == L'ó') { // Cambiar 'ó' a L'ó'
            texto[i] = L'o'; // Cambiar 'o' a L'o'
        } else if (c == L'ú') { // Cambiar 'ú' a L'ú'
            texto[i] = L'u'; // Cambiar 'u' a L'u'
        } else if (c == L'Á') { // Cambiar 'Á' a L'Á'
            texto[i] = L'A'; // Cambiar 'A' a L'A'
        } else if (c == L'É') { // Cambiar 'É' a L'É'
            texto[i] = L'E'; // Cambiar 'E' a L'E'
        } else if (c == L'Í') { // Cambiar 'Í' a L'Í'
            texto[i] = L'I'; // Cambiar 'I' a L'I'
        } else if (c == L'Ó') { // Cambiar 'Ó' a L'Ó'
            texto[i] = L'O'; // Cambiar 'O' a L'O'
        } else if (c == L'Ú') { // Cambiar 'Ú' a L'Ú'
            texto[i] = L'U'; // Cambiar 'U' a L'U'
        }
    }
    
    return texto;
}

// Función para convertir un std::wstring a mayúsculas
std::wstring convertirAMayusculas(std::wstring texto) {
    for (size_t i = 0; i < texto.length(); ++i) {
        texto[i] = std::towupper(texto[i]); // Convierte el carácter a mayúsculas
    }
    return texto;
}

// Función para eliminar espacios en blanco y signos de puntuación
std::wstring eliminarEspaciosPuntuacion(const std::wstring& texto) {
    std::wstring resultado;
    std::wstring caracteresValidos = L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Caracteres válidos

    for (wchar_t c : texto) {
        if (std::iswspace(c) || caracteresValidos.find(c) == std::wstring::npos) {
            // Si es un espacio en blanco o un carácter no válido, omítelo
            continue;
        }
        resultado += c;
    }
    return resultado;
}

int main() {
    std::wstring Poema = L"Hay golpes en la vida, tan fuertes… ¡Yo no sé!\nGolpes como del odio de Dios; como si ante ellos,\nla resaca de todo lo sufrido\nse empozara en el alma… ¡Yo no sé!\n\nSon pocos; pero son… Abren zanjas oscuras\nen el rostro más fiero y en el lomo más fuerte.\nSerán tal vez los potros de bárbaros Atilas;\no los heraldos negros que nos manda la Muerte.\n\nSon las caídas hondas de los Cristos del alma\nde alguna fe adorable que el Destino blasfema.\nEsos golpes sangrientos son las crepitaciones\nde algún pan que en la puerta del horno se nos quema.\n\nY el hombre… Pobre… ¡pobre! Vuelve los ojos, como\ncuando por sobre el hombro nos llama una palmada;\nvuelve los ojos locos, y todo lo vivido\nse empoza, como charco de culpa, en la mirada.\n\nHay golpes en la vida, tan fuertes… ¡Yo no sé!";

    // Aplicar la función al wstring Poema
    std::wstring resultado = sustituirCaracteres(Poema);

    // Mostrar el resultado en la consola
    std::wcout << L"Realizar las siguientes sustituciones: j → i, h → i,  ̃n → n, k → l, u → v, w → v, y → z" << std::endl;
    std::wcout << resultado << std::endl;

    // Aplicar la función eliminarTildes al wstring resultado
    resultado = eliminarTildes(resultado);

    // Mostrar el resultado en la consola
    std::wcout << std::endl;
    std::wcout << L"Elimine las tildes" << std::endl;
    std::wcout << resultado << std::endl;

    // Aplicar la función eliminarTildes al wstring resultado
    resultado = convertirAMayusculas(resultado);

    // Mostrar el resultado en la consola
    std::wcout << std::endl;
    std::wcout << L"Convierta todas las letras a mayúsculas" << std::endl;
    std::wcout << resultado << std::endl;

    // Eliminar espacios en blanco y signos de puntuación
    std::wstring textoLimpio = eliminarEspaciosPuntuacion(resultado);

    // Guardar el resultado en un archivo
    std::wofstream archivoSalida("HERALDOSNEGROS_pre.txt");
    if (archivoSalida.is_open()) {
        archivoSalida << textoLimpio;
        archivoSalida.close();
        std::wcout << L"Resultado guardado en 'HERALDOSNEGROS_pre.txt'" << std::endl;
    } else {
        std::wcerr << L"No se pudo abrir el archivo de salida." << std::endl;
    }


    return 0;
}
