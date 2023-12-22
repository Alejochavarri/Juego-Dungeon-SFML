#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdio.h>
class Archivo
{
private :
	char Nombre[15];
	int Puntos;

public:
	const char* getNombre(); 
	void setNombre(const char* palabra); 
	void setPuntos(int P); 
	int getPuntos(); 
	void mostrarRegistro();
};

