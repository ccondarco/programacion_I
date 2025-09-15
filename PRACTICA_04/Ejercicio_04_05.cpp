// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 14/09/2025
// Número de ejercicio: 5

#include <iostream>
using namespace std;

double salario_del_trabajador(int horas, double tarifa, double& bonificacion);
// Se utilizó la variable "bonificacion" como parámetro por referencia para evitar crear una segunda función que calcule la bonificación por separado.
int main()
{
    system("chcp 65001");
    system("cls");

    int horas_trabajadas;
    double tarifa_por_hora;
    double bonificacion = 0.0;

    cout << "Ingresar las horas trabajadas del trabajador: ";
    cin >> horas_trabajadas;
    cout << "Ingresar la tarifa por hora: ";
    cin >> tarifa_por_hora;

    cout << "El salario del trabajador es: " << salario_del_trabajador(horas_trabajadas, tarifa_por_hora, bonificacion) << endl;
    
    if (horas_trabajadas > 8)
    {
        salario_del_trabajador(horas_trabajadas, tarifa_por_hora, bonificacion);
        cout << "Su bonificación por horas extra es: " << bonificacion;
    }
    
    return 0;
}

double salario_del_trabajador(int horas, double tarifa, double& bonificacion)
{
    double salario;
    salario = horas * tarifa;
    
    if (horas > 8)
    {
        horas = horas - 8;
        bonificacion = horas * tarifa;
    }
    return salario;
}