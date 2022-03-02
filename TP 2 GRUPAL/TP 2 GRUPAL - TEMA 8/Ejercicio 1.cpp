// 1) Dada una lista de números compuesta por 20 grupos y cada grupo separado del siguiente por un cero, se pide determinar e informar:
// a) Para cada uno de los grupos el máximo de los números pares y el mínimo de los números impares.
// b) Para cada uno de los grupos analizar si está formado por una secuencia de todos números ordenados de mayor a menor, en tal caso para ese grupo indicar un cartel al final de ese grupo con la leyenda: “todos ordenados”, caso contrario no se emitirá ningún cartel.
#include <iostream>
using namespace std;

int main()
{
    system("color 6");
    // Variables
    int n;
    // Punto A
    int maximoPar = 1, minimoImpar = 2;
    // Punto B
    int temp;
    bool primerNumero, ordenado;
    // Punto C
    int contadorDePrimos = 0, divisores;

    // Desarrollo del Programa
    for (int g = 0; g < 1; g++)
    {
        cin >> n;
        // Punto B
        primerNumero = false;
        ordenado = true;
        while (n != 0)
        {
            // Punto A
            if (n % 2 == 0)
            {
                if (maximoPar == 1)
                    maximoPar = n;
                else
                {
                    if (n > maximoPar)
                        maximoPar = n;
                }
            }
            else
            {
                if (minimoImpar == 2)
                    minimoImpar = n;
                else
                {
                    if (n < minimoImpar)
                        minimoImpar = n;
                }
            }
            // Punto B
            if (!primerNumero)
            {
                primerNumero = true;
                temp = n;
            }
            else if (n < temp)
                ordenado = false;
            // Punto C
            divisores=0;
            for (int i = 1; i <= n; i++)
            {
                if (n % i == 0)
                    divisores++;
            }
            if (divisores == 2)
                contadorDePrimos++;

            cin >> n;
        }
        // Punto A
        if (maximoPar != 1)
            cout << "\nMAXIMO PAR: " << maximoPar << endl;
        if (minimoImpar != 2)
            cout << "\nMINIMO IMPAR: " << minimoImpar << endl;

        // Punto B
        if (ordenado)
            cout << "\nTODOS ORDENADOS" << endl;
        puts("");
    }
    // Punto C
    cout << "TOTAL DE PRIMOS: " << contadorDePrimos << endl;

    // Fin del Programa
    // system("pause>nul");
    return 0;
}