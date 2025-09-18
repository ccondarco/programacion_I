// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 18/09/2025
// Número de ejercicio: 9

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int productos_vendidos(int cantidad_vendedoras);
int antiguedad_vendedoras(int cantidad_vendedoras);
double comision(int productos);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_vendedoras;
    double sueldo_basico = 2750.0;
    double sueldo_por_vendedora;
    int ventas;
    int antiguedad;
    double comision_ganada = 0.0;
    double sueldo_total;

    cout << "Ingresar la cantidad de vendedoras: ";
    cin >> cantidad_vendedoras;
    cout << endl;

    srand(time(0));

    for (int i = 1; i <= cantidad_vendedoras; i++)
    {
        ventas = productos_vendidos(cantidad_vendedoras);
        cout << "La vendedora " << i << " realizó " << ventas << " ventas este mes." << endl;

        antiguedad = antiguedad_vendedoras(cantidad_vendedoras);
        cout << "Tiene " << antiguedad << " años de antigúedad." << endl;
        sueldo_por_vendedora = sueldo_basico;
        if (antiguedad != 1)
        {
            if (antiguedad >= 2 && antiguedad <= 4)
            {
                sueldo_por_vendedora = sueldo_basico + (sueldo_basico * 0.05);
                cout << "Su sueldo más el 5% de bonificación por su antigüedad es: Bs." << sueldo_por_vendedora << endl;
            }
            
            if (antiguedad >= 5 && antiguedad <= 7)
            {
                sueldo_por_vendedora = sueldo_basico + (sueldo_basico * 0.11);
                cout << "Su sueldo más el 11% de bonificación por su antigüedad es: Bs." << sueldo_por_vendedora << endl;
            }

            if (antiguedad >= 8 && antiguedad <= 10)
            {
                sueldo_por_vendedora = sueldo_basico + (sueldo_basico * 0.18);
                cout << "Su sueldo más el 18% de bonificación por su antigüedad es: Bs." << sueldo_por_vendedora << endl;
            }
        }
        else
        {
            cout << "Aún no tiene bonificación por antigüedad. Su sueldo base es: Bs." << sueldo_por_vendedora << endl;
        }
        
        comision_ganada = comision(ventas);
        cout << "La comisión obtenida por los productos vendidos es: Bs." << comision_ganada << endl;

        sueldo_total = sueldo_por_vendedora + comision_ganada;
        cout << "Su sueldo total a pagar es: Bs." << sueldo_total << endl;

        cout << endl;
    }
    
    return 0;
}

int productos_vendidos(int cantidad_vendedoras)
{
    int cantidad_productos;
    cantidad_productos = (rand() % (15 - 5 + 1) + 5);
    // El promedio de ventas de una vendedora es de 10 productos, pero pueden vender más o menos.
    return cantidad_productos;
}

int antiguedad_vendedoras(int cantidad_vendedoras)
{
    int antiguedad;
    antiguedad = (rand() % (10 - 1 + 1)) + 1;
    // Se establece que una vendedora puede tener de 1 a 10 años de antigüedad.
    return antiguedad;
}

double comision(int productos)
{
    double comision;
    double precio_producto = 100.0;
    // Se establece que el precio fijo de los productos a vender es de Bs.100.
    comision = productos * precio_producto * 0.10;
    return comision;
}