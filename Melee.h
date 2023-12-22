#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Enemigo.h"

class Melee : public Enemigo {
private:
    float movementSpeed;
    sf::Vector2f nuevaPos;
    int contador;

public:
    Melee(sf::Vector2f Pos);
    int getDanio();
    void Update();
    void choca();
    void perseguir(int x1, int x2, int y1, int y2);
    sf::Vector2f getSpeed();
    sf::Sprite getSprite();
};
