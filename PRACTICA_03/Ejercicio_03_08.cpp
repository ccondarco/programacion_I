// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 10/09/2025
// Número de ejercicio: 8

#include <iostream>

using namespace std;

int algoritmo (int monto, int corte);
// La función calculará la cantidad de billetes o monedas de un corte específico que caben en el monto dado.
int main()
{
    system("chcp 65001");
    system("cls");

    int monto_a_ingresar = 0;
    int cantidad_a_devolver = 0;
    cout << "Ingresar monto de dinero: ";
    cin >> monto_a_ingresar;

    cantidad_a_devolver = algoritmo(monto_a_ingresar, 200);
    if (cantidad_a_devolver > 0)
    {
        cout << cantidad_a_devolver << " billetes de Bs.200" << endl;
        monto_a_ingresar = monto_a_ingresar - (cantidad_a_devolver * 200);
    }

    cantidad_a_devolver = algoritmo(monto_a_ingresar, 100);
    if (cantidad_a_devolver > 0)
    {
        cout << cantidad_a_devolver << " billetes de Bs.100" << endl;
        monto_a_ingresar = monto_a_ingresar - (cantidad_a_devolver * 100);
    }

    cantidad_a_devolver = algoritmo(monto_a_ingresar, 50);
    if (cantidad_a_devolver > 0)
    {
        cout << cantidad_a_devolver << " billetes de Bs.50" << endl;
        monto_a_ingresar = monto_a_ingresar - (cantidad_a_devolver * 50);
    }

    cantidad_a_devolver = algoritmo(monto_a_ingresar, 20);
    if (cantidad_a_devolver > 0)
    {
        cout << cantidad_a_devolver << " billetes de Bs.20" << endl;
        monto_a_ingresar = monto_a_ingresar - (cantidad_a_devolver * 20);
    }

    cantidad_a_devolver = algoritmo(monto_a_ingresar, 10);
    if (cantidad_a_devolver > 0)
    {
        cout << cantidad_a_devolver << " billetes de Bs.10" << endl;
        monto_a_ingresar = monto_a_ingresar - (cantidad_a_devolver * 10);
    }

    cantidad_a_devolver = algoritmo(monto_a_ingresar, 5);
    if (cantidad_a_devolver > 0)
    {
        cout << cantidad_a_devolver << " monedas de Bs.5" << endl;
        monto_a_ingresar = monto_a_ingresar - (cantidad_a_devolver * 5);
    }

    cantidad_a_devolver = algoritmo(monto_a_ingresar, 2);
    if (cantidad_a_devolver > 0)
    {
        cout << cantidad_a_devolver << " monedas de Bs.2" << endl;
        monto_a_ingresar = monto_a_ingresar - (cantidad_a_devolver * 2);
    }

    cantidad_a_devolver = algoritmo(monto_a_ingresar, 1);
    if (cantidad_a_devolver > 0)
    {
        cout << cantidad_a_devolver << " monedas de Bs.1" << endl;
        monto_a_ingresar = monto_a_ingresar - (cantidad_a_devolver * 1);
    }
    return 0;
}

int algoritmo (int monto, int corte)
{
    if (monto >= corte)
    // Devuelve el número de billetes/monedas o 0 si el monto es menor que el corte.
    {
        int cantidad;
        cantidad = monto / corte;
        // Calcula cuántos billetes o monedas caben en el monto.
        return cantidad;
    }
    else
    {
        return 0;
    }
}