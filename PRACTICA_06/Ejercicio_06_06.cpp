// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/10/2025
// Número de ejercicio: 6

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void generar_calificaciones(vector<int>& calificaciones, int cantidad);
void clasificar_y_mostrar_calificaciones(vector<int> calificaciones);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_estudiantes;
    vector<int> calificaciones;

    cout << "Ingresar cantidad de estudiantes: ";
    cin >> cantidad_estudiantes;

    srand(time(0));

    generar_calificaciones(calificaciones, cantidad_estudiantes);
    clasificar_y_mostrar_calificaciones(calificaciones);

    return 0;
}

void generar_calificaciones(vector<int>& calificaciones, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        int calificacion;
        calificacion = rand() % 101;
        calificaciones.push_back(calificacion);
    }

    cout << "Calificaciones generadas: ";
    for (int i = 0; i < calificaciones.size(); i++)
    {
        cout << calificaciones[i] << " ";
    }
    cout << endl << endl;
}

void clasificar_y_mostrar_calificaciones(vector<int> calificaciones)
{
    int calificacion;
    int reprobados = 0;
    int regulares = 0;
    int buenos = 0;
    int excelentes = 0;
    int total_calificaciones = 0;
    double porcentaje_reprobados;
    double porcentaje_regulares;
    double porcentaje_buenos;
    double porcentaje_excelentes;

    for (int i = 0; i < calificaciones.size(); i++)
    // Se recorre por todas las calificaciones para clasificarlas.
    {
        calificacion = calificaciones[i];
        if (calificacion >= 0)
        {
            if (calificacion <= 59)
            {
                reprobados = reprobados + 1;
            }
            else
            {
                if (calificacion <= 79)
                {
                    regulares = regulares + 1;
                }
                else
                {
                    if (calificacion <= 89)
                    {
                        buenos = buenos + 1;
                    }
                    else
                    {
                        if (calificacion <= 100)
                        {
                            excelentes = excelentes + 1;
                        }
                    }
                }
            }
        }
    }

    total_calificaciones = calificaciones.size();
    
    porcentaje_reprobados = (reprobados * 100) / total_calificaciones;
    porcentaje_regulares = (regulares * 100) / total_calificaciones;
    porcentaje_buenos = (buenos * 100) / total_calificaciones;
    porcentaje_excelentes = (excelentes * 100) / total_calificaciones;

    cout << "Reprobados: " << porcentaje_reprobados << "%" << endl;
    cout << "Regulares: " << porcentaje_regulares << "%" << endl;
    cout << "Buenos: " << porcentaje_buenos << "%" << endl;
    cout << "Excelentes: " << porcentaje_excelentes << "%" << endl;
}