// Una empresa dispone de un lote de registros con la siguiente información de sus 100 artículos:
// - Código de Artículo (1 a 200)
// - Categoría del Artículo (1 a 10)
// - Precio Unitario
// Este lote está ordenado por Precio Unitario
// Existe un lote de registros con las ventas efectuadas durante el año anterior, cada uno de ellos con los siguientes datos:
// - Mes de la venta (1 a 12)
// - Día de la venta (1 a 31)
// - Número de vendedor (1 a 50)
// - Código de Artículo (1 a 200)
// - Cantidad vendida
// Este lote está desordenado y finaliza con un registro con mes igual a cero. Puede haber más de un registro para el mismo mes, vendedor o artículo.
// DEBIDO A SU TAMAÑO DESCONOCIDO, ESTE LOTE NO SE PUEDE CARGAR DIRECTO EN MEMORIA EN VECTORES O MATRICES.
// Se pide determinar e informar:
// a) La recaudación mes por mes con el siguiente formato:
// Mes 1: Recaudación total: 9999,99
// Mes 2: Recaudación total: 9999,99
// b) Indicar los bimestres en los que no hubo ninguna venta.
//  Bimestre sin ventas:
//  3
//  6
// c) Los números de los vendedores inactivos, es decir sin ventas, durante 3 o más meses consecutivos en el año. Cada vendedor debe ser listado una sola vez.
// d) La cantidad de artículos para cada una de las categorías.
// PAUTA 1. EN ESTE EXAMEN NO ESTA PERMITIDO UTILIZAR NINGUN SWITCH NI IF QUE UTILICE MÁS DE TRES (3) SALIDAS.
// PAUTA 2. EL EXAMEN DEBE CONTENER AL MENOS 4 FUNCIONES/RUTINAS. DENTRO DE ESE TOTAL DE 4 FUNCIONES LA FUNCIONES QUE PONEN UNA VARIABLE SIMPLE/VECTOR/MATRIZ EN CERO NO SE CUENTAN.

#include <iostream>
using namespace std;

const int articulos = 20;
const int vendedores = 10;

// Registros de artículos:
void primerLote(int *, float *);
// Ventas efectuadas el anio anterior
void segundoLote(float *, float *, int *, int (*)[12]);
// Punto A
// Listar recaudacion total mes por mes
void listarRecaudacionTotalMes(float *);
// Punto B
// Listar bimestres en lo que no hubo ventas
void listarBimestresSinVentas(int *);
// Punto C
// Listar vendedores inactivos durante 3 meses consecutivos en el anio
void listarVendedoresInactivos(int (*)[12]);
bool calcularInactividadConsecutiva(int (*)[12], int);
// Punto D
// Listar cantidad de articulos para cada una de las categorias
void listarCantidadArticulosPorCategoria(int *);

int main()
{
    system("color 6");
    // Variables
    int categoriaArticulo[articulos];
    float precioUnitario[articulos];

    // Punto A
    float recaudacionTotalMes[12] = {0};

    // Punto B
    int bimestres[6] = {0};

    // Punto C
    int actividadPorMesVendedores[vendedores][12] = {0};

    // Desarrollo del Programa
    // Primer Lote
    primerLote(categoriaArticulo, precioUnitario);
    // Segundo Lote
    segundoLote(precioUnitario, recaudacionTotalMes, bimestres, actividadPorMesVendedores);
    // Punto A
    listarRecaudacionTotalMes(recaudacionTotalMes);
    // Punto B
    listarBimestresSinVentas(bimestres);
    // Punto C
    listarVendedoresInactivos(actividadPorMesVendedores);
    // Punto D
    listarCantidadArticulosPorCategoria(categoriaArticulo);

    // Fin del Programa
    system("pause>nul");
    return 0;
}

// Desarrollo de Funciones
void primerLote(int *categoriaArticulo, float *precioUnitario)
{
    int codigoArticulo; // (1 a 100)
    cout << "INGRESAR EL CODIGO DEL ARTICULO (1 A 200): ";
    cin >> codigoArticulo;
    while (codigoArticulo != 0)
    {
        cout << "INGRESAR LA CATEGORIA DEL ARTICULO (1 A 10): ";
        cin >> categoriaArticulo[codigoArticulo - 1];
        cout << "INGRESAR EL PRECIO UNITARIO: ";
        cin >> precioUnitario[codigoArticulo - 1];
        cout << "INGRESAR EL CODIGO DEL ARTICULO (1 A 200): ";
        cin >> codigoArticulo;
    }
}
void segundoLote(float *precioUnitario, float *recaudacionTotalMes, int *bimestres, int actividadPorMesVendedores[][12])
{
    int mesVenta;       // (1 a 12)
    int diaVenta;       // (1 a 31)
    int numeroVendedor; // (1 a 50)
    int codigoArticulo; // (1 a 100)
    int cantidadVendida;

    cout << "MES DE LA VENTA (1 a 12): ";
    cin >> mesVenta;
    while (mesVenta != 0)
    {
        cout << "DIA DE LA VENTA (1 a 31): ";
        cin >> diaVenta;
        cout << "NUMERO DE VENDEDOR (1 a 50): ";
        cin >> numeroVendedor;
        cout << "CODIGO DE ARTICULO (1 a 100): ";
        cin >> codigoArticulo;
        cout << "CANTIDAD VENDIDA: ";
        cin >> cantidadVendida;

        // Punto A
        recaudacionTotalMes[mesVenta - 1] += precioUnitario[codigoArticulo - 1] * cantidadVendida;
        // Punto B
        if (mesVenta % 2 != 0)
            bimestres[((mesVenta + 1) / 2) - 1]++;
        else
            bimestres[(mesVenta / 2) - 1]++;
        // Punto C
        actividadPorMesVendedores[numeroVendedor - 1][mesVenta - 1]++;

        cout << "MES DE LA VENTA (1 a 12): ";
        cin >> mesVenta;
    }
}
void listarRecaudacionTotalMes(float *recaudacionTotalMes)
{
    cout << "\nRecaudacion total mes por mes." << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << "Mes " << i + 1 << ": Recaudacion Total: " << recaudacionTotalMes[i] << endl;
    }
}
void listarBimestresSinVentas(int *bimestres)
{
    cout << "\nBimestres sin ventas:" << endl;
    for (int i = 0; i < 6; i++)
    {
        if (bimestres[i] == 0)
            cout << "\t" << i + 1 << endl;
    }
}
void listarVendedoresInactivos(int actividadPorMesVendedores[][12])
{
    cout << "\nVendedores inactivos durante 3 o mas meses consecutivos:" << endl;
    for (int i = 0; i < vendedores; i++)
    {
        if (calcularInactividadConsecutiva(actividadPorMesVendedores, i))
            cout << "\t" << i + 1 << endl;
    }
}
bool calcularInactividadConsecutiva(int actividadPorMesVendedores[][12], int vendedor)
{
    int contadorConsecutivos = 0;
    bool actividad = true;
    for (int i = 0; i < 12; i++)
    {
        if ((actividadPorMesVendedores[vendedor][i] == 0) && (actividad == true))
        {
            contadorConsecutivos = 0;
            actividad = false;
        }
        else if (actividadPorMesVendedores[vendedor][i] == 0)
            contadorConsecutivos++;
        else
        {
            actividad = true;
            if (contadorConsecutivos >= 3)
                return true;
        }
    }
    return false;
}
void listarCantidadArticulosPorCategoria(int *categoriaArticulo)
{
    cout << "\nCantidad de articulos para cada una de las categorias:" << endl;
    for (int i = 1; i <= 10; i++)
    {
        int cantidad = 0;
        for (int c = 0; c < vendedores; c++)
        {
            if (categoriaArticulo[c] == i)
                cantidad++;
        }
        cout << "Categoria " << i << ": " << cantidad << endl;
    }
}