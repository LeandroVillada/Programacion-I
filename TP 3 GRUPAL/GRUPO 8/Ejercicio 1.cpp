// Hacer una función que dado un número entero positivo indique cuál es el número primo mayor más cercano.
// Por ejemplo, si el usuario ingresa 24, el programa devolverá 29 pues es el número primo más cercano mayor que 24.
// Por ejemplo, si el usuario ingresa 5 el programa devolverá 7 pues es el número primo más cercado mayor que 7.
#include <iostream>
using namespace std;

// Prototipos de Funciones
int buscarNumeroPrimoCercano(int);

int main()
{
    system("color 6");
    // Variables
    int numero;

    // Desarrollo del Programa
    cout << "INGRESAR UN NUMERO: ";
    cin >> numero;
    cout << "PRIMO MAYOR MAS CERCANO: " << buscarNumeroPrimoCercano(numero) << endl;

    // Fin del Programa
    // system("pause>nul");
    return 0;
}

// Desarrollo de Funciones
int buscarNumeroPrimoCercano(int n)
{
    int divisores;
    while (true)
    {
        n++;
        divisores = 0;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                divisores++;
        }
        if (divisores == 2)
            break;
    }
    return n;
}