// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 17/09/2025
// Número de ejercicio: 8

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void IVA(int cantidad, double& suma_precios, double& suma_precios_con_IVA);
// La función calcula precios base y con IVA.
double descuento(double suma_con_IVA);
// La función aplica un descuento del 5%.
int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_productos;
    double suma_precios = 0.0;
    double suma_precios_con_IVA = 0.0;
    double impuesto_IVA;
    double monto_con_descuento;
    double IVA_con_descuento;

    cout << "Ingresar cantidad de productos vendidos en el día: ";
    cin >> cantidad_productos;

    srand(time(0));

    IVA(cantidad_productos, suma_precios, suma_precios_con_IVA);

    impuesto_IVA = suma_precios_con_IVA * (13.0 / 113.0);
    // Se calcula el IVA a declarar (precio base = 100%, IVA = 13%. Total = 113%).

    cout << "IVA a pagar es de Bs." << impuesto_IVA << endl;

    if (suma_precios_con_IVA > 2500.0)
    {
        monto_con_descuento = descuento(suma_precios_con_IVA);
        cout << "El monto con el 5% de descuento es de Bs." << monto_con_descuento << endl;

        IVA_con_descuento = monto_con_descuento * (13.0 / 113.0);
        // Se calcula el nuevo IVA después del descuento.
        cout << "Nuevo IVA a pagar con el descuento es de Bs." << IVA_con_descuento << endl;
    }
    else
    {
        cout << "No se aplica descuento." << endl;
    }
    
    return 0;
}

void IVA(int cantidad, double& suma_precios, double& suma_precios_con_IVA)
{
    double precio; 
    double precio_con_IVA;

    for (int i = 1; i <= cantidad; i++)
    {
        precio = (rand() % (50 - 20 + 1)) + 20;
        precio_con_IVA = precio * 1.13;
        cout << "El precio del producto " << i << " es: " << precio_con_IVA << endl;
        suma_precios = suma_precios + precio;
        suma_precios_con_IVA = suma_precios_con_IVA + precio_con_IVA;
    }
    cout << "La suma total de las ventas del día (con IVA) es de Bs." << suma_precios_con_IVA << endl;
}

double descuento(double suma_con_IVA)
{
    double descuento;
    double total_con_descuento;
    descuento = suma_con_IVA * 0.05;
    total_con_descuento = suma_con_IVA - descuento;
    return total_con_descuento;
}