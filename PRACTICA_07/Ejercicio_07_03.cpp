// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/10/2025
// Número de ejercicio: 3

#include <iostream>
#include <vector>

using namespace std;

void mostrar_matriz(char matriz[3][4]);
int filas_libres(char matriz[3][4]);
int columnas_libres(char matriz[3][4]);
vector<pair<int, int>> coordenadas(char matriz[3][4]);

int main()
{
    system("chcp 65001");
    system("cls");

    char matriz[3][4] = {'x', 'o', 'x', 'o',
                         'o', 'o', 'o', 'o',
                         'o', 'o', 'x', 'o'};
    int filas_sin_muertos;
    int columnas_sin_muertos;
    vector<pair<int, int>> muertos_vivientes;
    
    cout << "a) Matriz" << endl;
    mostrar_matriz(matriz);
    cout << endl;

    cout << "b) Filas y columnas libres" << endl;
    filas_sin_muertos = filas_libres(matriz);
    columnas_sin_muertos = columnas_libres(matriz);
    cout << "Número de filas sin muertos vivientes: " << filas_sin_muertos << endl;
    cout << "Número de columnas sin muertos vivientes: " << columnas_sin_muertos << endl;
    cout << endl;

    cout << "c) Coordenadas de los muertos vivientes" << endl;
    muertos_vivientes = coordenadas(matriz);
    for (int i = 0; i < muertos_vivientes.size(); i++)
    {
        cout << "[" << muertos_vivientes[i].first << "][" << muertos_vivientes[i].second << "]" << endl;
    }
    cout << endl;
    
    cout << "d) Cantidad de muertos vivientes" << endl;

    cout << "e) Posibilidad de entrar al complejo" << endl;

    return 0;
}

void mostrar_matriz(char matriz[3][4])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int filas_libres(char matriz[3][4])
{
    int filas_libres = 0;
    int muertos_vivientes = 0;

    for (int i = 0; i < 3; i++)
    {
        muertos_vivientes = 0;
        for (int j = 0; j < 4; j++)
        {
            if (matriz[i][j] == 'x')
            {
                muertos_vivientes = muertos_vivientes + 1;
            }
        }
        
        if (muertos_vivientes == 0)
        {
            filas_libres = filas_libres + 1;
        }
    }
    return filas_libres;
}

int columnas_libres(char matriz[3][4])
{
    int columnas_libres = 0;
    int muertos_vivientes = 0;

    for (int j = 0; j < 4; j++)
    {
        muertos_vivientes = 0;
        for (int i = 0; i < 3; i++)
        {
            if (matriz[i][j] == 'x')
            {
                muertos_vivientes = muertos_vivientes + 1;
            }    
        }

        if (muertos_vivientes == 0)
        {
            columnas_libres = columnas_libres + 1;
        }
    }
    return columnas_libres;
}

vector<pair<int, int>> coordenadas(char matriz[3][4])
{
    vector<pair<int, int>> muertos_vivientes;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (matriz[i][j] == 'x')
            {
                muertos_vivientes.push_back({i, j});
            }
        }
    }
    return muertos_vivientes;
}

