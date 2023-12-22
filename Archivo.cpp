#include "Archivo.h"

const char* Archivo::getNombre()
{
	return Nombre;
}

void Archivo::setNombre(const char* palabra)
{
	strcpy_s(Nombre, palabra);
}

void Archivo::setPuntos(int P)
{
	Puntos = P;
}

int Archivo::getPuntos()
{
	return Puntos;
}

void Archivo::mostrarRegistro()
{
	std::cout << Nombre<<std::endl;
	std::cout << Puntos << std::endl;
}
