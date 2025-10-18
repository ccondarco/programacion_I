// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 18/10/2025
// Número de ejercicio: 8

#include <iostream>

using namespace std;

int secuencia(int numero);

int main()
{
    system("chcp 65001");
    system("cls");

    int numero;
    do
    {
        cout << "Ingresar número: ";
        cin >> numero;
    } while (numero <= 1);
    
    secuencia(numero);
    
    return 0;
}

int secuencia(int numero)
{
    cout << numero << " ";
    // Imprime el número actual en la secuencia.

    if (numero == 1)
    // Caso base: si el número es 1, se termina la secuencia y se devuelve 1.
    {
        return 1;
    }
    else
    {
        if (numero % 2 == 0)
        // Paso recursivo si el número es par: se divide entre 2.
        {
            return secuencia(numero / 2);
        }
        else
        // Paso recursivo si el número es impar: se multiplica por 3 y se suma 1.
        {
            return secuencia((numero * 3) + 1);
        }
    }
}