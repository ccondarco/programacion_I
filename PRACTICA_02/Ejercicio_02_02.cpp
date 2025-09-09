// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 04/09/2025
// Número de ejercicio: 2

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int cantidad = 0;
    int moneda = 0;
    int cantidad_caras = 0;
    int cantidad_cruces = 0;
    int porcentaje_caras = 0;
    int porcentaje_cruces = 0;

    cout << "Ingresar la cantidad de veces que se desea lanzar la moneda: ";
    cin >> cantidad;

    srand(time(0));

    for (int i = 0; i < cantidad; i++)
    {
        moneda = (rand() % 2) + 1;
        cout << moneda << endl;
        // Cara = 1
        // Cruz = 2
        if (moneda == 1)
        {
            cantidad_caras = cantidad_caras + 1;
        }
        else
        {
            cantidad_cruces = cantidad_cruces + 1;
        }
    }

    porcentaje_caras = ((cantidad_caras) * 100) / cantidad;
    porcentaje_cruces = ((cantidad_cruces) * 100) / cantidad;

    cout << "El porcentaje de veces que salió cara es de " << porcentaje_caras << "%." << endl;
    cout << "El porcentaje de veces que salió cruz es de " << porcentaje_cruces << "%." << endl;
    
    return 0;
}