// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 23/08/2025
// Número de ejercicio: 10

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int nota = 0;
    cout << "Ingresar nota: ";
    cin >> nota;
    if (nota >= 51)
    // Se descarta si la persona reprobó (nota menor a 51).
    {
        if (nota >= 60)
        // Si la nota es menor a 60, su calificación es igual a C.
        {
            if (nota >= 70)
            // Si la nota es menor a 70, su calificación es igual a C+.
            {
                if (nota >= 80)
                // Si la nota es menor a 80, su calificación es igual a B.
                {
                    if (nota >= 90)
                    // Si la nota es menor a 90, su calificación es igual a B+.
                    {
                        if (nota >= 95)
                        // Si la nota es menor a 95, su calificación es igual a A.
                        {
                            cout << "Aprobado. Calificación = A+";
                        }
                        else
                        {
                            cout << "Aprobado. Calificación = A";
                        }
                    }
                    else
                    {
                        cout << "Aprobado. Calificación = B+";
                    }
                }
                else
                {
                    cout << "Aprobado. Calificación = B";
                }
            }
            else
            {
                cout << "Aprobado. Calificación = C+";
            }
        }
        else
        {
            cout << "Aprobado. Calificación = C";
        }
    }
    else
    {
        cout << "Reprobado.";
    }
    return 0;
}