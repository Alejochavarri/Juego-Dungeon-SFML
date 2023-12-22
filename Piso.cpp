#include "Piso.h"

Piso::Piso() {
    _Textura.loadFromFile("Img/PisoTeo.png");
    _Sprite.setTexture(_Textura);
}

void Piso::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_Sprite, states);
}

void Piso::Update(float X, float Y) {
    _Sprite.setPosition(X, Y);
}

sf::FloatRect Piso::getBounds() const {
    return _Sprite.getGlobalBounds();
}

void Piso::reposicionar() {
    _Sprite.setPosition(900, 700);
}

Piso::~Piso() {}

sf::Sprite Piso::getSprite()
{
    return _Sprite;
}
