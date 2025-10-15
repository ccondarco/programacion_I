// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 14/10/2025
// Número de ejercicio: 5

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generar_matriz_1(int matriz[100][100], int filas, int columnas);
void generar_matriz_2(int matriz[100][100], int filas, int columnas);
void imprimir_matriz(int matriz[100][100], int filas, int columnas);
void multiplicar_matrices(int matriz_1[100][100], int matriz_2[100][100], int filas, int columnas);

int main()
{
	system("chcp 65001");
    system("cls");
    
    int filas_n;
    int columnas_m;
    int primera_matriz[100][100];
    int segunda_matriz[100][100];

    cout << "Ingresar cantidad de filas: ";
    cin >> filas_n;
    cout << "Ingresar cantidad de columnas: ";
    cin >> columnas_m;

    srand(time(0));

    generar_matriz_1(primera_matriz, filas_n, columnas_m);
    // Se genera una matriz de dimensiones N×M.
    cout << "Primera matriz:" << endl;
    imprimir_matriz(primera_matriz, filas_n, columnas_m);

    cout << endl;

    generar_matriz_2(segunda_matriz, columnas_m, filas_n);
    // Se genera una segunda matriz de dimensiones M×N, para que sea compatible al multiplicar.
    cout << "Segunda matriz:" << endl;
    imprimir_matriz(segunda_matriz, columnas_m, filas_n);

    cout << endl;

    cout << "Matriz multiplicada: " << endl;
    multiplicar_matrices(primera_matriz, segunda_matriz, filas_n, columnas_m);
    // Se realiza la multiplicación matriz_1(N×M) × matriz_2(M×N).

    
    return 0;
}

void generar_matriz_1(int matriz[100][100], int filas, int columnas)
{
    int valor;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            valor = (rand() % 10) + 1;
            matriz[i][j] = valor;
        }
    }
}

void generar_matriz_2(int matriz[100][100], int filas, int columnas)
{
    int valor;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            valor = (rand() % 10) + 1;
            matriz[i][j] = valor;
        }
    }
}

void imprimir_matriz(int matriz[100][100], int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplicar_matrices(int matriz_1[100][100], int matriz_2[100][100], int filas, int columnas)
{
    int multiplicacion[100][100];
    // La matriz que resultará de la multiplicación tendrá un tamaño de N×N (filas de matriz_1 × columnas de matriz_2)
    for (int i = 0; i < filas; i++)
    // Recorre filas de matriz_1
    {
        for (int j = 0; j < filas; j++)
        // Recorre columnas de matriz_2
        {
            multiplicacion[i][j] = 0;
            for (int k = 0; k < columnas; k++)
            // "k" recorre la cantidad de valores que se multiplican entre la fila de matriz_1 y la columna de matriz_2.
            {
                multiplicacion[i][j] = multiplicacion[i][j] + (matriz_1[i][k] * matriz_2[k][j]);
            }
            cout << multiplicacion[i][j] << " ";
        }
        cout << endl;
    }
}