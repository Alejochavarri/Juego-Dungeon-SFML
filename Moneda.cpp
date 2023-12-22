#include "Moneda.h"

Moneda::Moneda(){
    _Textura.loadFromFile("Img/Coin.png");
    _Sprite.setTexture(_Textura);
    //buffer.loadFromFile("Sound/Coin.wav");
    //sound.setBuffer(buffer);
}

void Moneda::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_Sprite, states);
}

void Moneda::Update(float X, float Y) {
    _Sprite.setPosition(X, Y);
}

sf::FloatRect Moneda::getBounds() const {
    return _Sprite.getGlobalBounds();
}

void Moneda::reposicionar() {
    _Sprite.setPosition(900, 700);
}

//void Moneda::music(){
//    sound.play();
//}

Moneda::~Moneda() {

}

sf::Sprite Moneda::getSprite() {
    return _Sprite;
}
