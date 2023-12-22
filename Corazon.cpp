#include "Corazon.h"
Corazon::Corazon() {
    _Textura.loadFromFile("Img/hart.png");
    _Sprite.setTexture(_Textura);
}

void Corazon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_Sprite, states);
}

void Corazon::Update(float X, float Y) {
    _Sprite.setPosition(X, Y);
}

sf::FloatRect Corazon::getBounds() const {
    return _Sprite.getGlobalBounds();
}

void Corazon::reposicionar() {
    _Sprite.setPosition(900, 700);
}

Corazon::~Corazon() {}

sf::Sprite Corazon::getSprite() {
    return _Sprite;
}
