// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 04/09/2025
// Número de ejercicio: 7

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int cantidad_de_ninos = 0;
    int ninos_de_1_anio = 0;
    int ninos_de_2_anios = 0;
    int ninos_de_3_anios = 0;
    int panales_1_anio = 0;
    int panales_2_anios = 0;
    int panales_3_anios = 0;
    int total_panales = 0;
    cout << "Ingresar la cantidad de niños que se desea generar: ";
    cin >> cantidad_de_ninos;

    srand(time(0));

    ninos_de_1_anio = (rand() % cantidad_de_ninos + 1);
    cout << "Cantidad de niños de 1 año : " << ninos_de_1_anio << endl;
    ninos_de_2_anios = (rand() % (cantidad_de_ninos - ninos_de_1_anio + 1));
    cout << "Cantidad de niños de 2 años : " << ninos_de_2_anios << endl;
    ninos_de_3_anios = cantidad_de_ninos - ninos_de_1_anio - ninos_de_2_anios;
    cout << "Cantidad de niños de 3 años : " << ninos_de_3_anios << endl;
    // Se asegura que la suma total de niños no exceda la cantidad ingresada.

    panales_1_anio = ninos_de_1_anio * 6;
    panales_2_anios = ninos_de_2_anios * 3;
    panales_3_anios = ninos_de_3_anios * 2;

    total_panales = panales_1_anio + panales_2_anios + panales_3_anios;

    cout << "La cantidad de pañales diarios que se consume es: " << total_panales;
    return 0;
}