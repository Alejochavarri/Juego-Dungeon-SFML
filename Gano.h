#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
#include "claseMenu.h"
#include "Archivo.h"
#include "archivoManager.h"

class Gano {
private:
	Font font;
	Text Cartel;
	Text Puntos;
	Text Salir;
	Text Nombre;
	Text cartelNombre;
	std::string nombre;
public:
	Gano();

	void draw(RenderWindow& window);
	void drawWin(sf::RenderWindow* window,int P);
	void drawLose(sf::RenderWindow* window, int P);
	void generarArchivo(int P);
	void mostrarArchivo(sf::RenderWindow* window);
	void mostrarUsuario(sf::RenderWindow* window);
	void Ordenar();
	~Gano();
	void ordenarVectores(Archivo* v, int tam);
};
