// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/11/2025
// Número de ejercicio: 5

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void leer_archivo_txt(vector<string>& lineas_de_texto);
void actualizar_texto(vector<string>& lineas_de_texto);

int main()
{
    system("chcp 65001");
    system("cls");

    vector<string> lineas_de_texto;
    
    leer_archivo_txt(lineas_de_texto);
    cout << endl;

    actualizar_texto(lineas_de_texto);
    
    return 0;
}

void leer_archivo_txt(vector<string>& lineas_de_texto)
{
    ifstream archivo;
    string linea_de_texto;

    archivo.open("Ejercicio_10_05_PRODUCTOS.txt");
    while (getline(archivo, linea_de_texto))
    {
        cout << linea_de_texto << endl;
        lineas_de_texto.push_back(linea_de_texto);
        // Cada línea se guarda en un vector para poder recorrer línea por línea para actualizar los productos.
    }
    archivo.close();
}

void actualizar_texto(vector<string>& lineas_de_texto)
{
    ofstream archivo_productos;
    string producto_a_actualizar;
    string nuevo_precio;
    int posicion_de_producto;
    bool coincidencia;
    bool producto_encontrado = false;
    // Booleano para saber si el producto fue encontrado.

    cout << "Ingresar el producto que se desea actualizar: ";
    getline(cin, producto_a_actualizar);
    cout << "Ingresar el nuevo precio del producto: ";
    cin >> nuevo_precio;

    for (int i = 0; i < lineas_de_texto.size(); i++)
    // Se recorre cada línea de texto del archivo.
    {
        coincidencia = true;
        // Booleano para indicar si cada letra del producto coincide con la línea de texto.
        for (int j = 0; j < producto_a_actualizar.length(); j++)
        // Se recorre cada carácter del producto ingresado (producto_a_actualizar).
        {
            if (j >= lineas_de_texto[i].length())
            {
                coincidencia = false;
                // Si el producto_a_actualizar tiene más letras que la línea actual del archivo, j ya está fuera del rango de índices válidos de esa línea.
            }
            else
            {
                if (lineas_de_texto[i][j] != producto_a_actualizar[j])
                // Se compara letra por letra los caracteres de la línea con el producto.
                {
                    coincidencia = false;
                    // Si no coincide alguna letra, el booleano se convierte en falso.
                }
            }
        }
        
        if (coincidencia == true && lineas_de_texto[i][producto_a_actualizar.length()] == ' ')
        // Se verifica que todos los caracteres coincidan.
        // Se verifica que sí haya un espacio justo después del nombre por si hay un producto con los mismos primeros caracteres.
        {
            lineas_de_texto[i] = producto_a_actualizar + " " + nuevo_precio;
            // Se actualiza la línea del vector por el producto con su nuevo precio.
            producto_encontrado = true;
        }
    }
    
    if (producto_encontrado == false)
    {
        cout << "El producto no existe en el archivo." << endl;
    }

    archivo_productos.open("Ejercicio_10_05_PRODUCTOS.txt");
    for (int i = 0; i < lineas_de_texto.size(); i++)
    {
        archivo_productos << lineas_de_texto[i] << endl;
        // Se remplaza el texto original del archivo por el texto actualizado.
    }
    
    archivo_productos.close();
}
