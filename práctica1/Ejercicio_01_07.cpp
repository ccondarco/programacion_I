// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 23/08/2025
// Número de ejercicio: 7

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    char letra = 'a';
    cout << "Ingresar letra: ";
    cin >> letra;
    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z'))
    // Se verifica que el caracter ingresado sea una letra minúscula o mayúscula dentro del abecedario.
    {
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
        {
            cout << "El caracter ingresado es vocal.";
        }
        else
        {
            cout << "El caracter ingresado es consonante.";
        }
    }
    else
    {
        cout << "El caracter ingresado es un símbolo.";
    }
    return 0;
}