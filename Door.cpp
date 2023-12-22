#include "Door.h"
#include <SFML/Graphics.hpp>

Door::Door(){
    _Textura.loadFromFile("Img/Door.png");
    _Sprite.setTexture(_Textura);
}

void Door::Update(float X, float Y) {
    _Sprite.setPosition(X, Y);
}


void Door::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_Sprite, states);
}


sf::FloatRect Door::getBounds() const {
    return _Sprite.getGlobalBounds();
}

sf::Sprite Door::getSprite() {
    return _Sprite;
}
void Door::Render(sf::RenderTarget& target)
{
    target.draw(_Sprite);
}

