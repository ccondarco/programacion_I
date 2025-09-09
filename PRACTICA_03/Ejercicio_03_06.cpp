// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 06/09/2025
// Número de ejercicio: 6

#include <iostream>
using namespace std;

int dias_del_mes(int anio, int mes);
// La función devolverá el número de días del mes ingresado.
string nombre_del_mes(int mes);
// La función devolverá el nombre del mes.
int main()
{
    system("chcp 65001");
    system("cls");

    int anio = 0;
    int mes = 0;
    cout << "Ingresar año: ";
    cin >> anio;
    cout << "Ingresar mes como número: ";
    cin >> mes;

    if (mes < 1 || mes > 12)
    {
        cout << "Mes inválido";
    }
    else
    {
        cout << "El mes de " << nombre_del_mes(mes) << " tiene " << dias_del_mes(anio, mes) << " días.";
    }
    return 0;
}

string nombre_del_mes(int mes)
{
    switch (mes)
    {
    case 1:
            return "enero";
        case 2:
            return "febrero";
        case 3:
            return "marzo";
        case 4:
            return "abril";
        case 5:
            return "mayo";
        case 6:
            return "junio";
        case 7:
            return "julio";
        case 8:
            return "agosto";
        case 9:
            return "septiembre";
        case 10:
            return "octubre";
        case 11:
            return "noviembre";
        case 12:
            return "diciembre";
        default:
            return "Inválido";
    }
}

int dias_del_mes(int anio, int mes)
{
    switch (mes)
    {
        case 1:
            return 31;
        case 2:
            if (anio % 400 == 0)
            {
                return 29;
            }
            else
            {
                if (anio % 4 == 0 && anio % 100 != 0)
                {
                    return 29;
                }
                else
                {
                    return 28;
                }
            }
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return 0;
    }
}