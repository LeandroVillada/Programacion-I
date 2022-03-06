// Una aerolínea cuenta con una flota de aviones y los siguientes lotes de información.
// Un primer lote contiene los datos de la flota de aviones. Cada registro contiene los siguientes datos:
// - Matrícula del avión (1 a aviones)
// - Cantidad de asientos
// Este lote se ingresa desordenado y contiene aviones registros.
// Un segundo lote contiene los datos de los vuelos efectuados por los aviones durante el mes anterior, cada registro contiene los siguientes datos.
// - Matrícula del avión (1 a aviones)
// - Legajo del piloto (1 a 50)
// - Día del vuelo (1 al dias)
// - Cantidad de pasajes vendidos
// Este lote se ingresa desordenado y finaliza con un registro con día del vuelo igual a cero. Puede haber varios registros para el mismo avión, para el mismo día, para el mismo piloto, etc.
// DEBIDO A SU TAMAÑO DESCONOCIDO, ESTE LOTE NO SE PUEDE CARGAR
// DIRECTO EN MEMORIA EN VECTORES Y/O MATRICES
// Se pide a partir de los lotes anteriores, generar los siguientes listados
// a) Un listado detallado avión por avión con los vuelos que haya efectuado durante el mes.
//  Matrícula del Avión: 999
// Día: 1 Cantidad de vuelos: 99
// Día: 2 Cantidad de vuelos: 99
// b) Un listado informando por cada día la cantidad total de pasajes vendidos con el siguiente
// formato:
// Día: 1 Cantidad de pasajes vendidos: 99
// Día: 2 Cantidad de pasajes vendidos: 99
// c) Un listado indicando para cada avión el porcentaje de ocupación promedio que tuvo considerando todos los vuelos efectuados.

// d) Un listado indicando para cada piloto la cantidad de vuelos que efectuó en cada quincena con el siguiente formato:
//  Legajo del Piloto: 99
// Quincena: 1 Cantidad de vuelos: 99
// Quincena: 2 Cantidad de vuelos: 99

// PAUTA 1. EN ESTE EXAMEN NO ESTA PERMITIDO UTILIZAR NINGUN SWITCH NI IF QUE UTILICE MÁS DE TRES (3) SALIDAS.
// PAUTA 2. EL EXAMEN DEBE CONTENER AL MENOS 4 FUNCIONES/RUTINAS. DENTRO DE ESE TOTAL DE 4 FUNCIONES LA FUNCIONES QUE PONEN UNA VARIABLE SIMPLE/VECTOR/MATRIZ EN CERO NO SE CUENTAN.
#include <iostream>
using namespace std;

const int aviones = 20;
const int dias = 31;

// Prototipos de Funciones

// Datos de la flota de aviones.
void primerLote(int *);
// Datos de los vuelos efectuados por los aviones durante el mes anterior.
void segundoLote(int (*)[dias], int *, int *, float *, int *, int (*)[2]);

// Punto A
// Un listado detallado avión por avión con los vuelos que haya efectuado durante el mes.
void listarVuelosEfectuadosDuranteElMes(int (*)[dias]);

// Punto B
// Un listado informando por cada día la cantidad total de pasajes vendidos
void listarCantidadDePasajesVendidos(int *);

// Punto C
// Un listado indicando para cada avión el porcentaje de ocupación promedio que tuvo considerando todos los vuelos efectuados.
void listarPorcentajeDeOcupacionPromedio(int *, float *);

// Punto D
// Un listado indicando para cada piloto la cantidad de vuelos que efectuó en cada quincena
void listarQuincenaConVuelosDePilotos(int (*)[2]);

int main()
{
    system("color 6");
    // Variables

    // Primer Lote
    int cantidadAsientos[aviones] = {0};

    // Punto A
    int cantidadVuelosAvion[aviones][dias] = {0};

    // Punto B
    int pasajesVendidosPorDia[dias] = {0};

    // Punto C
    int vuelosTotales[aviones] = {0};
    float porcentajeTotalOcupacion[aviones] = {0};

    // Punto D
    int cantidadVuelosQuincenasPorPiloto[50][2] = {0};

    // Desarrollo del Programa
    // Primer Lote
    primerLote(cantidadAsientos);
    puts("");
    // Segundo Lote
    segundoLote(cantidadVuelosAvion, pasajesVendidosPorDia, vuelosTotales, porcentajeTotalOcupacion, cantidadAsientos, cantidadVuelosQuincenasPorPiloto);
    puts("");
    // Punto A
    listarVuelosEfectuadosDuranteElMes(cantidadVuelosAvion);
    puts("");
    // Punto B
    listarCantidadDePasajesVendidos(pasajesVendidosPorDia);
    puts("");
    // Punto C
    listarPorcentajeDeOcupacionPromedio(vuelosTotales, porcentajeTotalOcupacion);
    puts("");
    // Punto D
    listarQuincenaConVuelosDePilotos(cantidadVuelosQuincenasPorPiloto);

    // Fin del Programa
    system("pause>nul");
    return 0;
}

// Desarrollo de Funciones
void primerLote(int *cantidadAsientos)
{
    int matriculaAvion; // (1 a aviones)
    cout << "INGRESAR LA MATRICULA DEL AVION: ";
    cin >> matriculaAvion;
    while (matriculaAvion != 0) // Cambiar while * for(0;<aviones)
    {
        cout << "INGRESAR LA CANTIDAD DE ASIENTOS DEL AVION: ";
        cin >> cantidadAsientos[matriculaAvion - 1];
        cout << "INGRESAR LA MATRICULA DEL AVION: ";
        cin >> matriculaAvion;
    }
}
void segundoLote(int cantidadVuelosAvion[][31], int *pasajesVendidosPorDia, int *vuelosTotales, float *porcentajeTotalOcupacion, int *cantidadAsientos, int cantidadVuelosQuincenasPorPiloto[][2])
{
    int matriculaAvion; // (1 al aviones)
    int LegajoPiloto;   // (1 al 50)
    int diaVuelo;       // (1 al dias)
    int cantidadPasajesVendidos;
    cout << "INGRESAR EL DIA DEL VUELO: ";
    cin >> diaVuelo;
    while (diaVuelo != 0)
    {
        cout << "INGRESAR LA MATRICULA DEL AVION: ";
        cin >> matriculaAvion;
        cout << "INGRESAR EL LEGAJO DEL PILOTO: ";
        cin >> LegajoPiloto;
        cout << "CANTIDAD DE PASAJES VENDIDOS: ";
        cin >> cantidadPasajesVendidos;

        // Punto A
        cantidadVuelosAvion[matriculaAvion - 1][diaVuelo - 1]++;
        // Punto B
        pasajesVendidosPorDia[diaVuelo - 1] += cantidadPasajesVendidos;
        // Punto C
        vuelosTotales[matriculaAvion - 1]++;
        porcentajeTotalOcupacion[matriculaAvion - 1] += (cantidadPasajesVendidos * 100) / cantidadAsientos[matriculaAvion - 1];
        // Punto D
        if (diaVuelo < 16)
            cantidadVuelosQuincenasPorPiloto[LegajoPiloto - 1][0]++;
        else
            cantidadVuelosQuincenasPorPiloto[LegajoPiloto - 1][1]++;

        cout << "INGRESAR EL DIA DEL VUELO: ";
        cin >> diaVuelo;
    }
}
void listarVuelosEfectuadosDuranteElMes(int cantidadVuelosAvion[][dias])
{
    for (int c = 0; c < aviones; c++)
    {
        cout << "Matricula del avion: " << c + 1 << endl;
        for (int f = 0; f < dias; f++)
        {
            if (cantidadVuelosAvion[c][f] != 0)
                cout << "Dia: " << f + 1 << " Cantidad de vuelos: " << cantidadVuelosAvion[c][f] << endl;
        }
    }
}
void listarCantidadDePasajesVendidos(int *pasajesVendidosPorDia)
{
    for (int i = 0; i < dias; i++)
    {
        if (pasajesVendidosPorDia[i] != 0)
            cout << "Dia: " << i + 1 << " Cantidad de pasajes vendidos: " << pasajesVendidosPorDia[i] << endl;
    }
}
void listarPorcentajeDeOcupacionPromedio(int *vuelosTotales, float *PorcentajeTotalOcupacion)
{
    for (int i = 0; i < aviones; i++)
    {
        if (vuelosTotales[i] != 0)
            cout << "Avion: " << i + 1 << "\tPromedio del porcentaje de ocupacion: " << float(PorcentajeTotalOcupacion[i] / vuelosTotales[i]) << " %." << endl;
    }
}
void listarQuincenaConVuelosDePilotos(int cantidadVuelosQuincenasPorPiloto[][2])
{
    for (int c = 0; c < 50; c++)
    {
        for (int f = 0; f < 2; f++)
        {
            if (f == 0)
                cout << "Legajo del Piloto: " << c+1 << endl;
            if (cantidadVuelosQuincenasPorPiloto[c][f] != 0)
                cout << "Quincena: " << f + 1 << " Cantidad de vuelos: " << cantidadVuelosQuincenasPorPiloto[c][f] << endl;
        }
    }
}