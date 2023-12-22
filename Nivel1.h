#pragma once
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include "Personaje.h"
#include "Bloque.h"
#include "Piso.h"
#include "Moneda.h"
#include "Door.h"
#include "Melee.h"
#include "Bullet.h";
#include "Ranged.h"
#include "Pinchos.h"
#include "Golem.h"
#include "Corazon.h"
#include "Antorcha.h"
#include"Gargola.h"

class Nivel1 {
private:
    int Matriz[14][26];
    Bloque* _bloque;
    Piso* _piso;
    Door* _puerta;
    Moneda* _moneda;
    Pinchos* pincho;
    Corazon* corazon;
    Antorcha* torch;
    const int screenX = 1300;
    const int screenY = 700;
    const int numFilas = 14;
    const int numColumnas = 26;

    const int celX = screenX / numColumnas;
    const int celY = screenY / numFilas;
    int contador;
    int posCorazon;

public:
    Nivel1();
    virtual ~Nivel1();
    void cargarMatriz();//bool& monedaA);
    void Dibujar(sf::RenderWindow* window);
    void dibujarPuerta(sf::RenderWindow* window);

    bool chocoPersonaje(Personaje* Player,  Gargola* G);
    bool chocoPuerta(Personaje* Player);
    bool agarroMoneda(Personaje* Player);

    bool chocoBala(std::vector<Bullet*> bullets);
    bool chocoBalaE(std::vector<Bullet*> bullets);

    bool chocoPersonajeMelee(Personaje* Player, Melee* _melee);
    bool chocoPersonajeGolem(Personaje* Player, Golem* _melee);

    bool chocoMelee(Melee* _melee, std::vector<Bullet*> bullets);
    bool chocoRanged(Ranged* _melee, std::vector<Bullet*> bullets);
    bool chocoGolem(Golem* _melee, std::vector<Bullet*> bullets);

    bool chocoBulletPersonaje(Personaje* _melee, std::vector<Bullet*> bullets);

    bool chocoPersonajeRanged(Personaje* Player, Ranged* _melee);
    
    void borrarCorazon();
};