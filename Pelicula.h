/*
Autor: MARIO ALBERTO PÉREZ BARRERA  A01799928
PROGRAMACION ORIENTADA A OBJETOS
SITUACION PROBLEMA


SE IMPLEMENTA LA CLASE Pelicula
*/

#include "Video.h"
#ifndef PELICULA_H
#define PELICULA_H

class Pelicula : public Video
{
public:
    Pelicula(string id, string nombre, int duracion,  vector<string> generos, double calificacion, string fechaEstreno);
    void verVideo();
    //friend ostream& operator<<(ostream& os, Pelicula& p);
};

#endif