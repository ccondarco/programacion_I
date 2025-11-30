// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 19/11/2025
// Número de ejercicio: 2

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>

using namespace std;

struct Datos_producto
{
    int codigo_producto;
    char nombre_producto[20];
    int cantidad_inicial;
    double precio_unitario;
};

struct Datos_cliente
{
    int CI;
    char nombre[50];
    int codigo_producto_comprado;
    int cantidad;
};

void desplegar_menu(string nombre_archivo_productos, string nombre_archivo_ventas);
void adicionar_producto(string nombre_archivo);
void listado_productos(string nombre_archivo_productos, string nombre_archivo_ventas);
void buscar_producto(string nombre_archivo);
void modificar_producto(string nombre_archivo);
void adicionar_ventas_producto(string nombre_archivo_productos, string nombre_archivo_ventas);

int main()
{
    system("chcp 65001");
    system("cls");

    string nombre_archivo_productos = "Ejercicio_11_02_Productos.bin";
    string nombre_archivo_ventas = "Ejercicio_11_02_Ventas.txt";
    desplegar_menu(nombre_archivo_productos, nombre_archivo_ventas);

    return 0;
}

void desplegar_menu(string nombre_archivo_productos, string nombre_archivo_ventas)
{
    int opcion;

    do
    {
        system("cls");
        cout << "============== MENÚ DE OPCIONES ==============" << endl;
        cout << "\t1. Adicionar producto" << endl;
        cout << "\t2. Lista de productos" << endl;
        cout << "\t3. Buscar un producto por código" << endl;
        cout << "\t4. Modificar un producto" << endl;
        cout << "\t5. Adicionar ventas del producto" << endl;
        cout << "\t0. Salir" << endl;
        cout << endl;
        cout << "Seleccionar opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            adicionar_producto(nombre_archivo_productos);
            break;
        
        case 2:
            listado_productos(nombre_archivo_productos, nombre_archivo_ventas);
            break;
        
        case 3:
            buscar_producto(nombre_archivo_productos);
            break;
        
        case 4:
            modificar_producto(nombre_archivo_productos);
            break;
        
        case 5:
            adicionar_ventas_producto(nombre_archivo_productos, nombre_archivo_ventas);
            break;
        
        default:
            if (opcion != 0)
            {
                cout << "Opción inválida" << endl;
                system("pause");
            }
            
            break;
        }
    } while (opcion != 0);
}

void adicionar_producto(string nombre_archivo)
{
    Datos_producto producto;
    ofstream archivo_productos;

    archivo_productos.open(nombre_archivo, ios::binary | ios::app);
    if (archivo_productos.good())
    {
        cout << "Ingresar código de producto: ";
        cin >> producto.codigo_producto;
        cin.ignore();
        cout << "Ingresar nombre de producto: ";
        cin.getline(producto.nombre_producto, 20);
        cout << "Ingresar cantidad inicial: ";
        cin >> producto.cantidad_inicial;
        cout << "Ingresar precio unitario: ";
        cin >> producto.precio_unitario;
        archivo_productos.write((char*)&producto, sizeof(Datos_producto));
        cout << "Producto agregado correctamente." << endl;
    }
    else
    {
        cout << "No se pudo adicionar el producto." << endl;
        system("pause");
    }
    archivo_productos.close();
}

void listado_productos(string nombre_archivo_productos, string nombre_archivo_ventas)
{
    Datos_producto producto;
    Datos_cliente cliente;
    ifstream archivo_productos;
    ifstream archivo_ventas;
    string linea_texto;
    string dato;
    string nombre_temporal;
    int cantidad_vendida = 0;
    double total = 0.0;

    archivo_productos.open(nombre_archivo_productos, ios::binary);
    if (archivo_productos.good())
    {
        system("cls");
        cout << "LISTADO DE PRODUCTOS" << endl;
        cout << "CODIGO \tNOMBRE PRODUCTO \tCANTIDAD INICIAL \tPRECIO \tCANTIDAD VENDIDA \tTOTAL" << endl;
        while (archivo_productos.read((char*)&producto, sizeof(Datos_producto)))
        {
            cantidad_vendida = 0;
            // Se reinicia el contador de ventas para cada producto.
            
            archivo_ventas.open(nombre_archivo_ventas);
            // Se abre el archivo de ventas para calcular la cantidad vendida.
            if (archivo_ventas.good())
            {
                while (getline(archivo_ventas, linea_texto))
                {
                    stringstream ss(linea_texto);
                    // Se usa stringstream para extraer los datos separados por ';'.

                    getline(ss, dato, ';');
                    // ss es el origen de donde se leerá el string. dato es la variable donde se guardará lo leído. ';' es el delimitador; todo lo que esté antes de ; se guarda en dato.
                    cliente.CI = stoi(dato);
                    // Se convierte de string a entero.

                    getline(ss, nombre_temporal, ';');
                    // Se lee el nombre del cliente.
                    strcpy(cliente.nombre, nombre_temporal.c_str());
                    // c_str() convierte un string a un arreglo de caracteres, esto para poder usar strcpy (copiar los caracteres de nombre_temporal a cliente.nombre).

                    getline(ss, dato, ';');
                    cliente.codigo_producto_comprado = stoi(dato);

                    getline(ss, dato);
                    cliente.cantidad = stoi(dato);

                    if (cliente.codigo_producto_comprado == producto.codigo_producto)
                    // Si la venta corresponde al producto actual, se suma a la cantidad vendida.
                    {
                        cantidad_vendida = cantidad_vendida + cliente.cantidad;
                    }
                }
            }
            archivo_ventas.close();

            total = cantidad_vendida * producto.precio_unitario;

            cout << producto.codigo_producto << "\t" << producto.nombre_producto << "\t" << producto.cantidad_inicial << "\t" << producto.precio_unitario << "\t" << cantidad_vendida << "\t" << total << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo de productos." << endl;
    }
    archivo_productos.close();
    system("pause");
}

void buscar_producto(string nombre_archivo)
{
    Datos_producto producto;
    ifstream archivo_productos;
    int codigo_a_buscar;
    bool codigo_encontrado = false;

    cout << "Ingresar código de producto a buscar: ";
    cin >> codigo_a_buscar;

    archivo_productos.open(nombre_archivo, ios::binary);
    if (archivo_productos.good())
    {
        while (archivo_productos.read((char*)&producto, sizeof(Datos_producto)))
        {
            if (codigo_a_buscar == producto.codigo_producto)
            // Si coincide el código, se muestra la información del producto.
            {
                cout << "Producto encontrado:" << endl;
                cout << "Código: " << producto.codigo_producto << endl;
                cout << "Nombre: " << producto.nombre_producto << endl;
                cout << "Cantidad inicial: " << producto.cantidad_inicial << endl;
                cout << "Precio unitario: " << producto.precio_unitario << endl;
                codigo_encontrado = true;
            }
        }
        if (codigo_encontrado == false)
        {
            cout << "Producto no encontrado." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo de productos." << endl;
    }
    archivo_productos.close();
    system("pause");
}

void modificar_producto(string nombre_archivo)
{
    Datos_producto producto;
    fstream archivo_productos;
    int codigo_a_buscar;
    bool codigo_encontrado = false;
    
    cout << "Ingresar código de producto a modificar: ";
    cin >> codigo_a_buscar;

    archivo_productos.open(nombre_archivo, ios::binary | ios::in | ios::out);
    if (archivo_productos.good())
    {
        while (archivo_productos.read((char*)&producto, sizeof(Datos_producto)))
        {
            if (codigo_a_buscar == producto.codigo_producto)
            {
                cout << "Producto encontrado. Ingresar nuevos datos." << endl;
                cout << "Ingresar código de producto: ";
                cin >> producto.codigo_producto;
                cin.ignore();
                cout << "Ingresar nombre de producto: ";
                cin.getline(producto.nombre_producto, 20);
                cout << "Ingresar cantidad inicial: ";
                cin >> producto.cantidad_inicial;
                cout << "Ingresar precio unitario: ";
                cin >> producto.precio_unitario;
                codigo_encontrado = true;

                archivo_productos.seekp(-sizeof(Datos_producto), ios::cur);

                archivo_productos.write((char*)&producto, sizeof(Datos_producto));
                cout << "Producto modificado correctamente." << endl;
            }
        }
        
        if (codigo_encontrado == false)
        {
            cout << "Producto no encontrado." << endl;
        }
    }
    else
    {
        cout << "No se pudo modificar el producto." << endl;
        system("pause");
    }
    archivo_productos.close();
    system("pause");
}

void adicionar_ventas_producto(string nombre_archivo_productos, string nombre_archivo_ventas)
{
    Datos_cliente cliente;
    Datos_producto producto;
    ofstream archivo_ventas;
    fstream archivo_productos;

    archivo_ventas.open(nombre_archivo_ventas, ios::app);
    if (archivo_ventas.good())
    {
        cout << "Ingresar CI del cliente: ";
        cin >> cliente.CI;
        cin.ignore();
        cout << "Ingresar nombre del cliente: ";
        cin.getline(cliente.nombre, 50);
        cout << "Ingresar código de producto comprado: ";
        cin >> cliente.codigo_producto_comprado;
        cout << "Ingresar cantidad comprada: ";
        cin >> cliente.cantidad;

        archivo_ventas << cliente.CI << "; " << cliente.nombre << "; " << cliente.codigo_producto_comprado << "; " << cliente.cantidad << endl;
        cout << "Venta registrada correctamente." << endl;

        archivo_productos.open(nombre_archivo_productos, ios::binary | ios::in | ios::out);
        // Se actualiza el inventario restando la cantidad vendida.
        if (archivo_productos.good())
        {
            while (archivo_productos.read((char*)&producto, sizeof(Datos_producto)))
            {
                if (producto.codigo_producto == cliente.codigo_producto_comprado)
                {
                    producto.cantidad_inicial = producto.cantidad_inicial - cliente.cantidad;
                    // Si el producto existe, se resta la cantidad de ventas de la cantidad inicial.
                    archivo_productos.seekp(-sizeof(Datos_producto), ios::cur);
                    // Se escribe de nuevo los datos del producto modificado.
                    archivo_productos.write((char*)&producto, sizeof(Datos_producto));
                }
            }
            archivo_productos.close();
        }
        else
        {
            cout << "No se pudo abrir el archivo de productos para actualizar." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo de ventas." << endl;
    }
    archivo_ventas.close();
    system("pause");
}