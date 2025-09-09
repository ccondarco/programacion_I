// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 06/09/2025
// Número de ejercicio: 3

#include <iostream>
using namespace std;

int invertir_numero (int valor);
// Función que invertirá el número original.
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 0;

    cout << "Ingresar número: ";
    cin >> numero;

    if (numero == invertir_numero(numero))
    {
        cout << "El número ingresado es capicúa.";
    }
    else
    {
        cout << "El número ingresado no es capicúa.";
    }

    return 0;
}

int invertir_numero (int valor)
// Para poder determinar si un número es capicúa sin saber cuántos dígitos tendrá, la mejor solución es invertirlo.
{
    int digito_sacado = 0;
    int numero_invertido = 0;

    while (valor > 0)
    {
        digito_sacado = valor % 10;
        numero_invertido = numero_invertido * 10;
        numero_invertido = numero_invertido + digito_sacado;
        valor = valor / 10;
    }
    return numero_invertido;
}