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

    // Excepciones
    // entrada.flags(ios_base::failbit);
    entrada.exceptions(ifstream::failbit);

    try
    {
        entrada.open("DatosPeliculas.csv");
    }
    catch (ifstream::failure &e)
    {
        cout << "ERROR excepcion al abrir el archivo" << endl;
        return -1;
    }
    /*
        //Manejo normal de error
        if(entrada.fail())
        {
            cout << "Error, no puedo leer el archivo..." << endl;
            return -1;
        }
    */
    string linea;
    int numeroLinea = 1;

    while (getline(entrada, linea))
    {
        vector<string> datos = separar(linea);
        cout << (numeroLinea++);
        if (datos.size() == 6)
        {
            cout << "Pelicula: ";
            // new Pelicula(datos); //Hacer un constructor en pelicula que reciba un vector
        }
        else
        {
            cout << "Episodio: ";
            // new Episodio(datos); //Hacer un constructor en episodio que reciba un vector
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
    try
    {
        entrada.close();
    }
    catch (ifstream::failure &e)
    {
        cout << "ERROR al procesar el archivo" << endl;
        return -1;
    }

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
            tokens.push_back(dato); // Guarda en el vector
            numeroTokens++;
        }
    }
    bool incorrecto = true;
    while (incorrecto)
    {
        try
        {
            cout << "tokens: " << tokens.at(tokens.size()) << endl;
            incorrecto = false;
        }
        catch (out_of_range &e)
        {
            cout << "Indice incorrecto" << endl;
            incorrecto = true;
        }
    }
    return tokens;
    // cout << "Tokens: " << numeroTokens << endl << endl;
}
