
/*
Autor: MARIO ALBERTO PÉREZ BARRERA  A01799928
PROGRAMACION ORIENTADA A OBJETOS
SITUACION PROBLEMA


SE IMPLEMENTA LA CLASE VIDEO
*/
#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Video
{
    // Declaramos las variables de instancia para la clase Video
    string id, nombre, fechaEstreno;
    int duracion;
    vector<string> generos;
    double calificacion;

public:
    // Constructor de la clase Video con parámetros
    Video(string id, string nombre, int duracion, vector<string> generos, double calificacion, string fechaEstreno);
    
    // Función para establecer la calificación del video
    void setCalificacion(float calificacion);
    
    // Función para obtener el ID del video
    string getIdVideo();
    
    // Función para obtener el nombre del video
    string getNombre();
    
    // Función para obtener la duración del video
    float getDuracion();
    
    // Función para obtener los géneros del video como un vector de cadenas
    vector<string> getGenerosVideo();
    
    // Función para imprimir los géneros del video en la consola
    void videoGeneros();
    
    // Función virtual para ver el video (será implementada en clases derivadas)
    virtual void verVideo();
    
    // Función para obtener la calificación del video
    float getCalificacion();
    
    // Función para obtener la fecha de estreno del video
    string getFechaEstreno();
    
    // Función para verificar si el video tiene un género específico
    bool tieneGenero(string genero);
};

#endif // !VIDEO_H
