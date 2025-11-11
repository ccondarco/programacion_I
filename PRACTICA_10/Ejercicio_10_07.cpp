// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 10/11/2025
// Número de ejercicio: 7

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
// Librería necesaria para usar stringstream.

using namespace std;

void leer_archivo_txt(vector<string>& lineas_de_texto);
vector<double> calcular_promedios(vector<string>& lineas_de_texto, vector<string>& nombres_estudiantes);
void crear_archivo_promedios(vector<string> estudiantes, vector<double> promedios);

int main()
{
    system("chcp 65001");
    system("cls");

    vector<string> lineas_de_texto;
    vector<string> nombres_estudiantes;
    vector<double> promedios;

    leer_archivo_txt(lineas_de_texto);

    promedios = calcular_promedios(lineas_de_texto, nombres_estudiantes);

    crear_archivo_promedios(nombres_estudiantes, promedios);

    return 0;
}

void leer_archivo_txt(vector<string>& lineas_de_texto)
{
    ifstream archivo;
    string linea_de_texto;

    archivo.open("Ejercicio_10_07_CALIFICACIONES.txt");
    while (getline(archivo, linea_de_texto))
    {
        cout << linea_de_texto << endl;
        lineas_de_texto.push_back(linea_de_texto);
    }
    archivo.close();
}

vector<double> calcular_promedios(vector<string>& lineas_de_texto, vector<string>& nombres_estudiantes)
{
    vector<double> promedios;
    string palabra;
    string linea_actual;
    stringstream lector_de_palabras;
    // Stringstream se usará para leer una línea palabra por palabra y dividir cada palabra (o número) por espacios.
    
    string nombre;
    double nota;
    double suma_notas = 0.0;
    int contador_palabras = 1;
    double promedio;

    for (int i = 0; i < lineas_de_texto.size(); i++)
    {
        linea_actual = lineas_de_texto[i];
        stringstream lector_de_palabras(linea_actual);
        // Stringstream permite leer las partes de la línea como si fueran palabras separadas por espacios. Divide las palabras de la línea actual de acuerdo a sus espacios.
        // Aquí se inicializa una vez más dentro del bucle porque si se hiciera antes, causaría error.

        suma_notas = 0.0;
        contador_palabras = 1;
        // Las variables se reinician para cada estudiante.
        
        while (getline(lector_de_palabras, palabra, ' '))
        // El bucle permite que lector_de_palabras vaya leyendo la línea actual palabra por palabra y cada que encuentre un espacio (' '), guarda la palabra dentro de la variable "palabra".
        // El tercer parámetro (' ') funciona como el delimitador, es decir, lee la línea hasta encontrar un espacio.
        {
            if(contador_palabras == 1)
            // La primera palabra siempre es el nombre del estudiante.
            {
                nombres_estudiantes.push_back(palabra);
            }
            else
            // Las demás palabras son números.
            {
                nota = stod(palabra);
                // stod convierte un número tipo string a un número tipo double.
                suma_notas = suma_notas + nota;
            }
            contador_palabras = contador_palabras + 1;
            // El contador avanza después de cada palabra leída.
        }

        promedio = suma_notas / 4.0;
        promedios.push_back(promedio);
    }
    return promedios;
}

void crear_archivo_promedios(vector<string> estudiantes, vector<double> promedios)
{
    ofstream archivo_promedios;

    archivo_promedios.open("PROMEDIOS.TXT");
    for (int i = 0; i < estudiantes.size(); i++)
    {
        archivo_promedios << estudiantes[i] << " " << promedios[i] << endl;
    }

    archivo_promedios.close();
}