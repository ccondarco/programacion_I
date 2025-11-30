// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 28/11/2025
// Número de ejercicio: 3

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Datos_pizza
{
    int codigo;
    char nombre[20];
    int tipo;
    int tamanio;
    float precio;
    bool eliminada;
};

struct Datos_venta
{
    int carnet_cliente;
    int codigo_pizza;
    int tamanio;
    int cantidad_pizzas_vendidas;
};

void menu_opciones(string nombre_archivo_pizzas, string nombre_archivo_ventas, vector<string> tipos, vector<string> tamanios);
void adicionar_pizza(string nombre_archivo_pizzas, vector<string> tipos, vector<string> tamanios);
void listado_pizzas(string nombre_archivo_pizzas, string nombre_archivo_ventas, vector<string> tipos, vector<string> tamanios);
void modificar_precio_pizza(string nombre_archivo_pizzas, vector<string> tipos, vector<string> tamanios);
void eliminar_pizza(string nombre_archivo_pizzas, vector<string> tipos, vector<string> tamanios);
void adicionar_venta_de_pizza(string nombre_archivo_pizzas, string nombre_archivo_ventas, vector<string> tipos, vector<string> tamanios);

int main()
{
    system("chcp 65001");
    system("cls");

    vector<string> tipos = {"Tradicional", "Especial"};
    // Especial = tradicional + (tradicional * 0.1)
    vector<string> tamanios = {"Pizza XS", "Mediana", "Grande", "Familiar", "Interminable"};
    string nombre_archivo_pizzas = "Ejercicio_11_03_Producto.bin";
    string nombre_archivo_ventas = "Ejercicio_11_03_Ventas.txt";

    menu_opciones(nombre_archivo_pizzas, nombre_archivo_ventas, tipos, tamanios);

    return 0;
}

void menu_opciones(string nombre_archivo_pizzas, string nombre_archivo_ventas, vector<string> tipos, vector<string> tamanios)
{
    int opcion;

    do
    {
        system("cls");
        cout << "========== MENÚ DE OPCIONES - PIZZERIA ELI'S ==========" << endl;
        cout << "1. Adicionar pizza" << endl;
        cout << "2. Listado de pizzas" << endl;
        cout << "3. Modificar precio de pizza según código" << endl;
        cout << "4. Eliminar pizza" << endl;
        cout << "5. Adicionar venta de pizzas" << endl;
        cout << "0. Salir" << endl;
        cout << endl;
        cout << "Seleccionar opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            adicionar_pizza(nombre_archivo_pizzas, tipos, tamanios);
            break;
        
        case 2:
            listado_pizzas(nombre_archivo_pizzas, nombre_archivo_ventas, tipos, tamanios);
            break;

        case 3:
            modificar_precio_pizza(nombre_archivo_pizzas, tipos, tamanios);
            break;

        case 4:
            eliminar_pizza(nombre_archivo_pizzas, tipos, tamanios);
            break;

        case 5:
            adicionar_venta_de_pizza(nombre_archivo_pizzas, nombre_archivo_ventas, tipos, tamanios);
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

void adicionar_pizza(string nombre_archivo_pizzas, vector<string> tipos, vector<string> tamanios)
{
    Datos_pizza pizza;
    ofstream archivo_pizzas;

    system("cls");

    archivo_pizzas.open(nombre_archivo_pizzas, ios::binary | ios::app);
    if (archivo_pizzas.good())
    {
        cout << "Ingresar código de pizza: ";
        cin >> pizza.codigo;
        cin.ignore();
        cout << "Ingresar nombre de pizza: ";
        cin.getline(pizza.nombre, 20);
        cout << "\tTIPOS" << endl;
        for (int i = 0; i < tipos.size(); i++)
        {
            cout << "\t" << i + 1 << " " << tipos[i] << endl;
        }
        cout << "Ingresar tipo: ";
        cin >> pizza.tipo;
        cout << "\tTAMAÑOS" << endl;
        for (int i = 0; i < tamanios.size(); i++)
        {
            cout << "\t" << i + 1 << " " << tamanios[i] << endl;
        }
        cout << "Ingresar tamaño: ";
        cin >> pizza.tamanio;
        cout << "Ingresar precio: ";
        cin >> pizza.precio;
        if (pizza.tipo == 2)
        // Si el tipo es Especial, se adiciona un 10% más que el precio de la Tradicional.
        {
            pizza.precio = pizza.precio + (pizza.precio * 0.1);
        }
        pizza.eliminada = false;

        archivo_pizzas.write((char*)&pizza, sizeof(Datos_pizza));
        cout << "Producto agregado exitosamente." << endl;
        system("pause");
    }
    else
    {
        cout << "No se pudo abrir archivo para adicionar pizzas." << endl;
        system("pause");
    }
    archivo_pizzas.close();
}

void listado_pizzas(string nombre_archivo_pizzas, string nombre_archivo_ventas, vector<string> tipos, vector<string> tamanios)
{
    system("cls");

    Datos_pizza pizza;
    Datos_venta venta;
    ifstream archivo_pizzas;
    ifstream archivo_ventas;
    int cantidad_total = 0;
    float total_en_bs = 0;
    string linea_texto;
    string dato;
    int contador_datos_ss;
    int codigo_linea_de_texto;
    int cantidad_linea_de_texto;

    archivo_pizzas.open(nombre_archivo_pizzas, ios::binary);
    if (archivo_pizzas.good())
    {
        cout << "LISTADO DE PIZZAS" << endl;
        cout << "CÓDIGO \tNOMBRE \tTIPO \tTAMAÑO \tPRECIO \tCANTIDAD \tTOTAL" << endl;

        while (archivo_pizzas.read((char*)&pizza, sizeof(Datos_pizza)))
        {
            if (!pizza.eliminada)
            {
                cantidad_total = 0;
                total_en_bs = 0.0;
                // Se reinician los contadores para calcular las ventas de esta pizza en particular.
                archivo_ventas.open(nombre_archivo_ventas);
                if (archivo_ventas.good())
                {
                    while (getline(archivo_ventas, linea_texto))
                    // Se lee línea por línea el archivo de ventas.
                    {
                        stringstream ss(linea_texto);
                        // Se crea un stringstream para separar por ';'.
                        contador_datos_ss = 0;
                        // Se reinicia para cada línea porque cada línea empieza de cero.

                        while (getline(ss, dato, ';'))
                        // Se separan los campos de la línea (carnet;codigo;tamanio;cantidad).
                        {
                            if (contador_datos_ss == 1)
                            {
                                codigo_linea_de_texto = stoi(dato);
                            }
                            if (contador_datos_ss == 3)
                            {
                                cantidad_linea_de_texto = stoi(dato);
                                // stoi convierte de string a int para guardar la cantidad de pizzas vendidas.
                            }
                            contador_datos_ss = contador_datos_ss + 1;
                        }

                        if (codigo_linea_de_texto == pizza.codigo)
                        {
                            cantidad_total = cantidad_total + cantidad_linea_de_texto;
                            total_en_bs = total_en_bs + (cantidad_linea_de_texto * pizza.precio);
                        }
                    }
                }
                else
                {
                    archivo_ventas.clear();  // Limpiar cualquier bandera de error
                    archivo_ventas.open(nombre_archivo_ventas, ios::out); // Abrir en modo de escritura
                    archivo_ventas.close(); // Cerrar el archivo vacío creado
                    archivo_ventas.open(nombre_archivo_ventas); // Volver a abrir en modo lectura
                    
                    cout << "No se pudo abrir el archivo de texto." << endl;
                    system("pause");
                }
                archivo_ventas.close();

                cout << pizza.codigo << "\t" << pizza.nombre << "\t" << tipos[pizza.tipo - 1] << "\t" << tamanios[pizza.tamanio - 1] << "\t" << pizza.precio << "\t" << cantidad_total << "\t" << total_en_bs << endl;
            }
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo binario." << endl;
        system("pause");
    }
    archivo_pizzas.close();
    system("pause");
}

void modificar_precio_pizza(string nombre_archivo_pizzas, vector<string> tipos, vector<string> tamanios)
{
    system("cls");

    Datos_pizza pizza;
    fstream archivo_pizzas;
    int codigo_a_buscar;
    bool codigo_encontrado = false;
    float nuevo_precio;

    cout << "Ingresar código de pizza a buscar: ";
    cin >> codigo_a_buscar;

    archivo_pizzas.open(nombre_archivo_pizzas, ios::binary | ios::in | ios::out);
    if (archivo_pizzas.good())
    {
        while (archivo_pizzas.read((char*)&pizza, sizeof(Datos_pizza)) && !codigo_encontrado)
        {
            if (codigo_a_buscar == pizza.codigo && !codigo_encontrado)
            {
                cout << "Encontrado" << endl;
                cout << "Código: " << pizza.codigo << endl;
                cout << "Nombre: " << pizza.nombre << endl;
                cout << "Tipo: " << tipos[pizza.tipo - 1] << endl;
                cout << "Tamaño: " << tamanios[pizza.tamanio - 1] << endl;
                cout << "Precio: " << pizza.precio << endl;
                codigo_encontrado = true;
                cout << endl;
                cout << "Ingresar nuevo precio: ";
                cin >> nuevo_precio;
                // Se pide el nuevo precio y se actualiza el archivo.
                archivo_pizzas.seekp(-sizeof(Datos_pizza), ios::cur);
                pizza.precio = nuevo_precio;
                if (pizza.tipo == 2)
                {
                    pizza.precio = pizza.precio + (pizza.precio * 0.1);
                }
                archivo_pizzas.write((char*)&pizza, sizeof(Datos_pizza));

                cout << "Precio modificado exitosamente." << endl;
                system("pause");
            }
        }

        if (!codigo_encontrado)
        {
            cout << "Código no encontrado" << endl;
            system("pause");
        }
        
    }
    else
    {
        cout << "No se pudo abrir archivo para modificar precio." << endl;
        system("pause");
    }
    archivo_pizzas.close();
}

void eliminar_pizza(string nombre_archivo_pizzas, vector<string> tipos, vector<string> tamanios)
{
    system("cls");
    
    Datos_pizza pizza;
    fstream archivo_pizzas;
    int codigo_a_buscar;
    bool codigo_encontrado = false;

    cout << "Ingresar código de pizza a buscar: ";
    cin >> codigo_a_buscar;

    archivo_pizzas.open(nombre_archivo_pizzas, ios::binary | ios::in | ios::out);
    if (archivo_pizzas.good())
    {
        while (archivo_pizzas.read((char*)&pizza, sizeof(Datos_pizza)) && !codigo_encontrado)
        {
            if (codigo_a_buscar == pizza.codigo && !codigo_encontrado && !pizza.eliminada)
            {
                if (!pizza.eliminada)
                {
                    cout << "Pizza encontrada" << endl;
                    cout << "Código: " << pizza.codigo << endl;
                    cout << "Nombre: " << pizza.nombre << endl;
                    cout << "Tipo: " << tipos[pizza.tipo - 1] << endl;
                    cout << "Tamaño: " << tamanios[pizza.tamanio - 1] << endl;
                    cout << "Precio: " << pizza.precio << endl;
                    codigo_encontrado = true;
                    cout << endl;

                    archivo_pizzas.seekp(-sizeof(Datos_pizza), ios::cur);
                    pizza.eliminada = true;
                    archivo_pizzas.write((char*)&pizza, sizeof(Datos_pizza));

                    cout << "Pizza eliminada exitosamente." << endl;
                    system("pause");
                }
            }
        }

        if (!codigo_encontrado)
        {
            cout << "Código no encontrado" << endl;
            system("pause");
        }
    }
    else
    {
        cout << "No se pudo abrir archivo para eliminar pizza." << endl;
        system("pause");
    }
    archivo_pizzas.close();
}

void adicionar_venta_de_pizza(string nombre_archivo_pizzas, string nombre_archivo_ventas, vector<string> tipos, vector<string> tamanios)
{
    system("cls");

    Datos_pizza pizza;
    Datos_venta venta;
    ofstream archivo_ventas;
    ifstream archivo_pizzas;
    int codigo_a_buscar;
    bool encontrado = false;

    cout << "Ingresar código de pizza para adicionar venta: ";
    cin >> codigo_a_buscar;

    archivo_pizzas.open(nombre_archivo_pizzas, ios::binary);
    if (archivo_pizzas.good())
    {
        while (archivo_pizzas.read((char*)&pizza, sizeof(Datos_pizza)) && !encontrado)
        {
            if (codigo_a_buscar == pizza.codigo && !pizza.eliminada)
            {
                archivo_ventas.open(nombre_archivo_ventas, ios::app);
                if (archivo_ventas.good())
                {
                    cout << "Ingresar carnet de cliente: ";
                    cin >> venta.carnet_cliente;
                    venta.codigo_pizza = pizza.codigo;
                    cout << "Código de pizza: " << venta.codigo_pizza << endl;
                    venta.tamanio = pizza.tamanio;
                    cout << "Tamaño de pizza: " << tamanios[venta.tamanio - 1] << endl;
                    cout << "Ingresar cantidad de pizzas vendidas: ";
                    cin >> venta.cantidad_pizzas_vendidas;

                    archivo_ventas << venta.carnet_cliente << ";" << venta.codigo_pizza << ";" << tamanios[venta.tamanio - 1] << ";" << venta.cantidad_pizzas_vendidas << endl;
                }
                else
                {
                    cout << "No se pudo abrir archivo de ventas." << endl;
                }
                encontrado = true;
                system("pause");
                archivo_ventas.close();
            }
        }
    }
    else
    {
        cout << "No se pudo abrir archivo binario de pizzas." << endl;
        system("pause");
    }
    archivo_pizzas.close();
}