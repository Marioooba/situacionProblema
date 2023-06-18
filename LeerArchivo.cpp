/*
MARIO ALBERTO PÉREZ BARRERA

LEER EL ARCHIVO DE TEXTO EN C++
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


int leerArchivo(string line) {
  int contadorElementos = 0;      // Contador de elementos
  int ultimoDigito;   // Índice del último dígito encontrado

  for (int i = 0; i < line.length(); i++) {
    // Si se encuentra una coma y el carácter anterior no es una coma
    if (line[i] == ',' && line[i - 1] != ',') {
      contadorElementos++;                  // Incrementar el contador
      ultimoDigito = i;         // Actualizar el índice del último dígito encontrado
    }
  }

  // Verificar si hay un elemento adicional después de la última coma
  if (line[ultimoDigito + 1] != ',') {
    contadorElementos++;        // Incrementar el contador
  }

  return contadorElementos;     // Devolver la cantidad de elementos encontrados
}

vector<string> separar(const string &input, char delimiter) {
  vector<string> tokens;     // Vector para almacenar las subcadenas resultantes
  istringstream iss(input);  // Objeto istringstream para procesar la cadena de texto
  string token;              // Variable para almacenar cada subcadena

  // Mientras se pueda obtener una subcadena del istringstream usando el delimitador
  while (getline(iss, token, delimiter)) {
    tokens.push_back(token);  // Agregar la subcadena al vector de subcadenas
  }

  return tokens;             // Devolver el vector con las subcadenas resultantes
}

string quitarEspacios(const string& str) {
  size_t start = str.find_first_not_of(' ');           // Posición del primer carácter no espacial
  size_t end = str.find_last_not_of(' ');              // Posición del último carácter no espacial

  if (start == string::npos || end == string::npos) {
    // La cadena está compuesta completamente por espacios en blanco
    return "";
  }

  return str.substr(start, end - start + 1);           // Extraer la subcadena sin los espacios en blanco al inicio y al final
}


//FUNCION IMPLEMENTADA DURANTE LA CLASE, FUE CAMBIADA DEBIDO A QUE MOSTRABA MUCHA BASURA, SE BUSCO LA OPTIMIZACION

/*
int main(int argc, char const *argv[])
{
    string archivo;
    cout << "Ingresa el nombre del archivo en formato CSV, Ejemplo: (''MiArchivo.csv''): " << endl;
    cin >> archivo;
    ifstream entrada(archivo);
    if (!entrada){
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    // Excepciones
    // entrada.flags(ios_base::failbit);
    entrada.exceptions(ifstream::failbit);

    try
    {
        entrada.open(archivo);
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
    *
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
        *
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

*/
