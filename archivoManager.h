#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <stdio.h>
#include "Archivo.h"
class archivoManager
{
private:
    
public:
    Archivo leerRegistro(int pos);
    int contarRegistros();
    Archivo registroVacio();
};

