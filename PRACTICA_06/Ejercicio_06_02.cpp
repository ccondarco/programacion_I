// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 06/10/2025
// Número de ejercicio: 2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void buscar_mineral(vector<string> minerales, vector<double> produccion);
void mayor_a_menor(vector<string> minerales, vector<double> produccion);

int main()
{
    system("chcp 65001");
    system("cls");

    vector<string> minerales = {"AG", "AU", "CU", "PT", "SB", "SN"};
    vector<double> produccion = {135.567, 786.670, 109.412, 636.143, 876.500, 998.000};

    buscar_mineral(minerales, produccion);
    mayor_a_menor(minerales, produccion);

    return 0;
}

void buscar_mineral(vector<string> minerales, vector<double> produccion)
{
    string nombre_mineral;
    bool mineral_encontrado = false;

    cout << "Ingresar nombre del mineral: ";
    cin >> nombre_mineral;

    for (int i = 0; i < minerales.size(); i++)
    {
        if (nombre_mineral == minerales[i])
        {
            cout << produccion[i] << " toneladas métricas." << endl;
            mineral_encontrado = true;
        }
    }
    
    if (mineral_encontrado = false)
    // Si no se encuentra ninguna coincidencia, se notifica al usuario
    {
        cout << "Mineral no encontrado." << endl;
    }
    
}

void mayor_a_menor(vector<string> minerales, vector<double> produccion)
{
    vector<string> minerales_ordenados = minerales;
    vector<double> produccion_ordenada = produccion;
    string minerales_temporal;
    double produccion_temporal;

    for (int i = 0; i < produccion_ordenada.size() - 1; i++)
    {
        for (int j = 0; j < produccion_ordenada.size() - 1; j++)
        {
            if (produccion_ordenada[j] < produccion_ordenada[j+1])
            {
                produccion_temporal = produccion_ordenada[j];
                produccion_ordenada[j] = produccion_ordenada[j + 1];
                produccion_ordenada[j + 1] = produccion_temporal;

                minerales_temporal = minerales_ordenados[j];
                minerales_ordenados[j] = minerales_ordenados[j + 1];
                minerales_ordenados[j + 1] = minerales_temporal;
                // Se intercambian posiciones tanto en producción como en minerales para mantener la relación.
            }
        }
    }
    
    cout << "Mineral \t Producción" << endl;
    for (int i = 0; i < produccion_ordenada.size(); i++)
    {
        cout << minerales_ordenados[i] << " \t " << produccion_ordenada[i] << endl;
    }
}