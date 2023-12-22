#include "Bloque.h"

Bloque::Bloque() {
    _Textura.loadFromFile("Img/Bloque.png");
    _Sprite.setTexture(_Textura);
}

void Bloque::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_Sprite, states);
}

void Bloque::Update(float X, float Y) {
    _Sprite.setPosition(X, Y);
}

sf::FloatRect Bloque::getBounds() const {
    return _Sprite.getGlobalBounds();
}

void Bloque::reposicionar() {
    _Sprite.setPosition(900, 700);
}

Bloque::~Bloque() {}

sf::Sprite Bloque::getSprite() {
    return _Sprite;
}
