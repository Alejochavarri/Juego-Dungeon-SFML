#include "Pinchos.h"
Pinchos::Pinchos() {
    _Textura.loadFromFile("Img/Pinchos.png");
    _Sprite.setTexture(_Textura);
}

void Pinchos::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_Sprite, states);
}

void Pinchos::Update(float X, float Y) {
    _Sprite.setPosition(X, Y);
}

sf::FloatRect Pinchos::getBounds() const {
    return _Sprite.getGlobalBounds();
}

void Pinchos::reposicionar() {
    _Sprite.setPosition(900, 700);
}

Pinchos::~Pinchos() {}

sf::Sprite Pinchos::getSprite() {
    return _Sprite;
}
