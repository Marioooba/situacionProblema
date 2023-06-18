/*
Autor: MARIO ALBERTO PÉREZ BARRERA  A01799928
PROGRAMACION ORIENTADA A OBJETOS
SITUACION PROBLEMA


SE IMPLEMENTA LA CLASE SERIE
*/


#ifndef SERIE_H
#define SERIE_H

#include <iostream>
#include <string>
#include <vector>

#include "Video.h"

using namespace std;

class Serie : public Video
{
    // Declaramos las variables de instancia para la clase Serie
    string idEpisodio, nombreEpisodio;
    int numEpisodio, numTemporada;

public:
    // Constructor de la clase Serie con parámetros
    Serie(string id, string nombre, int duracion, vector<string> generos, double calificacion, string fechaEstreno, string idEpisodio, string nombreEpisodio, int numEpisodio, int numTemporada);
    
    // Función para obtener el ID del episodio
    string getIdEpisodio();
    
    // Función para obtener el nombre del episodio
    string getEpisodio();
    
    // Función para obtener el número de episodio
    int getNumEpisodio();
    
    // Función para obtener el número de temporada
    int getNumTemporada();
    
    // Función para ver el video (implementación de la función virtual en la clase base)
    void verVideo() override;
};

#endif // !SERIE_H
