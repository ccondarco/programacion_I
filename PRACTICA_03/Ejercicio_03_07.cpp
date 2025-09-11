// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/09/2025
// Número de ejercicio: 7

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int generar_edad();
// La función ayudará a generar edades.
int generar_estatura();
// La función ayudará a generar estaturas.
float calcular_promedio(float suma, float cantidad);
// La función ayudará a calcular el promedio a partir de los datos proporcionados.

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_alumnos = 0;
    int edad = 0;
    int estatura = 0;
    float suma_edades = 0.0;
    float suma_estaturas = 0.0;
    int alumnos_mayores_a_18 = 0;
    int alumnos_mas_altos_175 = 0;

    cout << "Ingresar cantidad de alumnos: ";
    cin >> cantidad_alumnos;

    srand(time(0));

    for (int i = 1; i <= cantidad_alumnos; i++)
    {
        edad = generar_edad();
        cout << "Edad alumno " << i << ": " << edad << " años" << endl;
        estatura = generar_estatura();
        cout << "Estatura alumno " << i << ": " << estatura << "cm" << endl;

        suma_edades = suma_edades + edad;
        suma_estaturas = suma_estaturas + estatura;
        if (edad > 18)
        {
            alumnos_mayores_a_18 = alumnos_mayores_a_18 + 1;
            // Se incrementa el contador de alumnos mayores de 18 años.
        }
        if (estatura > 175)
        {
            alumnos_mas_altos_175 = alumnos_mas_altos_175 + 1;
            // Se incrementa el contador de alumnos más altos que 175cm.
        }   
    }

    cout << "La edad media es de " << calcular_promedio(suma_edades, cantidad_alumnos) << " años." << endl;
    cout << "La estatura media es de " << calcular_promedio(suma_estaturas, cantidad_alumnos) << "cm." << endl;
    cout << "La cantidad de alumnos mayores de 18 años es: " << alumnos_mayores_a_18 << endl;
    cout << "La cantidad de alumnos más altos que 175cm: " << alumnos_mas_altos_175 << endl;
    
    return 0;
}

int generar_edad()
{
    int edad;
    edad = (rand() % 35) + 1;
    return edad;
}

int generar_estatura()
{
    int estatura;
    int estatura_minima = 120;
    int estatura_maxima = 200;
    estatura = (rand() % (estatura_maxima - estatura_minima + 1)) + estatura_minima;
    return estatura;
}

float calcular_promedio(float suma, float cantidad)
{
    float promedio = 0.0;
    promedio = suma / cantidad;
    return promedio;
}