#include "Melee.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Melee::Melee(sf::Vector2f Pos) {
    _Textura.loadFromFile("Img/Enemigos/Esqueleto.png");
    _Sprite.setTexture(_Textura);
    speed = { 1,0 };
    vida = 100;
    damage = 50;
    //_Sprite.setPosition(450,550);
    _Sprite.setPosition(Pos);
    movementSpeed = 4.f;
    contador = 0;
}

int Melee::getDanio(){
    return damage;
}

void Melee::choca()
{
    speed = { -speed.x ,-speed.y };
    _Sprite.move(speed);
}

void Melee::perseguir(int x1, int x2, int y1, int y2)
{
    srand(time(nullptr)); // Inicializar el generador de números aleatorios con un valor diferente cada vez (en función del momento en que se ejecuta)

    // Generar un número aleatorio
 // melee abajo
        nuevaPos.x = ((rand() % x1) * 50) + x2;
        nuevaPos.y = ((rand() % y1) * 50) + y2;
        

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

sf::Vector2f Melee::getSpeed()
{
    return speed;
}

void Melee::Update() {


    if ( ( (_Sprite.getPosition().x > (_currentPos.x + 50)) || (_Sprite.getPosition().y > (_currentPos.y + 50) ) ) ||
        ( (_Sprite.getPosition().x < (_currentPos.x - 50)) || (_Sprite.getPosition().y < (_currentPos.y - 50) ) ) ) {
        choca();
        
    }//Arriba der
    else {
        if ((_Sprite.getPosition().x > (_currentPos.x + 50)) && (_Sprite.getPosition().y < (_currentPos.y + 50))) {
            choca();
        };//Punta derecha arr

        if ((_Sprite.getPosition().x > (_currentPos.x + 50)) && (_Sprite.getPosition().y < (_currentPos.y - 50))) {
            choca();
            speed.y = -speed.y;
        };//Punta derecha abajo

        if ((_Sprite.getPosition().x < (_currentPos.x - 50)) && (_Sprite.getPosition().y > (_currentPos.y - 50))) {
            choca();
            speed.x = -speed.x;
        };//punta izq abajo

        if ((_Sprite.getPosition().x > (_currentPos.x + 50)) && (_Sprite.getPosition().y < (_currentPos.y - 50))) {
            choca();
            speed.y = -speed.y;
        };//punta izq arriba
    }

}


sf::Sprite Melee::getSprite() {
    return _Sprite;
}
