// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 17

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int primer_numero = 0;
    int segundo_numero = 0;
    int divisores_primer_numero = 0;
    int divisores_segundo_numero = 0;
    cout << "Ingresar primer número: ";
    cin >> primer_numero;
    cout << "Ingresar segundo número: ";
    cin >> segundo_numero;
    // Los números amigos son parejas de números donde la suma de los divisores de cada uno es igual al otro número.
    for (int i=1; i<primer_numero; i++)
    // El bucle se utiliza para verificar cuáles son los divisores del primer número.
    {
        if (primer_numero%i == 0)
        // Si el número es divisor, se acumula en la variable de divisores.
        {
            divisores_primer_numero = divisores_primer_numero+i;
        }
    }
    for (int j=1; j<segundo_numero; j++)
    // El bucle se utiliza para verificar cuáles son los divisores del segundo número.
    {
        if (segundo_numero%j == 0)
        {
            divisores_segundo_numero = divisores_segundo_numero+j;
        }
    }
    if (primer_numero == divisores_segundo_numero && segundo_numero == divisores_primer_numero)
    // Se verifica si el primer número es igual a la suma de divisores del segundo número y viceversa.
    {
        cout << "Son números amigos.";
    }
    else
    {
        cout << "No son números amigos.";
    }
    return 0;
}