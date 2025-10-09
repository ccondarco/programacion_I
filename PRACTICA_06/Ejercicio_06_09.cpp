// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/10/2025
// Número de ejercicio: 9

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> separar_palabras(string oracion);
void mostrar_oracion_invertida(vector<string> palabras);

int main()
{
    system("chcp 65001");
    system("cls");

    string texto;
    vector<string> palabras;

    cout << "Ingresar texto: ";
    getline(cin, texto);

    palabras = separar_palabras(texto);

    mostrar_oracion_invertida(palabras);

    return 0;
}

vector<string> separar_palabras(string texto)
{
    int longitud_texto = texto.size();
    string palabra = "";
    vector<string> palabras;

    for (int i = 0; i < longitud_texto; i++)
    {
        
        if (texto[i] != ' ')
        // Si el carácter no es un espacio, se agrega a la palabra actual.
        {
            palabra = palabra + texto[i];
        } 
        // Si se encuentra un espacio y la palabra no está vacía, se guarda en el vector.
        else
        {
            if (palabra.length() > 0)
            {
                palabras.push_back(palabra);
                palabra = "";
            }
        }
    }
    if (palabra.size() > 0)
    {
        palabras.push_back(palabra);
    }
    
    return palabras;
}

void mostrar_oracion_invertida(vector<string> palabras)
{
    int cantidad_palabras = palabras.size();

    for (int i = cantidad_palabras - 1; i >= 0; i--)
    {
        cout << palabras[i];
        if (i > 0)
        // Si no es la última palabra, se pone un espacio.
        {
            cout << " ";
        }
    }
    cout << endl;
}
