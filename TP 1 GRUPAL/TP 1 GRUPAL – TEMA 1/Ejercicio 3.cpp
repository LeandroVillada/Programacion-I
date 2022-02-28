// 3) Se dispone de una lista de 10 grupos de números y cada uno de los grupos estará compuesto por 5 números. Se pide determinar e informar:
// a) Para cada uno de los 10 grupos el promedio de los números que lo componen. Se informa 1 resultado para cada uno de los 10 grupos.
// b) Determinar e informar el valor máximo de todos los grupos, indicando en que grupo se encontró y su posición relativa en el mismo. Se informan 2 resultados al final de todo.
// c) Indicar cuál de los 10 grupos tiene el menor de los promedios y cuál es ese valor promedio. Se informan 2 resultados al final de todo.
#include <iostream>
using namespace std;

int main()
{
    system("color 6");
    // Variables
    int n;
    // Punto 1
    float promedio, suma;
    // Punto 2
    int maximo = 0, posMaximo, posGrupoMaximo;
    // Punto 3
    int posMenorPromedio;
    float menorPromedio = 1;

    // Desarrollo del Programa
    for (int g = 0; g < 10; g++)
    {
        suma = 0;
        for (int p = 0; p < 5; p++)
        {
            cin >> n;
            // Punto 1
            suma += n;

            // Punto 2
            if (n >= maximo)
            {
                maximo = n;
                posGrupoMaximo = g+1;
                posMaximo = p+1;
            }
        }
        // Punto 1
        promedio = suma / 5;
        cout << "\nPROMEDIO DE ESTE GRUPO: " << promedio << endl
             << endl;

        // Punto 3
        if (g == 0)
        {
            menorPromedio = promedio;
            posMenorPromedio = g + 1;
        }
        else
        {
            if (promedio < menorPromedio)
            {
                menorPromedio = menorPromedio;
                posMenorPromedio = g + 1;
            }
        }
    }
    // Punto 2
    cout << "\nMAXIMO NUMERO ENCONTRADO: " << maximo << " GRUPO: " << posGrupoMaximo << " POSICION: " << posMaximo << endl;
    // Punto 3
    cout << "\nMENOR PROMEDIO ENCONTRADO: " << menorPromedio << " GRUPO: " << posMenorPromedio << endl;

    // Fin del Programa
    system("pause>nul");
    return 0;
}