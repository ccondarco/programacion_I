// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 15/10/2025
// Número de ejercicio: 1

#include <iostream>

using namespace std;

int suma_digitos(int numero);

int main()
{
    system("chcp 65001");
    system("cls");

    int numero;

    cout << "Ingresar número: ";
    cin >> numero;

    cout << suma_digitos(numero);
    return 0;
}

int suma_digitos(int numero)
{
    if (numero == 0)
    // Caso base: si el número es 0, se retorna 0.
    {
        return 0;
    }
    else
    // Paso recurrente: se extrae el último dígito (numero % 10) y se llama recursivamente con el resto del número (numero / 10).
    {
        return (numero % 10) + suma_digitos(numero / 10);
    }
}