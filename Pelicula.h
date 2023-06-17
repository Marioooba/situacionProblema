
#include "Video.h"
#ifndef PELICULA_H
#define PELICULA_H

class Pelicula : public Video
{
public:
    Pelicula(string id, string nombre, double duracion, string genero, double calificacion, string fechaEstreno);
};

#endif