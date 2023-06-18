#ifndef LEERARCHIVO_H
#define LEERARCHIVO_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> separar(const string &input, char delimiter);
string quitarEspacios(string str);
int leerArchivo (string line);

#endif
