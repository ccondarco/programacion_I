// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 03/10/2025
// Número de ejercicio: 1

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool ingreso_es_numero(string ingreso_usuario);
double calcular_promedio(vector<int> edades);
double calcular_desviacion(vector<int> edades, double promedio);

int main()
{
    system("chcp 65001");
    system("cls");

    vector<int> edades;
    string ingreso_usuario;
    int edad_numero = 0;
    double promedio;
    double desviacion;

    cout << "Ingresar edades. Escribir -1 para salir del programa:" << endl;

    while (edad_numero != -1)
    {
        getline(cin, ingreso_usuario);

        if (ingreso_es_numero(ingreso_usuario) == false)
        {
            cout << "Inválido. Escribir un número entero." << endl;
        }
        else
        {
            edad_numero = stoi(ingreso_usuario);

            if (edad_numero != -1)
            {
                if (edad_numero < 0)
                {
                    cout << "No se puede ingresar números negativos. Intentar de nuevo." << endl;
                }
                else
                {
                    edades.push_back(edad_numero);
                }
            }
        }
    }
    
    promedio = calcular_promedio(edades);
    desviacion = calcular_desviacion(edades, promedio);

    cout << "Edades ingresadas: ";
    for (int i = 0; i < edades.size(); i++)
    {
        cout << edades[i] << " ";
    }
    cout << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Desviación típica: " << desviacion;

    return 0;
}

bool ingreso_es_numero(string ingreso_usuario)
{
    int i = 0;
    // i es el contador.

    if (ingreso_usuario.length() == 0)
    // Se verifica si el usuario dejó el espacio en blanco.
    {
        return false;
    }
        
    if (ingreso_usuario[0] == '-')
    {
        if (ingreso_usuario.length() == 1)
        // Se verifica si el usuario ingresó solamente un guión.
        {
            return false;
        }
        i = 1;
        // i se vuelve 1 para descartar el guión si es que hay más caracteres después de éste.
    }
    
    while (i < ingreso_usuario.length())
    {
        if (ingreso_usuario[i] < '0' || ingreso_usuario[i] > '9')
        // Se verifica si el carácter actual no es un número utilizando la tabla ASCII.
        {
            return false;
        }
        i = i + 1;
    }

    return true;
}

double calcular_promedio(vector<int> edades)
{
    double suma = 0;
    double promedio;

    for (int i = 0; i < edades.size(); i++)
    {
        suma = suma + edades[i];
    }
    
    promedio = suma / edades.size();
    return promedio;
}

double calcular_desviacion(vector<int> edades, double promedio)
{
    double diferencia;
    double suma_desviaciones = 0;
    double desviacion;

    for (int i = 0; i < edades.size(); i++)
    {
        diferencia = edades[i] - promedio;
        suma_desviaciones = suma_desviaciones + (diferencia * diferencia);
    }

    desviacion = sqrt(suma_desviaciones / edades.size());
    return desviacion;
}