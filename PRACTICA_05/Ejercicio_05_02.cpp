// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 01/10/2025
// Número de ejercicio: 2
// Problema planteado: Escribir un programa para introducir los valores y mostrarlos como una matriz.

#include <iostream>
#include <vector>

using namespace std;

void mostrar_matriz(vector<double> voltios);

int main()
{
    system("chcp 65001");
    system("cls");

    vector<double> voltios;
    
    voltios = {11.95, 16.32, 12.15, 8.22, 15.98, 26.22, 13.54, 6.45, 17.59};

    mostrar_matriz(voltios);
    
    return 0;
}

void mostrar_matriz(vector<double> voltios)
{
    for (int i = 0; i < voltios.size(); i++)
    {
        cout << voltios[i] << " ";
        if ((i + 1) % 3 == 0)
        // Después de imprimir los primeros tres números, habrá un salto de línea.
        {
            cout << endl;
        }
    }
}