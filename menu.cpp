/*
Autor: MARIO ALBERTO PÉREZ BARRERA  A01799928
PROGRAMACION ORIENTADA A OBJETOS
SITUACION PROBLEMA


SE IMPLEMENTAN LOS CONSTRUCTORES DE LA CLASE MENU
*/

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "Video.h"
#include "Serie.h"
#include "Menu.h"
#include "LeerArchivo.h"

using namespace std;

Menu::Menu() {}

void Menu::cargarArchivo()
{
    ifstream file("DatosPeliculas.csv");
    string line;

    int linea = 0;

    while (getline(file, line))
    {
        if (linea == 0)
        {
            linea++;
            continue;
        }

        int count = leerArchivo(line); // Contar la cantidad de valores separados por comas en la línea
        string id, nombre, duracion, calificacion, fechaEstreno, idEpisodio,
            nombreEpisodio, temporada, numeroEpisodio, generos;

        stringstream ss(line);

        getline(ss, id, ',');           // Obtener el valor del ID hasta la coma
        getline(ss, nombre, ',');       // Obtener el valor del nombre hasta la coma
        getline(ss, duracion, ',');     // Obtener el valor de la duración hasta la coma
        getline(ss, generos, ',');      // Obtener el valor de los géneros hasta la coma
        getline(ss, calificacion, ','); // Obtener el valor de la calificación hasta la coma
        getline(ss, fechaEstreno, ','); // Obtener el valor de la fecha de estreno hasta la coma

        if (count == 10)
        {
            getline(ss, idEpisodio, ',');     // Obtener el valor del ID del episodio hasta la coma
            getline(ss, nombreEpisodio, ','); // Obtener el valor del nombre del episodio hasta la coma
            getline(ss, temporada, ',');      // Obtener el valor de la temporada hasta la coma
            getline(ss, numeroEpisodio, ','); // Obtener el valor del número del episodio hasta la coma

            Serie *serie =
                new Serie(id, nombre, stof(duracion), separar(generos, '&'),
                          stof(calificacion), fechaEstreno, idEpisodio,
                          nombreEpisodio, stoi(numeroEpisodio), stoi(temporada));

            this->series.push_back(serie); // Agregar la serie al vector de series
        }
        else if (count == 6)
        {
            Video *video =
                new Video(id, nombre, stof(duracion), separar(generos, '&'),
                          stof(calificacion), fechaEstreno);

            this->videos.push_back(video); // Agregar el video al vector de videos
        }
    }

    cout << "El archivo se cargo de manera exitosa" << endl;
    file.close();
}

void Menu::videosFiltrados()
{
    for (const auto &video : this->videos)
    {
        video->verVideo(); // Mostrar información del video en la consola
        cout << endl;
    }

    for (const auto &serie : this->series)
    {
        serie->verVideo(); // Mostrar información del episodio de la serie en la consola
        cout << endl;
    }
}

// Filtra los videos dependiendo de su calificacion
void Menu::buscarPorCalificacion()
{
    float calificacion;
    cout << "Ingrese la calificación minima que desea buscar: ";
    cin >> calificacion;

    // Recorre todos los videos y muestra aquellos que tengan una calificación mayor o igual a la calificación ingresada
    for (const auto &video : this->videos)
    {
        if (video->getCalificacion() >= calificacion)
        {
            video->verVideo(); // Muestra información del video en la consola
            cout << endl;
        }
    }
}

// Muestra la calificacion de un algun video
void Menu::calificacionVideos()
{
    float calificacion;
    cout << "Ingrese la calificación: ";
    cin >> calificacion;

    cout << "Peliculas con calificación mayor o igual a " << calificacion
         << endl;
    for (const auto &video : this->videos)
    {
        if (video->getCalificacion() >= calificacion)
        {
            video->verVideo(); // Muestra información de la película en la consola
            cout << endl;
        }
    }

    cout << "Episodios con calificación mayor o igual a " << calificacion
         << endl;
    for (const auto &serie : this->series)
    {
        if (serie->getCalificacion() >= calificacion)
        {
            serie->verVideo(); // Muestra información del episodio en la consola
            cout << endl;
        }
    }
}

void Menu::buscarPorGenero()
{
    string genero;
    cout << "-------------------------------------" << endl;
    cout << "Los generos que hay son: Acción\n"
            "2) Aventura\n"
            "3) Drama\n"
            "4) Fantasy\n"
            "5) Romance\n"
            "6) Sci-Fi\n"
            "7) Suspenso\n"
            "8) Animación\n"
            "9) Familiar\n"
            "10) Musical\n"
            "11) Guerra\n"
            "12) Crimen\n"
            "13) Misterio\n"
            "14) Comedia\n"
            "15) Western\n"
            "16) Biografía\n"
            << endl;
    cout << "-------------------------------------" << endl;
    cout << "Ingrese el genero que desea buscar, recuerde escribirlo tal cual: ";
    cin >> genero;

    cout << "Peliculas con género " << genero << endl;
    for (const auto &video : this->videos)
    {
        if (video->tieneGenero(genero))
        {
            video->verVideo(); // Muestra información de la película en la consola
            cout << endl;
        }
    }

    cout << "Episodios con género " << genero << endl;
    for (const auto &serie : this->series)
    {
        if (serie->tieneGenero(genero))
        {
            serie->verVideo();
            cout << endl;
        }
    }
}

// Muestra todos los episodios de una serie
void Menu::todosLosEpisodios()
{
    string nombreSerie;
    cout << "Ingrese el nombre de la serie: ";
    cin.ignore();
    getline(cin, nombreSerie);
    // Se realiza un for para encontrar las series y sus episodios
    for (const auto &serie : this->series)
    {
        if (serie->getNombre() == nombreSerie)
        {
            serie->verVideo(); // Muestra información del episodio en la consola
            cout << endl;
        }
    }
}

void Menu::calificarVideo()
{
    string nombreVideo;
    cout << "Ingrese el nombre de la pelicula/serie: ";
    cin.ignore();
    getline(cin, nombreVideo);

    bool encontrado = false;

    // Buscar el video en la lista de videos
    for (const auto &video : this->videos)
    {
        if (video->getNombre() == nombreVideo)
        {
            cout << "Calificacion actual: " << video->getCalificacion() << endl;
            float calificacion;
            cout << "Ingrese la calificación: ";
            cin >> calificacion;
            video->setCalificacion(calificacion);
            cout << "Calificación actualizada: " << video->getCalificacion() << endl;
            encontrado = true;
        }
    }

    // Si no se encontró el video en la lista de videos, buscarlo en la lista de series
    if (!encontrado)
    {
        for (const auto &serie : this->series)
        {
            if (serie->getEpisodio() == nombreVideo)
            {
                cout << "Calificacion actual: " << serie->getCalificacion() << endl;
                float calificacion;
                cout << "Ingrese la calificación: ";
                cin >> calificacion;
                serie->setCalificacion(calificacion);
                cout << "Calificación actualizada: " << serie->getCalificacion() << endl;
                encontrado = true;
            }
        }
    }

    // Si no se encontró el video ni en la lista de videos ni en la lista de series, mostrar un mensaje de error
    if (!encontrado)
    {
        cout << "No se encontró el video" << endl;
        return;
    }

    // Actualizar el archivo de datos con las calificaciones actualizadas

    ofstream file;
    file.open("DatosPeliculas.csv");

    // Escribir la cabecera del archivo
    file << "ID,Nombre Pelicula/Serie,Duración,Género,Calificación,Fecha Estreno,ID Episodio,Nombre Episodio,Temporada,Num Episodio" << endl;

    // Escribir los datos de los videos en el archivo
    for (const auto &video : this->videos)
    {
        file << video->getIdVideo() << "," << video->getNombre() << "," << video->getDuracion() << ",";
        for (const auto &genero : video->getGenerosVideo())
        {
            if (genero != video->getGenerosVideo().back())
            {
                file << genero;
                continue;
            }
            file << genero << "&";
        }
        file << "," << video->getCalificacion() << "," << video->getFechaEstreno() << endl;
    }

    // Escribir los datos de las series en el archivo
    for (const auto &serie : this->series)
    {
        file << serie->getIdVideo() << "," << serie->getNombre() << "," << serie->getDuracion() << ",";
        for (const auto &genero : serie->getGenerosVideo())
        {
            if (genero != serie->getGenerosVideo().back())
            {
                file << genero;
                continue;
            }
            file << genero << "&";
        }
        file << "," << serie->getCalificacion() << "," << serie->getFechaEstreno() << ","
             << serie->getIdEpisodio() << "," << serie->getEpisodio() << ","
             << serie->getNumTemporada() << "," << serie->getNumEpisodio() << endl;
    }

    file.close(); // Cerrar el archivo
}

void Menu::menuMostrarVideos()
{
    while (true)
    {
        system("clear");

        std::cout << "1. Mostrar videos por calificación" << std::endl;
        std::cout << "2. Mostrar videos por género" << std::endl;
        std::cout << "3. Mostrar todos los videos" << std::endl;
        std::cout << "4. Regresar" << std::endl;
        std::cout << "Ingrese una opción: ";

        int opcion;
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            buscarPorCalificacion();
            break;
        case 2:
            buscarPorGenero();
            break;
        case 3:
            videosFiltrados();
            break;
        case 4:
            return;
        default:
            std::cout << "Opción inválida" << std::endl;
            break;
        }
    }
}

// Funcion para calcular el promedio de la serie
void Menu::promedioSerie()
{
    string nombreSerie;
    cout << "Ingrese el nombre de la serie: ";
    cin.ignore();
    getline(cin, nombreSerie);

    double promedioSerie = 0;
    int totalEpisodios = 0;
    // Calcular el promedio de calificaciones y mostrar los episodios de la serie
    for (const auto &serie : this->series)
    {
        if (serie->getNombre() == nombreSerie)
        {
            promedioSerie += serie->getCalificacion();

            serie->verVideo();
            cout << endl;

            totalEpisodios++;
        }
    }
    // Si no se encontró la serie, mostrar un mensaje de error
    if (totalEpisodios == 0)
    {
        cout << "No se encontró la serie" << endl;
        return;
    }
    // Calcular y mostrar el promedio de calificaciones de la serie
    cout << "El promedio de la serie " << nombreSerie << " es "
         << promedioSerie / totalEpisodios << endl;
}
