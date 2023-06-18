/*
Autor: MARIO ALBERTO PÉREZ BARRERA  A01799928
PROGRAMACION ORIENTADA A OBJETOS
SITUACION PROBLEMA


SE IMPLEMENTAN LOS CONSTRUCTORES DE LA CLASE VIDEO
*/

#include <iostream>
#include <string>
#include <vector>

#include "Video.h"

using namespace std;

// Incluimos las bibliotecas necesarias y el archivo de encabezado "Video.h"

Video::Video(string id, string nombre, int duracion, vector<string> generos, double calificacion, string fechaEstreno)
{
  // Constructor de la clase Video que recibe los parámetros y los asigna a las variables de instancia correspondientes.
  this->id = id;
  this->nombre = nombre;
  this->duracion = duracion;
  this->generos = generos;
  this->calificacion = calificacion;
  this->fechaEstreno = fechaEstreno;
}

void Video::setCalificacion(float calificacion) {
  // Función para establecer la calificación del video.
  this->calificacion = calificacion;
}

string Video::getIdVideo() {
  // Función para obtener el ID del video.
  return id;
}

string Video::getNombre() {
  // Función para obtener el nombre del video.
  return nombre;
}

float Video::getDuracion() {
  // Función para obtener la duración del video.
  return duracion;
}

vector<string> Video::getGenerosVideo() {
  // Función para obtener los géneros del video como un vector de cadenas.
  return generos;
}

float Video::getCalificacion() {
  // Función para obtener la calificación del video.
  return calificacion;
}

string Video::getFechaEstreno() {
  // Función para obtener la fecha de estreno del video.
  return fechaEstreno;
}

void Video::videoGeneros() {
  // Función para imprimir los géneros del video en la consola.
  for (int i = 0; i < generos.size(); i++) {
    cout << generos[i] << " ";
  }
  cout << endl;
}


bool Video::tieneGenero(string genero) {
  // Función para verificar si el video tiene un género específico.
  for (int i = 0; i < generos.size(); i++) {
    if (generos[i] == genero) {
      return true;
    }
  }
  return false;
}

void Video::verVideo() {
  // Función virtual para ver el video.
  cout << "Id: " << id << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Duracion: " << duracion << endl;
  cout << "Generos: ";
  videoGeneros();
  cout << "Calificacion: " << calificacion << endl;
  cout << "Fecha de estreno: " << fechaEstreno << endl;
}