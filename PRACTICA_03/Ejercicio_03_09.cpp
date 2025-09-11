// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 10/09/2025
// Número de ejercicio: 9

#include <iostream>

using namespace std;

float tiempo_trabajado(int minutos);
// La función devolverá las horas trabajadas comparadas con la jornada laboral de 8 horas.
int main()
{
    system("chcp 65001");
    system("cls");

    int minutos = 0;
    float horas = 0;
    cout << "Ingresar la cantidad de minutos trabajados: ";
    cin >> minutos;

    horas = tiempo_trabajado(minutos);
    
    if (horas < 0)
    {
        cout << "Se trabajó menos horas.\nDebe a la empresa " << (-1) * horas << " horas de trabajo." << endl;
    }
    else
    {
        if (horas > 0)
        {
            cout << "Se trabajó horas extra. \nLa empresa debe pagar por " << horas << " horas extra." << endl;
        }
        else
        {
            cout << "Se trabajó 8 horas exactas." << endl;
        }   
    }
    return 0;
}

float tiempo_trabajado(int minutos)
{
    float horas;
    horas = minutos / 60.0;
    // Convierte minutos a horas
    return horas - 8.0;
}