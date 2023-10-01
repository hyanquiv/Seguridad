#include <iostream>
#include <string>

using namespace std;

// Función para cifrar un carácter utilizando el cifrado Vigenère
char cifrarCaracter(char caracter, char clave, int modulo) {
    if (caracter >= 'A' && caracter <= 'Z') {
        caracter = ((caracter - 'A') + (clave - 'A')) % modulo + 'A';
    } else if (caracter >= 'a' && caracter <= 'z') {
        caracter = ((caracter - 'a') + (clave - 'a')) % modulo + 'a';
    }
    return caracter;
}

// Función para cifrar un texto utilizando el cifrado Vigenère
string cifrarVigenere(string texto, string clave, int modulo) {
    string cifrado = "";
    int claveIndex = 0;
    for (char caracter : texto) {
        if (isalpha(caracter)) {
            cifrado += cifrarCaracter(caracter, clave[claveIndex % clave.length()], modulo);
            claveIndex++;
        } else {
            cifrado += caracter;
        }
    }
    return cifrado;
}

int main() {
    int modulo;
    cout << "Seleccione el módulo (27 o 191): ";
    cin >> modulo;

    if (modulo != 27 && modulo != 191) {
        cout << "Módulo no válido. Debe ser 27 o 191." << endl;
        return 1;
    }

    string texto, clave;
    cout << "Ingrese el texto: ";
    cin.ignore(); // Para consumir el salto de línea anterior
    getline(cin, texto);

    cout << "Ingrese la clave: ";
    cin >> clave;

    string cifrado = cifrarVigenere(texto, clave, modulo);

    cout << "Texto cifrado: " << cifrado << endl;

    return 0;
}
