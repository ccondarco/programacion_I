// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 15/10/2025
// Número de ejercicio: 2

#include <iostream>

using namespace std;

int calcular_potencia(int base, int exponente);

int main()
{
    system("chcp 65001");
    system("cls");

    int base_a;
    int exponente_n;

    cout << "Ingresar base: ";
    cin >> base_a;
    cout << "Ingresar exponente: ";
    cin >> exponente_n;

    cout << "La potencia de " << base_a << " elevado a " << exponente_n << " es: " << calcular_potencia(base_a, exponente_n);
    return 0;
}

int calcular_potencia(int base, int exponente)
{
    int potencia;

    if (exponente == 1)
    // Caso base: cualquier número elevado a 1 es él mismo.
    {
        return base;
    }
    else
    // Paso recurrente: se multiplica la base por la potencia de (exponente - 1).
    {
        return potencia = base * calcular_potencia(base, exponente - 1);
    }
}