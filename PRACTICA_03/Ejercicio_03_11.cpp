// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 11/09/2025
// Número de ejercicio: 11

#include <iostream>

using namespace std;

double retiro_de_dinero (double saldo, int cantidad);
// La función simulará el retiro de dinero en un cajero automático.
int main()
{
    system("chcp 65001");
    system("cls");

    double saldo = 1000;
    int cantidad = 0;
    double nuevo_saldo = 0;

    cout << "Ingresar monto a retirar: ";
    cin >> cantidad;
    
    nuevo_saldo = retiro_de_dinero(saldo, cantidad);
    
    if (nuevo_saldo == 0)
    {
        cout << "No se realizó la transacción.";
    }
    else
    {
        cout << "El saldo actual es de Bs. " << nuevo_saldo;
    }
    return 0;
}

double retiro_de_dinero (double saldo, int cantidad)
{
    if (saldo < cantidad)
    {
        cout << "No tiene saldo suficiente." << endl;
        return 0.0; 
    }
    
    if (cantidad % 10 != 0)
    {
        cout << "La cantidad no es válida para retirar." << endl;
        return 0.0;
    }
    
    cout << "El retiro es válido." << endl;
    return saldo - cantidad;
}
