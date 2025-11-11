// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 11/11/2025
// Número de ejercicio: 8

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void leer_archivo_txt();
void contar_elementos();

int main()
{
    system("chcp 65001");
    system("cls");

    cout << "CONTENIDO DEL ARCHIVO:" << endl;
    cout << endl;

    leer_archivo_txt();

    cout << endl;
    contar_elementos();

    return 0;
}

void leer_archivo_txt()
{
    ifstream archivo;
    string texto;

    archivo.open("Ejercicio_10_08_DOCUMENTO.txt");

    while (getline(archivo, texto))
    {
        cout << texto << endl;
    }

    archivo.close();
}

// Función que cuenta líneas, palabras y caracteres
void contar_elementos()
{
    ifstream archivo;
    string texto;
    int cantidad_palabras = 0;
    int cantidad_lineas = 0;
    int cantidad_caracteres = 0;
    bool dentro_de_palabra = false;
    char caracter;

    archivo.open("Ejercicio_10_08_DOCUMENTO.txt");

    while (getline(archivo, texto))
    // Se lee el archivo línea por línea.
    {
        cantidad_lineas = cantidad_lineas + 1;
        // Cada getline representa una nueva línea.
        dentro_de_palabra = false;
        // Se reinicia al comienzo de cada línea.

        for (int i = 0; i < texto.size(); i++)
        // Recorre todos los caracteres dentro de la línea actual.
        {
            caracter = texto[i];
            cantidad_caracteres = cantidad_caracteres + 1;
            // Cuenta cada caraácter visible.

            if (caracter != ' ' && caracter != '\n')
            // Si el carácter no es un espacio ni salto de línea, podría ser parte de una palabra.
            {
                if (dentro_de_palabra == false)
                // Si antes no se estaba dentro de una palabra, significa que una nueva comienza.
                {
                    cantidad_palabras = cantidad_palabras + 1;
                    dentro_de_palabra = true;
                    // Marca que ahora sí se está dentro de una palabra.
                }
            }
            else
            {
                dentro_de_palabra = false;
                // Si se encuentra un espacio o salto, la palabra actual termina.
            }
        }
    }

    archivo.close();

    cout << "Líneas: " << cantidad_lineas << endl;
    cout << "Palabras: " << cantidad_palabras << endl;
    cout << "Caracteres: " << cantidad_caracteres << endl;
}