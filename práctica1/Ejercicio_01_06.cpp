// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 23/08/2025
// Número de ejercicio: 6

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 0;
    cout << "Ingresar número: ";
    cin >> numero;
    if (numero >= 0)
    // Se evalúa si el número es positivo, negativo o cero.
    {
        if (numero > 0)
        {
            cout << "Número positivo.";
        }
        else
        {
            cout << "Cero.";
        }
    }
    else
    {
        cout << "Número negativo.";
    }
    return 0;
}