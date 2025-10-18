// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 17/10/2025
// Número de ejercicio: 3

#include <iostream>

using namespace std;

int fibonacci(int valor);

int main()
{
    system("chcp 65001");
    system("cls");

    int secuencia_fibonacci;
    int numero_indice;

    cout << "Ingresar cuántos números generar en la secuencia Fibonacci: ";
    cin >> numero_indice;

    for (int i = 0; i < numero_indice; i++)
    {
        cout << fibonacci(i) << " ";
    }
    return 0;
}

int fibonacci(int valor)
{
    if (valor == 0 || valor == 1)
    // Casos base: si el número es 0 o 1, se devuelve el mismo número.
    {
        return valor;
    }
    else
    // Paso recursivo: se suman los dos valores anteriores en la secuencia.
    {
        return fibonacci(valor - 1) + fibonacci(valor - 2);
    }
}