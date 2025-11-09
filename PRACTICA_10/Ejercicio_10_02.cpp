// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 07/11/2025
// Número de ejercicio: 2

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void leer_archivo_txt();

int main()
{
    system("chcp 65001");
    system("cls");

    cout << "TEXTO DENTRO DEL ARCHIVO" << endl;
    cout << endl;
    leer_archivo_txt();

    return 0;
}

void leer_archivo_txt()
{
    ifstream archivo;
    string texto;
    int cantidad_palabras = 0;
    bool dentro_de_palabra;
    // La variable bool indicará si se está dentro de una palabra.

    archivo.open("Ejercicio_10_02_TEXTO.txt");
    while (getline(archivo, texto))
    {
        cout << texto << endl;
        dentro_de_palabra = false;
        // Se reinicia el indicador al comenzar una nueva línea.
        for (int i = 0; i < texto.size(); i++)
        {
            if (texto[i] != ' ')
            // Si el carácter actual no es un espacio...
            {
                if (dentro_de_palabra == false)
                // Si aún no se está dentro de una palabra...
                {
                    cantidad_palabras = cantidad_palabras + 1;
                    // Se cuenta la nueva palabra.
                    dentro_de_palabra = true;
                    // Se marca que ahora sí se encuentra dentro de la palabra.
                }
            }
            else
            {
                dentro_de_palabra = false;
                // Si se encuentra un espacio, se sale de la palabra.
            }
        }
    }
    archivo.close();
    cout << endl;
    
    cout << "Cantidad de palabras dentro del archivo: " << cantidad_palabras << endl;
}