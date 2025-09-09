// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/09/2025
// Número de ejercicio: 3

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 0;
    int factorial = 1;
    // Se inicializa la semilla para generar números aleatorios.

    srand(time(0));
    numero = (rand() % 10 ) + 1;
    // Se genera un número aleatorio entre 1 y 10.
    cout << "Número aleatorio del 1 al 10: " << numero << endl;
    
    for (int i = 1; i <= numero; i++)
    {
        factorial = factorial * i;
    }
    
    cout << "El factorial de " << numero << " : " << factorial;
    return 0;
}