// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 03/11/2025
// Número de ejercicio: 9

#include <iostream>
#include <vector>

using namespace std;

struct Notas_parciales_alumno
{
    int T1;
    int T2;
    int T3;
    int T4;
    int EF;
    float NP;
    float NF;
};

Notas_parciales_alumno ingresar_datos_alumno();
void ingresar_datos(vector<Notas_parciales_alumno>& alumnos, int cantidad);
void calcular_y_mostrar_notas_finales(vector<Notas_parciales_alumno>& alumnos);
void calcular_y_mostrar_resultados(vector<Notas_parciales_alumno> alumnos);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_alumnos;
    vector<Notas_parciales_alumno> alumnos;

    cout << "Ingresar cantidad de alumnos: ";
    cin >> cantidad_alumnos;

    ingresar_datos(alumnos, cantidad_alumnos);

    calcular_y_mostrar_notas_finales(alumnos);

    calcular_y_mostrar_resultados(alumnos);

    return 0;
}

Notas_parciales_alumno ingresar_datos_alumno()
{
    Notas_parciales_alumno alumno;

    cin.ignore();
    cout << "Ingresar nota T1: ";
    cin >> alumno.T1;
    cout << "Ingresar nota T2: ";
    cin >> alumno.T2;
    cout << "Ingresar nota T3: ";
    cin >> alumno.T3;
    cout << "Ingresar nota T4: ";
    cin >> alumno.T4;
    cout << "Ingresar nota EF: ";
    cin >> alumno.EF;

    return alumno;
}

void ingresar_datos(vector<Notas_parciales_alumno>& alumnos, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        alumnos.push_back(ingresar_datos_alumno());
        cout << endl;
    }
}

void calcular_y_mostrar_notas_finales(vector<Notas_parciales_alumno>& alumnos)
// Se vuelve a pasar el vector como valor por referencia para agregar las notas calculadas.
{
    for (int i = 0; i < alumnos.size(); i++)
    {
        alumnos[i].NP = (alumnos[i].T1 + alumnos[i].T2 + alumnos[i].T3 + alumnos[i].T4) / 4.0;
        // Se calcula la Nota de Presentación (NP) como el promedio de T1, T2, T3 y T4.
        alumnos[i].NF = (0.7 * alumnos[i].NP) + (0.3 * alumnos[i].EF);
        cout << "Nota final, alumno " << i + 1 << ": " << alumnos[i].NF << endl << endl;
    }
}

void calcular_y_mostrar_resultados(vector<Notas_parciales_alumno> alumnos)
{
    float suma_notas_finales = 0;
    float promedio;
    float nota_minima = 101;
    float nota_maxima = -1;

    for (int i = 0; i < alumnos.size(); i++)
    {
        suma_notas_finales = suma_notas_finales + alumnos[i].NF;
    }
    promedio = suma_notas_finales / alumnos.size();
    cout << "El promedio general de los alumnos es: " << promedio << endl << endl;

    for (int i = 0; i < alumnos.size(); i++)
    {
        if (alumnos[i].NF > nota_maxima)
        {
            nota_maxima = alumnos[i].NF;
        }
        else
        {
            if (alumnos[i].NF < nota_minima)
            {
                nota_minima = alumnos[i].NF;
            }
        }
    }
    cout << "La nota mínima entre los alumnos es: " << nota_minima << endl;
    cout << "La nota máxima entre los alumnos es: " << nota_maxima << endl;
}