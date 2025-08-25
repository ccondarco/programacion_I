// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 22/08/2025
// Número de ejercicio: 4

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    // El volumen de una esfera es 4/3 de pi (π = 3.1416) por radio al cubo (volumen = 4/3 π * r^3)
    float volumen = 0.0;
    float radio = 0.0;
    float pi = 3.1416;
    float radio_al_cubo;
    cout << "Ingresar radio de esfera: ";
    cin >> radio;
    radio_al_cubo = radio * radio * radio;
    volumen = (4.0 * radio_al_cubo * pi) / 3.0;
    cout << "Volumen de esfera: " << volumen;
    return 0;
}