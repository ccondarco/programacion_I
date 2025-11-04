// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 03/11/2025
// Número de ejercicio: 7

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Producto
{
    char nombre[50];
    char codigo[20];
    float precio;
    int cantidad_en_inventario;
    char observaciones[100];
};

Producto ingresar_datos_producto();
void ingresar_datos(vector<Producto>& productos, int cantidad);
void desplegar_datos_producto(Producto producto);
void mostrar_producto_mas_caro(vector<Producto> productos);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_productos;
    vector<Producto> lista_productos;
    int total_productos;

    cout << "Ingresar cantidad de productos: ";
    cin >> cantidad_productos;
    cout << endl;
    cin.ignore();

    ingresar_datos(lista_productos, cantidad_productos);
    cout << endl;

    mostrar_producto_mas_caro(lista_productos);

    total_productos = lista_productos.size();
    cout << "La cantidad total de productos es: " << total_productos << endl;
    cout << endl;
    
    return 0;
}

Producto ingresar_datos_producto()
{
    Producto producto;

    cout << "Ingresar nombre: ";
    cin.getline(producto.nombre, 50);
    cout << "Ingresar código: ";
    cin.getline(producto.codigo, 20);
    cout << "Ingresar precio: ";
    cin >> producto.precio;
    cout << "Ingresar cantidad en inventario: ";
    cin >> producto.cantidad_en_inventario;
    cin.ignore();
    if (producto.cantidad_en_inventario < 5)
    {
        strcpy(producto.observaciones, "Producto con baja cantidad de inventario");
        cout << "observaciones: " << producto.observaciones;
        // Se verifica si la cantidad en inventario es baja y, si es el caso, se agrega una observación.
    }
    else
    {
        strcpy(producto.observaciones, "");
        // Si no hay observación, el campo se deja vacío.
    }
    cout << endl;

    return producto;
}

void ingresar_datos(vector<Producto>& productos, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        productos.push_back(ingresar_datos_producto());
        cout << endl;
    }
}

void desplegar_datos_producto(Producto producto)
{
    cout << "==========================================" << endl;
    cout << "Nombre: " << producto.nombre << endl;
    cout << "Código: " << producto.codigo << endl;
    cout << "Precio: Bs." << producto.precio << endl;
    cout << "Cantidad en inventario: " << producto.cantidad_en_inventario << endl;
    cout << "Observaciones: " << producto.observaciones << endl;
    cout << "==========================================" << endl;
}

void mostrar_producto_mas_caro(vector<Producto> productos)
{
    float precio_mas_caro = 0;
    Producto producto_mas_caro;

    for (int i = 0; i < productos.size(); i++)
    {
        if (productos[i].precio > precio_mas_caro)
        {
            precio_mas_caro = productos[i].precio;
            producto_mas_caro = productos[i];
        }
    }

    cout << "PRODUCTO MÁS CARO" << endl;
    desplegar_datos_producto(producto_mas_caro);
    cout << endl;
}