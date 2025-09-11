// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 10/09/2025
// Número de ejercicio: 10

#include <iostream>

using namespace std;

double calcular_tarifa (double km_recorridos);
// La función calculará el costo del viaje en taxi según la distancia recorrida.
int main()
{
    system("chcp 65001");
    system("cls");

    double distancia_recorrida;
    double costo;
    cout << "Ingresar el recorrido del viaje en taxi en km: ";
    cin >> distancia_recorrida;
    
    costo = calcular_tarifa(distancia_recorrida);
    
    cout << "El costo del viaje es de: " << costo;
    
    return 0;
}

double calcular_tarifa (double km_recorridos)
{
    double costo = 10.0;
    costo = costo + (km_recorridos * 2.0);
    if (km_recorridos > 10.0)
    {
        costo = costo - (costo * 0.1);
    }    
    return costo;
}