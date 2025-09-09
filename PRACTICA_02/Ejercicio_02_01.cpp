// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 04/09/2025
// Número de ejercicio: 1

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 0;
    int cantidad = 0;
    int contador_pares = 0;

    cout << "Ingresar la cantidad de veces que se desea lanzar el dado: ";
    cin >> cantidad;
    
    srand(time(0));
    // Semilla para los números aleatorios.

    for (int i = 1; i <= cantidad; i++)
    {
        numero = (rand() % 6) + 1;
        // Se pide generar un número aleatorio entre 1 y 6.
        cout << numero << endl;
        if (numero % 2 == 0)
        {
            contador_pares = contador_pares + 1;
        }
    }

    cout << "La frecuencia de repetición de caras pares es de " << contador_pares << " de " << cantidad;
    return 0;
}