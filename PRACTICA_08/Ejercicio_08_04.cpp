// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 17/10/2025
// Número de ejercicio: 4

#include <iostream>

using namespace std;

void reordenar_valores(int& valor1, int& valor2);
int calcular_mcd(int valor1, int valor2);

int main()
{
    system("chcp 65001");
    system("cls");

    int valor1;
    int valor2;
    int mcd;

    cout << "Ingresar primer valor: ";
    cin >> valor1;
    cout << "Ingresar segundo valor: ";
    cin >> valor2;

    if (valor2 > valor1)
    {
        reordenar_valores(valor1, valor2);
    }

    mcd = calcular_mcd(valor1, valor2);
    cout << "El máximo común divisor de los dos números es: " << mcd;
    return 0;
}

void reordenar_valores(int& valor1, int& valor2)
// Se reordenan los valores por si el segundo es mayor que el primero para que se pueda ejecutar el algoritmo de Euclides.
{
    int valor_temporal;

    if (valor2 > valor1)
    {
        valor_temporal = valor1;
        valor1 = valor2;
        valor2 = valor_temporal;
    }
}

int calcular_mcd(int valor1, int valor2)
{
    if (valor2 == 0)
    // Caso base: si el segundo número es 0, el MCD es el primero.
    {
        return valor1;
    }
    else
    // Paso recursivo: el residuo de valor1 % valor2 se convierte en el nuevo valor2.
    {
        return calcular_mcd(valor2, valor1 % valor2);
    }
}