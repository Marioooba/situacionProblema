/*
Autor: MARIO ALBERTO PÉREZ BARRERA  A01799928
PROGRAMACION ORIENTADA A OBJETOS
SITUACION PROBLEMA


SE IMPLEMENTAN LOS CONSTRUCTORES DE LA CLASE SERIE
*/

#include <iostream>
#include <string>
#include <vector>

#include "Video.h"
#include "Serie.h"

using namespace std;

Serie::Serie(string id, string nombre, int duracion, vector<string> generos, double calificacion, string fechaEstreno, string idEpisodio, string nombreEpisodio, int numEpisodio, int numTemporada) : Video(id, nombre, duracion, generos, calificacion, fechaEstreno) {
  this->idEpisodio = idEpisodio;
  this->nombreEpisodio = nombreEpisodio;
  this->numEpisodio = numEpisodio;
  this->numTemporada = numTemporada;
}

string Serie::getIdEpisodio() {
  return idEpisodio;
}

string Serie::getEpisodio() {
  return nombreEpisodio;
}

int Serie::getNumEpisodio() {
  return numEpisodio;
}

int Serie::getNumTemporada() {
  return numTemporada;
}


void Serie::verVideo() {
  Video::verVideo();
  cout << "ID Episodio: " << this->idEpisodio << endl;
  cout << "Nombre Episodio: " << this->nombreEpisodio << endl;
  cout << "Número Episodio: " << this->numEpisodio << endl;
  cout << "Número Temporada: " << this->numTemporada << endl;
}

