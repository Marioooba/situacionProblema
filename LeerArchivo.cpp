/*
MARIO ALBERTO PÉREZ BARRERA

LEER EL ARCHIVO DE TEXTO EN C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> separar(string linea);

int main(int argc, char const *argv[])
{
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string linea;
    int numeroLinea = 1;

    while (getline(entrada, linea))
    {
        vector<string> datos = separar(linea);
        cout << (numeroLinea++);
        if (datos.size() == 6)
        {
            cout << "Pelicula: ";
            //new Pelicula(datos); //Hacer un constructor en pelicula que reciba un vector
    
        } else
        {
            cout << "Episodio: ";
            //new Episodio(datos); //Hacer un constructor en episodio que reciba un vector
        }
        cout << endl;
        // cout << (numeroLinea++) << ": " <<linea << endl;
        /*
        separar(linea);
        numeroLinea++;
        if (numeroLinea == 5)
        {
            break;
        }
        */
    }

    entrada.close();

    return 0;
}

vector<string> separar(string linea)
{
    vector<string> tokens;       // Componentes de la línea
    stringstream entrada(linea); // flujo de datos a partir de una cadena
    string dato;                 // token individual
    int numeroTokens = 0;
    while (getline(entrada, dato, ','))
    {
        if (dato != "" & dato != "\n" && dato != "\r")
        {
            cout << dato << numeroTokens << endl;
            tokens.push_back(dato);     //Guarda en el vector
            numeroTokens++;
        }
    }
    return tokens;
    //cout << "Tokens: " << numeroTokens << endl << endl;
}
