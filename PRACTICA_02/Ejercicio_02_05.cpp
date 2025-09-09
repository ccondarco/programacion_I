// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/09/2025
// Número de ejercicio: 5

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int cantidad = 0;
    int numero_generado = 0;
    float suma = 0.0;
    float promedio = 0.0;
    int mayor_valor = 0;
    int menor_valor = 0;

    cout << "Ingresar cantidad de números aleatorios de 1 a 1000 que se desea generar: ";
    cin >> cantidad;
    
    srand(time(0));
    numero_generado = (rand() % 1000) + 1;
    
    mayor_valor = numero_generado;
    menor_valor = numero_generado;
    
    for (int i = 0; i < cantidad; i++)
    {
        numero_generado = (rand() % 1000) + 1;
        cout << "Número generado: " << numero_generado << endl;
        suma = suma + numero_generado;
        promedio = suma / cantidad;
    
        if (numero_generado < menor_valor)
        {
            menor_valor = numero_generado;
            // Se actualiza el menor valor si el número generado es menor que el actual.
        }
        if (numero_generado > mayor_valor)
        {
            mayor_valor = numero_generado;
            // Se actualiza el mayor valor si el número generado es mayor que el actual.
        }
    }
    cout << "La sumatoria de todos los números generados es: " << suma << endl;
    cout << "El promedio de todos los números generados es: " << promedio << endl;
    cout << "El mayor valor entre todos los números generados es: " << mayor_valor << endl;
    cout << "El menor valor entre todos los números generados es: " << menor_valor << endl;
    return 0;
}