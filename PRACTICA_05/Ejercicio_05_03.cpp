// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 01/10/2025
// Número de ejercicio: 3
// Problema planteado: Escribir un programa que permita ingresar N calificaciones, calculando la suma total, el promedio, la desviación de cada calificación, y la varianza.


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double suma(int cantidad, vector<int> calificaciones);
double promedio(int cantidad, double calificaciones);
vector<double> calcular_desviaciones(vector<int> calificaciones, double promedio);
void desplegar_desviaciones(vector<double>desviaciones, vector<int> calificaciones);
double calcular_varianza(vector<double> desviaciones);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_calificaciones;
    int calificacion;
    vector<int> calificaciones;
    double suma_calificaciones;
    double promedio_calificaciones;
    vector<double> desviaciones;
    double varianza;

    cout << "Ingresar la cantidad de calificaciones: ";
    cin >> cantidad_calificaciones;

    for (int i = 0; i < cantidad_calificaciones; i++)
    {
        cout << "Ingresar la calificación " << i + 1 << ": ";
        cin >> calificacion;
        calificaciones.push_back(calificacion);
    }
    
    cout << endl;

    suma_calificaciones = suma(cantidad_calificaciones, calificaciones);
    cout << "La suma de calificaciones es: " << suma_calificaciones << endl;

    cout << endl;
    
    promedio_calificaciones = promedio(cantidad_calificaciones, suma_calificaciones);
    cout << "El promedio de calificaciones es: " << promedio_calificaciones << endl;

    cout << endl;

    desviaciones = calcular_desviaciones(calificaciones, promedio_calificaciones);
    cout << "Desviaciones:" << endl;
    desplegar_desviaciones(desviaciones, calificaciones);

    varianza = calcular_varianza(desviaciones);
    cout << "La varianza es: " << varianza << endl;

    return 0;
}

double suma(int cantidad, vector<int> calificaciones)
{
    double suma = 0.0;
    for (int i = 0; i < cantidad; i++)
    {
        suma = suma + calificaciones[i];
    }
    return suma;
}

double promedio(int cantidad, double suma)
{
    double promedio;
    promedio = suma / cantidad;
    return promedio;
}

vector<double> calcular_desviaciones(vector<int> calificaciones, double promedio)
{
    double desviacion;
    vector<double> desviaciones;
    for (int i = 0; i < calificaciones.size(); i++)
    {
        desviacion = calificaciones[i] - promedio;
        desviaciones.push_back(desviacion);
    }
    return desviaciones;
}

void desplegar_desviaciones(vector<double>desviaciones, vector<int> calificaciones)
{
    for (int i = 0; i < calificaciones.size(); i++)
    {
        cout << "Calificación: " << calificaciones[i] << "\t Desviación: " << desviaciones[i] << endl;
    }
}

double calcular_varianza(vector<double> desviaciones)
{
    double suma_cuadrados = 0.0;
    double varianza;
    for (int i = 0; i < desviaciones.size(); i++)
    {
        suma_cuadrados = suma_cuadrados + pow(desviaciones[i], 2);
    }
    varianza = suma_cuadrados / (desviaciones.size() - 1);
    // Se calcula la varianza dividiendo entre (n - 1) para obtener una varianza muestral y no una poblacional.
    return varianza;
}