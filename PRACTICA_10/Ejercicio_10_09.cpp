// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 10/11/2025
// Número de ejercicio: 9

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void escribir_mensaje();
void cifrar_mensaje_cesar();

int main()
{
    system("chcp 65001");
    system("cls");

    escribir_mensaje();
    cifrar_mensaje_cesar();

    return 0;
}

void escribir_mensaje()
{
    ofstream archivo_mensaje;
    string mensaje_usuario;

    archivo_mensaje.open("Ejercicio_10_09_MENSAJE.txt", ios::app);
    // ios::app permite que el nuevo texto se agregue al final del archivo.

    cout << "Escribir el mensaje que se desea cifrar: ";
    getline(cin, mensaje_usuario);
    archivo_mensaje << mensaje_usuario << endl;

    archivo_mensaje.close();
}

void cifrar_mensaje_cesar()
{
    ifstream archivo_original;
    ofstream archivo_cifrado;
    string linea_original;
    string linea_cifrada;
    char caracter_original;
    char caracter_cifrado;

    archivo_original.open("Ejercicio_10_09_MENSAJE.txt");
    archivo_cifrado.open("MENSAJE_CIFRADO.TXT");

    while (getline(archivo_original, linea_original))
    // Se lee el archivo original línea por línea.
    {
        linea_cifrada = "";
        // Se reinicia la variable para comenzar a construir la línea cifrada desde cero.

        for (int i = 0; i < linea_original.length(); i++)
        // Se recorre cada carácter de la línea original.
        {
            caracter_original = linea_original[i];
            caracter_cifrado = caracter_original + 3;
            linea_cifrada = linea_cifrada + caracter_cifrado;
        }

        archivo_cifrado << linea_cifrada << endl;
    }

    archivo_original.close();
    archivo_cifrado.close();
}