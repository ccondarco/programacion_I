// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 14/10/2025
// Número de ejercicio: 4

#include <iostream>

using namespace std;

void generar_matriz(int matriz[100][100], int dimension);
void imprimir_matriz(int matriz[100][100], int dimension);

int main()
{
	system("chcp 65001");
    system("cls");
    
    int dimension_matriz;
	int matriz[100][100];
	
	cout << "Ingresar dimensión de la matriz: ";
	cin >> dimension_matriz;
	
	generar_matriz(matriz, dimension_matriz);
    imprimir_matriz(matriz, dimension_matriz);
	
	return 0;
}

void generar_matriz(int matriz[100][100], int dimension)
{
    int inicio;
    for (int i = 0; i < dimension; i++)
    {
        inicio = 1 + (i * 2);
        // Cada fila comienza en un número impar diferente.
        for (int j = 0; j < dimension; j++)
        {
            matriz[i][j] = inicio + j;
            // Luego se incrementa de 1 en 1 dentro de la fila.
        }
    }
}

void imprimir_matriz(int matriz[100][100], int dimension)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
