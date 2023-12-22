#include "Ranged.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Ranged::Ranged(sf::Vector2f Pos) {
    _Textura.loadFromFile("Img/Fantasma.png");
    _Sprite.setTexture(_Textura);
    speed = { 1,0 };
    vida = 100;
    damage = 50;
    //_Sprite.setPosition(450,550);
    _Sprite.setPosition(Pos);
    movementSpeed = 4.f;
    contador = 0;
    cooldownMax = 30.f;
    cooldown = cooldownMax;

    buffer = new sf::SoundBuffer();
    sound = new sf::Sound();
}

int Ranged::getDanio() {
    return damage;
}

void Ranged::choca()
{
    speed = { -speed.x ,-speed.y };
    _Sprite.move(speed);
}

void Ranged::perseguir(int x1, int x2, int x3, int x4)
{
    srand(time(nullptr)); // Inicializar el generador de números aleatorios con un valor diferente cada vez (en función del momento en que se ejecuta)

    // Generar un número aleatorio
 // melee abajo
    nuevaPos.x = ((rand() % x1) * 50) + x2;;
    nuevaPos.y = ((rand() % x3) * 50) + x4;


    if (nuevaPos.x > _Sprite.getPosition().x) {
        speed = { 5,0 };
        _Sprite.move(speed);
    }
    if (nuevaPos.x < _Sprite.getPosition().x) {
        speed = { -5,0 };
        _Sprite.move(speed);
    }

    if (nuevaPos.y > _Sprite.getPosition().y) {
        speed = { 0,5 };
        _Sprite.move(speed);
    }

    if (nuevaPos.y < _Sprite.getPosition().y) {
        speed = { 0,-5 };
        _Sprite.move(speed);
    }

}

sf::Vector2f Ranged::getSpeed()
{
    return speed;
}

void Ranged::music()
{
    buffer->loadFromFile("Sound/HitSound.wav");
    sound->setBuffer(*buffer);
    sound->play();
    std::cout << "Sonido" << std::endl;
}

void Ranged::Update() {
    updateCooldown();
}


void Ranged::updateCooldown()
{
    if (cooldown < cooldownMax) {
        cooldown += 0.5f;
    }

}

const bool Ranged::canAtack()
{
    if (cooldown >= cooldownMax) {
        cooldown = 0.f;
        return true;
    }
    return false;
}

sf::Vector2f Ranged::Seguir(sf::Vector2f playerPos)
{
    nuevaPos.x = playerPos.x;
    nuevaPos.y = playerPos.y;
    sf::Vector2f Aux;

    if (nuevaPos.x > _Sprite.getPosition().x) {
        Aux = { 1,0 };
        std::cout << playerPos.x << std::endl;
        std::cout << playerPos.y << std::endl;
        return Aux;
    }
    if (nuevaPos.x < _Sprite.getPosition().x) {
        Aux = { -1,0 };
        std::cout << playerPos.x << std::endl;
        std::cout << playerPos.y << std::endl;
        return Aux;
    }

    if (nuevaPos.y > _Sprite.getPosition().y) {
        Aux = { 0,1 };
        std::cout << playerPos.x << std::endl;
        std::cout << playerPos.y << std::endl;
        return Aux;
    }

    if (nuevaPos.y < _Sprite.getPosition().y) {
        Aux = { 0,-1 };
        std::cout << playerPos.x << std::endl;
        std::cout << playerPos.y << std::endl;
        return Aux;
    }


}

const sf::Vector2f& Ranged::getPos()const
{
    return _Sprite.getPosition();
}

sf::Sprite Ranged::getSprite() {
    return _Sprite;
}