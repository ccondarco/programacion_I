// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 31/09/2025
// Número de ejercicio: 23

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 0;
    int numero_invertido = 0;
    int digito_extraido = 0;
    cout << "Ingresar número: ";
    cin >> numero;
    while(numero > 0)
    {
        digito_extraido = numero % 10;
        // Extrae el último dígito del número.
        numero_invertido = numero_invertido + digito_extraido;
        // Suma el último dígito al número invertido.
        numero_invertido = numero_invertido * 10;
        // Se multiplica por 10 para desplazar los dígitos.
        numero = numero / 10;
        // Se elimina el último dígito del número original.
    }
    
    cout << "Número invertido: " << numero_invertido / 10;
    return 0;
}