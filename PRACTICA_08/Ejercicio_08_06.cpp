// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 17/10/2025
// Número de ejercicio: 6

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

void ingresar_datos(vector<int>& vector, int cantidad);
void imprimir_datos(vector<int> vector, int cantidad);
bool vectores_diferentes(vector<int> vector1, vector<int> vector2, int indice);

int main()
{
    system("chcp 65001");
    system("cls");

    vector<int> vector1;
    vector<int> vector2;
    int cantidad_numeros;
    int numero_vector;
    bool son_vectores_iguales;

    cout << "Ingresar la cantidad de números que tendrán los vectores: ";
    cin >> cantidad_numeros;

    ingresar_datos(vector1, cantidad_numeros);
    cout << endl;
    ingresar_datos(vector2, cantidad_numeros);
    cout << endl;

    imprimir_datos(vector1, cantidad_numeros);
    cout << endl;
    imprimir_datos(vector2, cantidad_numeros);
    cout << endl;

    son_vectores_iguales = vectores_diferentes(vector1, vector2, 0);

    if (son_vectores_iguales == true)
    {
        cout << "Son vectores iguales.";
    }
    else
    {
        cout << "Son vectores diferentes.";
    }
    
    return 0;
}

void ingresar_datos(vector<int>& vector, int cantidad)
{
    int numero;

    cout << "Ingresar números para el vector:" << endl;
    for (int i = 0; i < cantidad; i++)
    {
        cin >> numero;
        vector.push_back(numero);
    }
}

void imprimir_datos(vector<int> vector, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        cout << vector[i] << " ";
    }
}

bool vectores_diferentes(vector<int> vector1, vector<int> vector2, int indice)
{
    if (indice == vector1.size())
    // Caso base: si el índice es igual al tamaño del vector (vector.size() - 1), todos los elementos han sido comparados.
    {
        return true;
        // Si se llega al final sin diferencias, los vectores son iguales.
    }
    else
    {
        if (vector1[indice] != vector2[indice])
        // Si los elementos no coinciden, los vectores son diferentes.
        {
            return false;
        }
        else
        // Paso recursivo para comparar el siguiente número.
        {
            return vectores_diferentes(vector1, vector2, indice + 1);
        }
    }
}