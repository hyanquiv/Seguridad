#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Función para descifrar el cifrado de Vigenère
wstring descifrarVigenere(wstring textoCifrado, wstring clave, const wchar_t* alfabeto, int longitudAlfabeto) {

    wstring resultado = L"";
    int longitudClave = clave.length();

    for (int i = 0; i < textoCifrado.length(); i++) {
        wchar_t caracterCifrado = textoCifrado[i];
        wchar_t claveActual = clave[i % longitudClave];
        
        // Encontrar el índice del carácter cifrado en el alfabeto
        int indiceCifrado = -1;
        int indiceClave = -1;
        
        for (int j = 0; j < longitudAlfabeto; j++) {
            if (caracterCifrado == alfabeto[j]) {
                indiceCifrado = j;
            }
            if (claveActual == alfabeto[j]) {
                indiceClave = j;
            }
        }

        // Realizar el descifrado en base a los índices
        int indiceOriginal = (indiceCifrado - indiceClave + longitudAlfabeto) % longitudAlfabeto;
        wchar_t caracterOriginal = alfabeto[indiceOriginal];
        resultado += caracterOriginal;
    }

    return resultado;
}

int main() {
    wstring texto = L"WPIXHVYYOSRTECSZBEEGHUUFWRWTZGRWUFSRIWESSXVOHAIHOHWWHCWHUZOBOZEAOYBMCRLTEYOTI";
    wstring clave;
    const wchar_t alfabeto[] = L"ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"; // Alfabeto válido
    int longitudAlfabeto = sizeof(alfabeto) / sizeof(alfabeto[0]) - 1; // Restar 1 para excluir el carácter nulo

    //wcout << L"Introduce el texto cifrado: ";
    //getline(wcin, texto);

    wcout << L"Introduce la clave: ";
    getline(wcin, clave);

    wstring textoDescifrado = descifrarVigenere(texto, clave, alfabeto, longitudAlfabeto);

    wcout << L"Texto descifrado: " << textoDescifrado << endl;

    return 0;
}