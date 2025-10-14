// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/10/2025
// Número de ejercicio: 2

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void generar_numeros_al_azar(int matriz[100][100], int filas, int columnas);
void imprimir_matriz(int matriz[100][100], int filas, int columnas);
int suma_de_columna(int matriz[100][100], int filas, int columnas);
int producto_de_fila(int matriz[100][100], int filas, int columnas);
void mayor_valor(int matriz[100][100], int filas, int columnas);
double calcular_desviacion(int matriz[100][100], int filas, int columnas);

int main()
{
    system("chcp 65001");
    system("cls");

    int matriz[100][100];
    int filas;
    int columnas;
    int suma_columna;
    int producto_fila;
    double desviacion_matriz;

    cout << "Ingresar número de filas de la matriz: ";
    cin >> filas;

    cout << "Ingresar número de columnas de la matriz: ";
    cin >> columnas;
    
    srand(time(0));

    generar_numeros_al_azar(matriz, filas, columnas);
  
    imprimir_matriz(matriz, filas, columnas);

    suma_columna = suma_de_columna(matriz, filas, columnas);
    cout << "La suma de los números de la última columna es: " << suma_columna << endl;

    producto_fila = producto_de_fila(matriz, filas, columnas);
    cout << "El producto de los números de la última fila es: " << producto_fila << endl;

    mayor_valor(matriz, filas, columnas);
    cout << endl;

    desviacion_matriz = calcular_desviacion(matriz, filas, columnas);
    cout << "La desviación típica de los números es: " << desviacion_matriz << endl;

    return 0;
}

void generar_numeros_al_azar(int matriz[100][100], int filas, int columnas)
{
    int numero;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            numero = rand() % 101;
            // El rango de números a generar será de 0 a 100.
            matriz[i][j] = numero;
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

int suma_de_columna(int matriz[100][100], int filas, int columnas)
{
    int suma = 0;

    for (int i = 0; i < filas; i++)
    {
        suma = suma + matriz[i][columnas - 1];
    }

    return suma;
}

int producto_de_fila(int matriz[100][100], int filas, int columnas)
{
    int producto = 1;

    for (int j = 0; j < columnas; j++)
    {
        producto = producto * matriz[filas - 1][j];
    }

    return producto;
}

void mayor_valor(int matriz[100][100], int filas, int columnas)
{
    int mayor_valor = 0;
    int posicion_fila;
    int posicion_columna;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (matriz[i][j] > mayor_valor)
            {
                mayor_valor = matriz[i][j];
                posicion_fila = i;
                posicion_columna = j;
            }
        }
    }
    cout << "El mayor valor en la matriz es " << mayor_valor << " y se encuentra en la posición [" << posicion_fila << "][" << posicion_columna << "]";
}

double calcular_desviacion(int matriz[100][100], int filas, int columnas)
{
    double diferencia = 0.0;
    double suma_desviaciones = 0.0;
    double suma_numeros_matriz = 0.0;
    double cantidad_numeros_matriz;
    double promedio;
    double desviacion;
    
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            suma_numeros_matriz = suma_numeros_matriz + matriz[i][j];
        }
    }
    cantidad_numeros_matriz = filas * columnas;

    promedio = suma_numeros_matriz / cantidad_numeros_matriz;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            diferencia = matriz[i][j] - promedio;
            suma_desviaciones = suma_desviaciones + (diferencia * diferencia);
        }
    }

    desviacion = sqrt(suma_desviaciones / cantidad_numeros_matriz);

    return desviacion;
}