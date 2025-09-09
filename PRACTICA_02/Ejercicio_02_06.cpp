// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/09/2025
// Número de ejercicio: 6

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int cantidad = 0;
    int numero_generado = 0;
    int contador_divisores = 0;
    int cantidad_numeros_primos = 0;
    cout << "Ingresar cantidad de números aleatorios de 1 a 10000 que se desea generar: ";
    cin >> cantidad;
    srand(time(0));

    for (int i = 1; i <= cantidad; i++)
    // El primer bucle recorre la cantidad de números que se pidió al principio del programa.
    {
        numero_generado = (rand() % 10000) + 1;
        cout << "Número generado " << i << ": " << numero_generado << endl;

        contador_divisores = 0;

        for (int j = 2; j < numero_generado; j++)
        // El segundo bucle recorre desde 2 hasta el número-1 para contar divisores.
        {
            if (numero_generado % j == 0)
            {
                contador_divisores = contador_divisores + 1;
            }
        }

        if (contador_divisores == 0)
        // Si no se encontraron divisores, el número es primo.
        {
            cout << "El número generado " << i << " es primo." << endl;
            cantidad_numeros_primos = cantidad_numeros_primos + 1;
        }
    }
    
    cout << "Cantidad de números primos: " << cantidad_numeros_primos;
    return 0;
}