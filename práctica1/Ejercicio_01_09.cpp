// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 23/08/2025
// Número de ejercicio: 9

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int edad = 0;
    cout << "Ingresar edad: ";
    cin >> edad;
    if (edad > 12)
    // La condición descarta si la persona es niño (edad menor o igual a 12)
    {
        if (edad > 18)
        // La condición descarta si la persona es adolescente (edad menor o igual a 18)
        {
            if (edad < 60)
            // La condición descarta si la persona es adulto mayor (edad mayor o igual a 60)
            {
                cout << "Es mayor de edad.";
            }
            else
            {
                cout << "Es adulto mayor.";
            }
        }
        else
        {
            cout << "Es adolescente.";
        }
    }
    else
    {
        cout << "Es niño.";
    }
    return 0;
}