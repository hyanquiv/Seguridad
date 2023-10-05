#include <iostream>
#include <string>
#include <locale>

using namespace std;

// Función para eliminar las tildes
wstring eliminarTildes(wstring texto) {
    for (size_t i = 0; i < texto.length(); ++i) {
        wchar_t c = texto[i];
        if (c == L'á') {
            texto[i] = L'a';
        } else if (c == L'é') {
            texto[i] = L'e';
        } else if (c == L'í') {
            texto[i] = L'i';
        } else if (c == L'ó') {
            texto[i] = L'o';
        } else if (c == L'ú') {
            texto[i] = L'u';
        } else if (c == L'Á') {
            texto[i] = L'A';
        } else if (c == L'É') {
            texto[i] = L'E';
        } else if (c == L'Í') {
            texto[i] = L'I';
        } else if (c == L'Ó') {
            texto[i] = L'O';
        } else if (c == L'Ú') {
            texto[i] = L'U';
        }
    }
    
    return texto;
}

// Función para convertir un wstring a mayúsculas
wstring convertirAMayusculas(wstring texto) {
    for (size_t i = 0; i < texto.length(); ++i) {
        texto[i] = towupper(texto[i]); // Convierte el carácter a mayúsculas
    }
    return texto;
}

// Función para eliminar espacios en blanco y signos de puntuación
wstring eliminarEspaciosPuntuacion(const wstring& texto) {
    wstring resultado;
    wstring caracteresValidos = L"ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"; // Caracteres válidos

    for (wchar_t c : texto) {
        if (iswspace(c) || caracteresValidos.find(c) == wstring::npos) {
            // Si es un espacio en blanco o un carácter no válido, omítelo
            continue;
        }
        resultado += c;
    }
    return resultado;
}

// Función para aplicar el cifrado de Vigenère
wstring cifrarVigenere(wstring texto, wstring clave, const wchar_t* alfabeto, int longitudAlfabeto) {
    texto = eliminarTildes(texto);
    texto = convertirAMayusculas(texto);
    texto = eliminarEspaciosPuntuacion(texto);

    wstring resultado = L"";
    int longitudClave = clave.length();

    for (int i = 0; i < texto.length(); i++) {
        wchar_t caracter = texto[i];
        wchar_t claveActual = clave[i % longitudClave];
        
        // Encontrar el índice del carácter en el alfabeto
        int indiceCaracter = -1;
        int indiceClave = -1;
        
        for (int j = 0; j < longitudAlfabeto; j++) {
            if (caracter == alfabeto[j]) {
                indiceCaracter = j;
            }
            if (claveActual == alfabeto[j]) {
                indiceClave = j;
            }
        }

        if (indiceCaracter != -1 && indiceClave != -1) {
            // Realizar el cifrado en base a los índices
            int indiceCifrado = (indiceCaracter + indiceClave) % longitudAlfabeto;
            wchar_t caracterCifrado = alfabeto[indiceCifrado];
            resultado += caracterCifrado;
        } else {
            // Si el carácter no está en el alfabeto, mantenerlo igual
            resultado += caracter;
        }
    }

    return resultado;
}

int main() {
    wstring texto;
    wstring clave;
    const wchar_t alfabeto[] = L"ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"; // Alfabeto válido
    int longitudAlfabeto = sizeof(alfabeto) / sizeof(alfabeto[0]) - 1; // Restar 1 para excluir el carácter nulo

    wcout << L"Introduce el texto a cifrar: ";
    getline(wcin, texto);

    wcout << L"Introduce la clave: ";
    getline(wcin, clave);

    wstring textoCifrado = cifrarVigenere(texto, clave, alfabeto, longitudAlfabeto);

    wcout << L"Texto cifrado: " << textoCifrado << endl;

    return 0;
}
