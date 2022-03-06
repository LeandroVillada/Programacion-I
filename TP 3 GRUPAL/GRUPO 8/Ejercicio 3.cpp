// Una rotación de vectores es cuando quitas algunos elementos del final y luego se los agregas al frente. Por ejemplo, [1,2,3,4,5,6] rotado seria [3,4,5,6,1,2].
// Escriba una función que acepte dos vectores y devuelva verdadero si el primero es la rotación del otro.
// Por ejemplo:
// v1 = [6, 3, 1, 5] y v2 = mitad3, 1, 5, 6] debería devolver verdadero.
// v1 = [6, 3, 1, 5, 5] y v2 = mitad1, 5, 5, 6, 3] debería devolver verdadero.
// v1 = [1, 2, 3, 4] y v2 = mitad3, 4, 2, 1] debería devolver falso.
// v1 = [1, 2, 3, 4] y v2 = mitad1, 2, 3, 4, 4] debería devolver falso
#include <iostream>
using namespace std;

// Prototipos de Funciones
void cargarVector(int v[], int tam);
bool compararRotacionVectores(int *, int, int *, int);

int main()
{
    system("color 6");
    // Variables
    int *vector1, tamanio1;
    int *vector2, tamanio2;

    // Desarrollo del Programa
    cout << "INGRESAR EL TAMANIO DEL VECTOR 1: ";
    cin >> tamanio1;
    vector1 = new int[tamanio1];
    cargarVector(vector1, tamanio1);
    cout << "INGRESAR EL TAMANIO DEL VECTOR 2: ";
    cin >> tamanio2;
    vector2 = new int[tamanio2];
    cargarVector(vector2, tamanio2);
    if (compararRotacionVectores(vector1, tamanio1, vector2, tamanio2))
        cout << "VERDADERO.";
    else
        cout << "FALSO.";

    // Fin del Programa
    // system("pause>nul");
    return 0;
}

// Desarrollo de Funciones
void cargarVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << "INGRESE NUMERO: ";
        cin >> v[i];
    }
}
bool compararRotacionVectores(int *v1, int tam1, int *v2, int tam2)
{
    int mitad = ((tam1 - tam1 % 2) / 2), contador = 0;
    for (int i = 0; i < tam1; i++)
    {
        if (i < mitad)
        {
            if (v1[i] == v2[tam1 - mitad + i])
                contador++;
        }
        else if (v1[i] == v2[i - mitad])
            contador++;
    }
    if ((contador != tam1) || (tam1 != tam2))
        return false;
    return true;
}