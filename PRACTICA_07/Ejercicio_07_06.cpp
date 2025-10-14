// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 12/10/2025
// Número de ejercicio: 6

#include <iostream>
#include <vector>

using namespace std;

void introducir_datos(int numeros[100][100], int filas, int columnas);
void imprimir_matriz_original(int numeros[100][100], int filas, int columnas);
void imprimir_matriz_transpuesta(int numeros[100][100], int filas, int columnas);

int main()
{
    system("chcp 65001");
    system("cls");

    int numeros[100][100];
    int filas;
    int columnas;

    cout << "Igresar número de filas: ";
    cin >> filas;
    cout << "Ingresar número de columnas: ";
    cin >> columnas;

    introducir_datos(numeros, filas, columnas);

    cout << "Matriz original:" << endl;
    imprimir_matriz_original(numeros, filas, columnas);
    cout << endl;

    cout << "Matriz transpuesta:" << endl;
    imprimir_matriz_transpuesta(numeros, filas, columnas);
    
    return 0;
}

void introducir_datos(int numeros[100][100], int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "Ingresar número para posición [" << i << "][" << j << "]: ";
            cin >> numeros[i][j];
        }
    }
}

void imprimir_matriz_original(int numeros[100][100], int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << numeros[i][j];
        }
        cout << endl;
    }
}

void imprimir_matriz_transpuesta(int numeros[100][100], int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << numeros[j][i];
            // Se transpone la matriz simplemente cambiando las posiciones de i y j.
        }
        cout << endl;
    }
}