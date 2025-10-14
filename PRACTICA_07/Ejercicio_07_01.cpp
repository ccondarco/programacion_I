// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 12/10/2025
// Número de ejercicio: 1

#include <iostream>
#include <vector>

using namespace std;

void introducir_datos(int numeros[100][100], int filas, int columnas);
void intercambiar_fila(int numeros[100][100], int columnas, int fila_a_cambiar);
void imprimir_matriz(int numeros[100][100], int filas, int columnas);

int main()
{
    system("chcp 65001");
    system("cls");

    int numeros[100][100];
    int filas;
    int columnas;
    int fila_a_cambiar;
    
    cout << "Igresar número de filas: ";
    cin >> filas;
    cout << "Ingresar número de columnas: ";
    cin >> columnas;

    introducir_datos(numeros, filas, columnas);
    cout << endl;

    imprimir_matriz(numeros, filas, columnas);
    cout << endl;

    cout << "Ingresar el número de fila que se desea cambiar por la fila 1: ";
    cin >> fila_a_cambiar;
    fila_a_cambiar = fila_a_cambiar - 1;
    // Se ajusta el número de fila dado que es probable que el usuario ingrese "0" como la fila 1.

    intercambiar_fila(numeros, columnas, fila_a_cambiar);
    
    cout << endl;

    imprimir_matriz(numeros, filas, columnas);

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

void intercambiar_fila(int numeros[100][100], int columnas, int fila_a_cambiar)
{
    int posicion_temporal;

    for (int j = 0; j < columnas; j++)
    {
        posicion_temporal = numeros[0][j];
        numeros[0][j] = numeros[fila_a_cambiar][j];
        numeros[fila_a_cambiar][j] = posicion_temporal;
    }
}

void imprimir_matriz(int numeros[100][100], int filas, int columnas)
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