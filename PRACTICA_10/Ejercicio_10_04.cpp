// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/11/2025
// Número de ejercicio: 4

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string leer_archivo_txt();
void buscar_texto(string texto_completo);

int main()
{
    system("chcp 65001");
    system("cls");

    string texto_completo;

    cout << "TEXTO DENTRO DEL ARCHIVO:" << endl;
    cout << endl;

    texto_completo = leer_archivo_txt();
    cout << endl;

    buscar_texto(texto_completo);

    return 0;
}

string leer_archivo_txt()
{
    ifstream archivo;
    string texto_completo = "";
    string linea_de_texto;

    archivo.open("Ejercicio_10_04_TEXTO.txt");
    while (getline(archivo, linea_de_texto))
    {
        cout << linea_de_texto << endl;
        texto_completo = texto_completo + linea_de_texto + "\n";
        // Se lee el archivo línea por línea y se va armando todo el texto completo, agregando "\n" para conservar los saltos de línea originales.
    }
    archivo.close();

    return texto_completo;
}

void buscar_texto(string texto_completo)
{
    int cantidad_palabras = 0;
    string texto_a_buscar;
    int posicion_de_palabra;

    cout << "Ingresar la palabra o frase que se desea buscar: ";
    getline(cin, texto_a_buscar);

    posicion_de_palabra = texto_completo.find(texto_a_buscar);
    // Se busca la primera aparición de la palabra en el texto.
    while (posicion_de_palabra != -1)
    // .find() devuelve -1 si no encuentra el texto a buscar, por lo que la condición de búsqueda es que sea diferente a -1.
    {
        cantidad_palabras = cantidad_palabras + 1;
        posicion_de_palabra = texto_completo.find(texto_a_buscar, posicion_de_palabra + texto_a_buscar.length());
        // Para no volver a contar la primera coincidencia, .find() comenzará a contar otra vez empezando desde después de la posición de la primera coincidencia.
        // Si ya no hay más coincidencias después de esa posición, find() devuelve -1 y el while termina.
    }

    cout << endl;
    cout << "Cantidad de veces que aparece la palabra/frase buscada: " << cantidad_palabras << endl;
}