// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 16

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 0;
    int contador_de_divisores = 0;
    cout << "Ingresar número: ";
    cin >> numero;
    // Un número primo solo se puede dividir por 1 y por sí mismo.
    if (numero > 1)
    // Se descartan los números menores a uno dado que no son primos.
    {
        for (int i=2; i<numero; i++)
        // El bucle recorre todos los números desde 2 hasta uno antes del número ingresado. Si se encuentra algún otro número que lo divida exacto, significa que no es primo.
        {
            if (numero%i == 0)
            {
                contador_de_divisores = contador_de_divisores + 1;
            }
        }
        if (contador_de_divisores == 0)
        // Si el contador de divisores quedó en cero, significa que el número es primo.
        {
            cout << "Es número primo.";
        }
        else
        {
            cout << "No es número primo.";
        }
    }
    else
    {
        cout << "No es número primo.";
    }
    return 0;
}