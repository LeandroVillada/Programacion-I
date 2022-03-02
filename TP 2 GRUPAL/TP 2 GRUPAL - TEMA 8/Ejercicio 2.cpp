// 2) Un negocio de venta de alfajores tiene registrada la información de las ventas efectuadas durante el mes pasado entre todas las sucursales y el dueño le pidió a Ud., futuro programador, que le desarrolle un programa para obtener determinadas estadísticas.
// Los datos que se disponen por cada una de las ventas efectuadas son:
// - Número de sucursal (1 a 30)
// - Día de la venta (1 a 31)
// - Cantidad de cajas de alfajores vendidas
// - Importe de la venta
// - Forma de Pago (1=Débito, 2=Crédito, 3=Contado)
// Los datos están agrupados, no ordenados, por número de sucursal.
// Puede haber sucursales que no registraron ninguna venta en todo el mes o en algún día determinado. No habrá ventas con importes igual a cero.
// El final de todo el lote se indicará con un registro con número de sucursal igual a 0.
// Se pide determinar e informar:
// a) Indicar para cada sucursal la recaudación total entre todas sus ventas. Se informa 1 resultado por cada sucursal.
// b) Para cada sucursal la venta individual de mayor importe y la de segundo mayor importe, indicando el importe y el día que se efectuaron esas ventas. Se informan 4 resultados por cada sucursal.
// c) Para cada una de las sucursales el porcentaje de recaudación total por sus ventas discriminado en crédito, débito y contado. Se informan 3 resultados por cada sucursal.
// d) Informar en cuál de las sucursales la cantidad total de cajas de alfajores vendidos haya sido menor. Se informa 1 resultado al final
#include <iostream>
using namespace std;

int main()
{
    system("color 6");
    // Variables
    int numeroSucursal = 1, aux = numeroSucursal; //(1 a 30)
    int dia;                                      // (1 a 31)
    int cantidadVendida;                          // Cajas de alfajores
    float importe;                                // Importe de la venta
    int formaPago;                                // (1=Débito, 2=Crédito, 3=Contado)
    // Punto A
    float recaudacionTotal;
    // Punto B
    float primerMayorImporte, segundoMayorImporte;
    int diaPrimerMayorImporte, diaSegundoMayorImporte;
    // Punto C
    int debito, credito, contado;
    // Punto D
    int totalCajasVendidas, sucursalMenoresVendidas, sucursalMenorVentas = 0;

    // Desarrollo del Programa
    cout << "NUMERO DE SUCURSAL (1 a 30): ";
    cin >> numeroSucursal;
    while (numeroSucursal != 0)
    {
        // Punto A
        recaudacionTotal = 0;
        // Punto B
        primerMayorImporte = 0;
        segundoMayorImporte = 0;
        // Punto C
        debito = 0;
        credito = 0;
        contado = 0;
        // Punto D
        totalCajasVendidas = 0;

        aux = numeroSucursal;
        while (numeroSucursal == aux)
        {
            cout << "DIA (1 a 31): ";
            cin >> dia;
            cout << "CANTIDAD DE CAJAS DE ALFAJORES VENDIDAS: ";
            cin >> cantidadVendida;
            cout << "IMPORTE: ";
            cin >> importe;
            cout << "FORMA DE PAGO (1=Debito, 2=Credito, 3=Contado): ";
            cin >> formaPago;
            cout << "NUMERO DE SUCURSAL (1 a 30): ";
            cin >> numeroSucursal;

            // Punto A
            recaudacionTotal += importe;

            // Punto B
            if (primerMayorImporte == 0)
            {
                primerMayorImporte = importe;
                diaPrimerMayorImporte = dia;
            }
            else if (segundoMayorImporte == 0)
            {
                if (importe > primerMayorImporte)
                {
                    segundoMayorImporte = primerMayorImporte;
                    diaSegundoMayorImporte = diaPrimerMayorImporte;
                    primerMayorImporte = importe;
                    diaPrimerMayorImporte = dia;
                }
                else
                {
                    segundoMayorImporte = importe;
                    diaSegundoMayorImporte = dia;
                }
            }
            else
            {
                int temp = primerMayorImporte;
                int tempDia = diaPrimerMayorImporte;
                if (importe > primerMayorImporte)
                {
                    primerMayorImporte = importe;
                    diaPrimerMayorImporte = dia;
                }
                if (temp < primerMayorImporte)
                {
                    segundoMayorImporte = temp;
                    diaSegundoMayorImporte = tempDia;
                }
                else if (importe > segundoMayorImporte)
                {
                    segundoMayorImporte = importe;
                    diaSegundoMayorImporte = dia;
                }
            }

            // Punto C
            switch (formaPago)
            {
            case 1:
                debito++;
                break;
            case 2:
                credito++;
                break;
            case 3:
                contado++;
                break;
            }
            // Punto D
            totalCajasVendidas+=cantidadVendida;
        }
        // Punto A
        cout << "\nRECAUDACION TOTAL DE LA SUCURSAL " << aux << ": " << recaudacionTotal << endl;
        // Punto B
        if (primerMayorImporte != 0)
            cout << "PRIMER MAYOR IMPORTE: " << primerMayorImporte << " FUE EFECTUADO EL DIA " << diaPrimerMayorImporte << endl;
        if (segundoMayorImporte != 0)
            cout << "SEGUNDO MAYOR IMPORTE: " << segundoMayorImporte << " FUE EFECTUADO EL DIA " << diaSegundoMayorImporte << endl;
        // Punto C
        cout << "PORCENTAJE DE PAGOS EN DEBITOS: " << (float)debito * 100 / (debito + credito + contado) << endl;
        cout << "PORCENTAJE DE PAGOS EN CREDITOS: " << (float)credito * 100 / (debito + credito + contado) << endl;
        cout << "PORCENTAJE DE PAGOS EN CONTADO: " << (float)contado * 100 / (debito + credito + contado) << endl;
        // Punto D
        if (sucursalMenorVentas == 0)
        {
            sucursalMenoresVendidas=totalCajasVendidas;
            sucursalMenorVentas=aux;
        }
        else if (totalCajasVendidas < sucursalMenoresVendidas)
            {
                sucursalMenoresVendidas = totalCajasVendidas;
                sucursalMenorVentas = aux;
            }
        puts("");
    }
    // Punto D
    cout << "SUCURSAL CON MENOR CANTIDAD DE CAJAS DE ALFAJORES VENDIDAS: Sucursal " << sucursalMenorVentas << endl;

    // Fin del Programa
    // system("pause>nul");
    return 0;
}