#include "Antorcha.h"
Antorcha::Antorcha() {
    _Textura.loadFromFile("Img/torch.png");
    _Sprite.setTexture(_Textura);
}

void Antorcha::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_Sprite, states);
}

void Antorcha::Update(float X, float Y) {
    _Sprite.setPosition(X, Y);
}

sf::FloatRect Antorcha::getBounds() const {
    return _Sprite.getGlobalBounds();
}

void Antorcha::reposicionar() {
    _Sprite.setPosition(900, 700);
}

Antorcha::~Antorcha() {}

sf::Sprite Antorcha::getSprite() {
    return _Sprite;
}
