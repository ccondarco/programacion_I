// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 18

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 100;
    int contador_de_divisores = 0;
    for (int i=2; i<=numero; i++)
    // Se realiza un bucle para recorrer cada número hasta 100. "i" en cada iteración será el dividendo.
    {
        contador_de_divisores = 0;
        // El contador se reinicia en cada repetición para que el contador de divisores no se acumule.
        for (int j=2; j<i; j++)
        // El segundo bucle recorre los números divisores de ¨i¨ desde 2 hasta i-1.
        // No se considera 1 ni ¨i¨ como divisores, ya que todos los números son divisibles por 1 y cada número es divisible por sí mismo.
        {
            if (i%j == 0)

            {
                contador_de_divisores = contador_de_divisores + 1;
            }
        }
    if (contador_de_divisores == 0)
    // Si no hay divisores, significa que es número primo.
    {
        cout << i << endl;
    }
    }
    return 0;
}
