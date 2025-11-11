// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/11/2025
// Número de ejercicio: 6

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void leer_archivo_txt(vector<string>& lineas_de_texto);
void crear_archivo_altas_temperaturas(vector<string> lineas_de_texto, float temperatura_filtro);
void filtrar_temperaturas(string& linea_de_texto, string& ciudad, float& temperatura);

int main()
{
    system("chcp 65001");
    system("cls");

    float temperatura_filtro;
    vector<string> lineas_de_texto;

    leer_archivo_txt(lineas_de_texto);
    cout << endl;
    
    cout << "Ingresar temperatura para filtrar: ";
    cin >> temperatura_filtro;

    crear_archivo_altas_temperaturas(lineas_de_texto, temperatura_filtro);

    return 0;
}

void leer_archivo_txt(vector<string>& lineas_de_texto)
{
    ifstream archivo;
    string linea_de_texto;

    archivo.open("Ejercicio_10_06_TEMPERATURAS.txt");
    while (getline(archivo, linea_de_texto))
    {
        cout << linea_de_texto << endl;
        lineas_de_texto.push_back(linea_de_texto);
    }
    archivo.close();
}

void crear_archivo_altas_temperaturas(vector<string> lineas_de_texto, float temperatura_filtro)
{
    ofstream archivo_altas_temperaturas;
    string ciudad;
    float temperatura = 0.0;
    // Se inicializan las variables ciudad y temperatura para poder escribirlas en el nuevo archivo.
    // Para guardar el valor númerico de temperatura, se incializa una variable float.

    archivo_altas_temperaturas.open("TEMPERATURAS.TXT");

    for (int i = 0; i < lineas_de_texto.size(); i++)
    {
        filtrar_temperaturas(lineas_de_texto[i], ciudad, temperatura);
        // La función separará la ciudad y la temperatura de la línea actual.
        if (temperatura > temperatura_filtro)
        {
            archivo_altas_temperaturas << ciudad << " " << temperatura << endl;
            // Si la temperatura es mayor al filtro, se la escribe en el nuevo archivo.
        }
    }

    archivo_altas_temperaturas.close();
}

void filtrar_temperaturas(string& linea_de_texto, string& ciudad, float& temperatura)
{
    string temperatura_string = "";
    // Se guarda la temperatura como texto.
    int espacio_ultima_palabra = -1;

    ciudad = "";
    // Se vacía la variable ciudad para llenarla de nuevo.

    for (int i = 0; i < linea_de_texto.length(); i++)
    // Se busca la posición del último espacio en la línea.
    {
        if (linea_de_texto[i] == ' ')
        {
            espacio_ultima_palabra = i;
            // Se actualiza la posición del último espacio encontrado.
        }
    }
    
    for (int i = 0; i < linea_de_texto.length(); i++)
    // Se recorre la línea nuevamente para separar la ciudad y la temperatura.
    {
        if (i <= espacio_ultima_palabra)
        {
            ciudad = ciudad + linea_de_texto[i];
            // Si la posición actual está antes o en el espacio, pertenece al nombre de la ciudad.
        }
        else
        {
            temperatura_string = temperatura_string + linea_de_texto[i];
            // Si la posición actual está después del último espacio, pertenece a la temperatura.
        }
    }
    
    temperatura = stof(temperatura_string);
    // Se convierte la temperatura que estaba en texto a número flotante.
}