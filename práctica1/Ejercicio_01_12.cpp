// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 12

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 0;
    do
    // La sentencia dice que se repetirá el bucle si el valor ingresado es menor a 1 o mayor a 5.
    {
        cout << "Ingresar número del 1 al 5: ";
        cin >> numero;
    } while (numero < 1 || numero > 5);
    cout << "Valor válido.";
    return 0;
}