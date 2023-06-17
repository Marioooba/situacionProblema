#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using std::string;
#include <iostream>
#include <vector>
using namespace std;

class Video
{
protected:
    string id;
    string nombre;
    double duracion;
    string genero;
    double calificacion;
    string fechaEstreno;

public:
    // Constructor que recibe todos los parámetros
    Video(string id, string nombre, double duracion, string genero, double calificacion, string fechaEstreno);

    // Getters para acceder a nuestras variables
    string getId();
    string getNombre();
    double getDuracion();
    string getGenero();
    double getCalificacion();
    string getFechaEstreno();
    virtual void verVideo();
    void setCalificacion(double calificacion);
};

#endif