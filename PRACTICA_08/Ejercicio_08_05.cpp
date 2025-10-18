// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 17/10/2025
// Número de ejercicio: 5

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

void generar_numeros(vector<int>& numeros, int cantidad);
int suma_vector(vector<int>& numeros, int cantidad);

int main()
{
    system("chcp 65001");
    system("cls");

    int numero;
    int cantidad_numeros;
    vector<int> numeros;
    int suma_numeros;

    srand(time(0));

    cout << "Ingresar la cantidad de números que habrá en el vector: ";
    cin >> cantidad_numeros;

    generar_numeros(numeros, cantidad_numeros);
    for (int i = 0; i < cantidad_numeros; i++)
    {
        cout << numeros[i] << " ";
    }
    cout << endl;

    suma_numeros = suma_vector(numeros, cantidad_numeros - 1);
    // Como los índices van de 0 a n - 1, para acceder al último número del vector se debe poner cantidad_numeros - 1.
    cout << "La suma de números dentro del vector es: " << suma_numeros;

    return 0;
}

void generar_numeros(vector<int>& numeros, int cantidad)
{
    int numero;

    for (int i = 0; i < cantidad; i++)
    {
        numero = (rand() % 10) + 1;
        // Se generan números del 1 al 10 para ingresarlos al vector.
        numeros.push_back(numero);
    }
}

int suma_vector(vector<int>& numeros, int cantidad)
{
    if (cantidad < 0)
    // Caso base: si el índice es menor que 0, no hay más elementos para sumar.
    {
        return 0;
    }
    else
    {
        return numeros[cantidad] + suma_vector(numeros, cantidad - 1);
    }
}