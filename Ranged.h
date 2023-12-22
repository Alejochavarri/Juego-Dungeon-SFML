#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include "Enemigo.h"

class Ranged : public Enemigo {
private:
    float movementSpeed;
    sf::Vector2f nuevaPos;
    int contador;
    float cooldown;
    float cooldownMax;
    sf::SoundBuffer* buffer;
    sf::Sound* sound;

public:
    Ranged(sf::Vector2f Pos);
    int getDanio();
    void Update();
    void choca();
    void updateCooldown();
    const bool canAtack();
    sf::Vector2f Seguir(sf::Vector2f playerPos);
    void perseguir(int x1, int x2, int x3, int x4);
    sf::Vector2f getSpeed();
    void music();
    sf::Sprite getSprite();
    const sf::Vector2f& getPos()const;
};

