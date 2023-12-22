#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Enemigo.h"

class Golem : public Enemigo {
private:
    float movementSpeed;
    sf::Vector2f nuevaPos;
    int contador;
    float cooldown;
    float cooldownMax;

public:
    Golem(sf::Vector2f Pos);
    int getDanio();
    void Update();
    void choca();
    sf::Vector2f Seguir(sf::Vector2f playerPos);
    void perseguir(int x1, int x2, int y1, int y2);
    sf::Vector2f getSpeed();
    sf::Sprite getSprite();

};

