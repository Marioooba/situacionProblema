#include "Video.h"

Video::Video(string id, string nombre, double duracion, string genero, double calificacion, string fechaEstreno)
{
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    this->calificacion = calificacion;
    this->fechaEstreno = fechaEstreno;
}

string Video::getId()
{
    return id;
}

string Video::getNombre()
{
    return nombre;
}

double Video::getDuracion()
{
    return duracion;
}

string Video::getGenero()
{
    return genero;
}

double Video::getCalificacion()
{
    return calificacion;
}

string Video::getFechaEstreno()
{
    return fechaEstreno;
}

void Video::verVideo()
{
    cout << "Nombre del video: " << nombre << "ID: " << id << endl;
}

void Video::setCalificacion(double calif)
{
    this->calificacion = calificacion;
}
