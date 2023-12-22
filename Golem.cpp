#include "Golem.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Golem::Golem(sf::Vector2f Pos) {
    _Textura.loadFromFile("Img/golem.png");
    _Sprite.setTexture(_Textura);
    speed = { 1,0 };
    vida = 200;
    damage = 50;
    //_Sprite.setPosition(450,550);
    _Sprite.setPosition(Pos);
    movementSpeed = 2.f;
    contador = 0;
}

int Golem::getDanio() {
    return damage;
}

void Golem::choca()
{
    speed = { -speed.x ,-speed.y };
    _Sprite.move(speed);
}

void Golem::perseguir(int x1, int x2, int y1, int y2)
{
    srand(time(nullptr)); // Inicializar el generador de números aleatorios con un valor diferente cada vez (en función del momento en que se ejecuta)

    // Generar un número aleatorio
 // melee abajo
    nuevaPos.x = ((rand() % x1) * 50) + x2;
    nuevaPos.y = ((rand() % y1) * 50) + y2;

    if (nuevaPos.x > _Sprite.getPosition().x) {
        speed = { 2,0 };
        _Sprite.move(speed);
    }
    if (nuevaPos.x < _Sprite.getPosition().x) {
        speed = { -2,0 };
        _Sprite.move(speed);
    }

    if (nuevaPos.y > _Sprite.getPosition().y) {
        speed = { 0,2 };
        _Sprite.move(speed);
    }

    if (nuevaPos.y < _Sprite.getPosition().y) {
        speed = { 0,-2 };
        _Sprite.move(speed);
    }

}

sf::Vector2f Golem::getSpeed()
{
    return speed;
}

void Golem::Update() {


    
}


sf::Sprite Golem::getSprite() {
    return _Sprite;
}
