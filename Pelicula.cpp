/*
Autor: MARIO ALBERTO PÉREZ BARRERA  A01799928
PROGRAMACION ORIENTADA A OBJETOS
SITUACION PROBLEMA


SE IMPLEMENTA LA CLASE Pelicula
*/

#include "Pelicula.h"

Pelicula::Pelicula(string id, string nombre, int duracion,  vector<string> generos, double calificacion, string fechaEstreno) : Video(id, nombre, duracion, generos, calificacion, fechaEstreno)
{
}

void Pelicula::verVideo()
{
   cout << "Pelicula: " << endl;
   Video::verVideo();
}
