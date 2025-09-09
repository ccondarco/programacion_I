// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 05/09/2025
// Número de ejercicio: 4

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero_al_azar = 0;
    int numero_a_adivinar = 0;
    int minimo = 0;
    int maximo = 50;
    bool adivinado = false;
    // Una variable booleana para verificar si el usuario adivinó el número.

    srand(time(0));
    cout << "Estoy pensando un número entre 0 y 50. ¿Cuál es?" << endl;
    numero_al_azar = (rand() % 51);
    
    for (int i = 1; i <= 5; i++)
    {
        if (adivinado == false)
        {
            cout << "Intento " << i << ": ";
            cin >> numero_a_adivinar;
            
            if (numero_a_adivinar != numero_al_azar)
            {
                if (i < 5)
                // Esta condicional sólo para que el mensaje de "El número está entre..." no aparezca luego del último intento.
                {
                    if (numero_a_adivinar < numero_al_azar)
                    {
                        cout << "El número está entre " << numero_a_adivinar << " y " << maximo << endl;
                        minimo = numero_a_adivinar;
                        // Si el número ingresado es menor que el número al azar, el mínimo nuevo debe ser ese número.
                    }
                    else
                    {
                        cout << "El número está entre " << minimo << " y " << numero_a_adivinar << endl;
                        maximo = numero_a_adivinar;
                        // Si el número ingresado es mayor que el número al azar, el máximo nuevo debe ser ese número.
                    }
                }
            }
            else
            {
                cout << "¡Felicidades! Número correcto." << endl;
                adivinado = true;
            }
        }
    }
    if (adivinado == false)
    {
        cout << "Se acabaron los intentos. El número era " << numero_al_azar << ".";
    }
    return 0;
}