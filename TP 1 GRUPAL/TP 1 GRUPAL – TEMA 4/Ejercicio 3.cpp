// 3) Se dispone de una lista de 10 grupos de números y cada uno de los grupos estará compuesto por 5 números. Se pide determinar e informar:
// a) Para cada uno de los grupos la cantidad de números primos que lo componen. Se informa 1 resultado para cada uno de los 10 grupos.
// b) El mínimo número par de cada uno de los grupos. Se informa 1 resultado para cada uno de los 10 grupos.
// c) El anteúltimo y último número positivo de cada uno de los grupos. Se informan 2 resultados para uno de los 10 grupos.

#include <iostream>
using namespace std;

int main()
{
    system("color 6");
    // Variables
    int n;
    // Punto 1
    int cantidadPrimos, contadorDivisores;
    // Punto 2
    int menorNumeroPar;
    bool numeroPar;
    // Punto 3
    int ultimo, Anteultimo, temp;

    // Desarrollo del Programa
    for (int g = 0; g < 1; g++)
    {
        // Punto 1
        cantidadPrimos = 0;

        // Punto 2
        numeroPar = false;

        // Punto 3
        ultimo = 0;
        Anteultimo = 0;

        for (int p = 0; p < 5; p++)
        {
            cin >> n;

            // Punto 1
            contadorDivisores = 0;
            for (int i = 1; i <= n; i++)
            {
                if (n % i == 0)
                    contadorDivisores++;
            }
            if (contadorDivisores == 2)
                cantidadPrimos++;

            // Punto 2
            if ((n % 2 == 0) && (!numeroPar))
            {
                numeroPar = true;
                menorNumeroPar = n;
            }
            else if ((n % 2 == 0) && (n < menorNumeroPar))
                menorNumeroPar = n;

            // Punto 3
            if (ultimo == 0)
            {
                ultimo = n;
            }
            else if (Anteultimo == 0)
            {
                if (n > ultimo)
                {
                    Anteultimo = ultimo;
                    ultimo = n;
                }
                else
                {
                    Anteultimo = n;
                }
            }
            else
            {
                temp = ultimo;
                if (n > ultimo)
                {
                    ultimo = n;
                }
                if (temp < ultimo)
                {
                    Anteultimo = temp;
                }
                else if (n > Anteultimo)
                {
                    Anteultimo = n;
                }
            }
        }
        // Punto 1
        cout << "\nNUMEROS PRIMOS ENCONTRADO: " << cantidadPrimos << endl;

        // Punto 2
        cout << "\nMENOR NUMERO PAR ENCONTRADO: " << menorNumeroPar << endl;
        puts("");

        // Punto 3
        cout << "ULTIMO NUMERO POSITIVO: " << ultimo << endl;
        cout << "ANTE ULTIMO NUMERO POSITIVO: " << Anteultimo << endl;
    }

    // Fin del Programa
    // system("pause>nul");
    return 0;
}