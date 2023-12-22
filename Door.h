#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Door : public sf::Drawable, public Colisionable{
private:
    sf::Sprite _Sprite;
    sf::Texture _Textura;

public:
    Door();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void Update(float X, float Y);
    sf::FloatRect getBounds() const override;
    sf::Sprite getSprite();
    void Render(sf::RenderTarget& target);

};
