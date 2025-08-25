// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 13

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 0;
    int suma = 0;
    cout << "Ingresar número: ";
    cin >> numero;
    for (int i = 1; i <= numero; i++)
    // El ciclo for ordena que se sumen todos los números en bucles desde el número 1 hasta el número ingresado.
    {
        suma = suma + i;
    }
    cout << suma;
    return 0;
}