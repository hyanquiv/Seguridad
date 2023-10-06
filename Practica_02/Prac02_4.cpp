#include <iostream>
#include <string>
#include <map>

using namespace std;

// Función para cifrar un mensaje usando el cifrado César
string cifradoCesar(string mensaje, int desplazamiento) {
    string cifrado = "";
    for (char caracter : mensaje) {
        if (isalpha(caracter)) {
            char base = isupper(caracter) ? 'A' : 'a';
            cifrado += char(((caracter - base + desplazamiento) % 26) + base);
        } else {
            cifrado += caracter;
        }
    }
    return cifrado;
}

// Función para cifrar un mensaje usando un cifrado de sustitución simple
string cifradoSustitucionSimple(string mensaje, const map<char, char>& clave) {
    string cifrado = "";
    for (char caracter : mensaje) {
        if (clave.find(caracter) != clave.end()) {
            cifrado += clave.at(caracter);
        } else {
            cifrado += caracter;
        }
    }
    return cifrado;
}

int main() {
    string mensaje;
    cout << "Introduce un mensaje: ";
    getline(cin, mensaje);

    int desplazamiento;
    cout << "Introduce el valor de desplazamiento para el cifrado César: ";
    cin >> desplazamiento;

    cin.ignore(); // Limpiar el buffer de entrada

    map<char, char> clave;
    // Definir una clave de sustitución simple
    clave['A'] = 'X';
    clave['B'] = 'Y';
    clave['C'] = 'Z';
    // Agregar más asignaciones según sea necesario

    string mensajeCifradoCesar = cifradoCesar(mensaje, desplazamiento);
    string mensajeCifradoSustitucion = cifradoSustitucionSimple(mensaje, clave);

    cout << "Mensaje cifrado en César: " << mensajeCifradoCesar << endl;
    cout << "Mensaje cifrado en Sustitución Simple: " << mensajeCifradoSustitucion << endl;

    return 0;
}
