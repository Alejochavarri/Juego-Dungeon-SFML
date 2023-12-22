#include "Enemigo.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_Sprite, states);
}

sf::FloatRect Enemigo::getBounds() const {
    return _Sprite.getGlobalBounds();
}

/*void Enemigo::choca() {
    _Sprite.setPosition(_currentPos);
}*/

void Enemigo::restarVida(int danio) {
    vida -= danio;
}


bool Enemigo::tieneVida()
{
    if (vida <= 0) {
        return false;
    }
    return true;
}

sf::Vector2f Enemigo::getCurrentPos() {
    return _currentPos;
}

sf::Vector2f Enemigo::getPosActual() {
    return _Sprite.getPosition();
}

sf::Vector2f Enemigo::getSpeed() {
    return speed;
}

void Enemigo::Render(sf::RenderTarget& target)
{
    target.draw(_Sprite);
}