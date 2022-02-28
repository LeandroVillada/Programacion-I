#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("color 6");
    int n;
    bool numeroNegativo = false;
    int primerMaximo, segundoMaximo, temp;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        if (n < 0)
        {
            if (!numeroNegativo)
            {
                primerMaximo = n;
                numeroNegativo = true;
            }
            else
            {
                temp = primerMaximo;
                if (n > primerMaximo)
                {
                    primerMaximo = n;
                }
                if (n < primerMaximo)
                {
                    segundoMaximo = n;
                }
                if (temp < primerMaximo)
                {
                    segundoMaximo = temp;
                }

            }
        }
    }
    // Punto B
    cout << "EL PRIMER MAXIMO ES: " << primerMaximo << endl;
    cout << "EL SEGUNDO MAXIMO ES: " << segundoMaximo << endl;
    
    // Fin del Programa
    system("pause>nul");
    return 0;
}