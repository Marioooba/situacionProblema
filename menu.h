/*
Autor: MARIO ALBERTO PÉREZ BARRERA  A01799928
PROGRAMACION ORIENTADA A OBJETOS
SITUACION PROBLEMA


SE IMPLEMENTA LA CLASE MENU
*/


#ifndef MENU_H
#define MENU_H

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include "Video.h"
#include "Serie.h"

using namespace std;

class Menu
{
  vector<Video*> videos;
  vector<Serie*> series;
public:
  Menu();
  //SE LE PIDE AL USUARIO QUE CARGUE EL ARCHIVO
  void cargarArchivo();

  //SE MUESTRAN LOS VIDEOS SOLICITADOS
  void videosFiltrados();

  //MUESTRAN TODOS LOS EPISODIOS DE UNA SERIE
  void todosLosEpisodios();

  //MUESTRA LA CALIFICACION DE LOS VIDEOS
  void calificacionVideos();

  //FILTRA LOS VIDEOS POR CALIFICACION
  void buscarPorCalificacion();

  //FILTRA LOS VIDEOS POR GENERO
  void buscarPorGenero();

  //CALCULA EL PROMEDIO DE UNA SERIE
  void promedioSerie();

  //CALIFICA EL VIDEO SELECCIONADO POR EL USUARIO
  void calificarVideo();

  //MENU DE LA 2 OPCION
  void menuMostrarVideos();
};

#endif