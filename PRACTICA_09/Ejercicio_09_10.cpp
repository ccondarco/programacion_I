// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 03/11/2025
// Número de ejercicio: 10

#include <iostream>

using namespace std;

struct Fraccion
{
    int numerador;
    int denominador;
};

struct Fraccion_simplificada
{
    int numerador;
    int denominador;
};

int calcular_mcd(int valor1, int valor2);
Fraccion_simplificada reducir_fraccion(Fraccion fraccion);

int main()
{
    system("chcp 65001");
    system("cls");
    
    Fraccion fraccion;
    // Variable para almacenar la fracción original.
    Fraccion_simplificada simplificacion;
    // Variable para almacenar la fracción simplificada.
    
    cout << "Ingrese el numerador: ";
    cin >> fraccion.numerador;
    cout << "Ingrese el denominador: ";
    cin >> fraccion.denominador;

    simplificacion = reducir_fraccion(fraccion);

    cout << "La fracción simplificada es: " << simplificacion.numerador << "/" << simplificacion.denominador << endl;

    return 0;
}

int calcular_mcd(int valor1, int valor2)
// Para calcular el MCD, se utiliza una función de recursividad.
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

Fraccion_simplificada reducir_fraccion(Fraccion fraccion)
{
    Fraccion_simplificada fraccion_simplificada;;
    
    int mcd = calcular_mcd(fraccion.numerador, fraccion.denominador);

    fraccion_simplificada.numerador = fraccion.numerador / mcd;
    fraccion_simplificada.denominador = fraccion.denominador / mcd;

    return fraccion_simplificada;
}