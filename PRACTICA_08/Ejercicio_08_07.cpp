// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 18/10/2025
// Número de ejercicio: 7

#include <iostream>

using namespace std;

int suma(int numero);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad;
    int suma_potencias;

    cout << "Ingresar hasta qué número se desea realizar el ejercicio: ";
    cin >> cantidad;

    suma_potencias = suma(cantidad);

    cout << "La suma de potencias es: " << suma_potencias;

    return 0;
}

int suma(int numero)
{
    if (numero == 1)
    // Caso base: si el número es 1, la suma de potencias es 1.
    {
        return 1;
    }
    else
    // Paso recursivo: devuelve el cuadrado del número actual y llama recursivamente con "numero - 1".
    {
        return numero * numero + suma(numero - 1);
    }
}