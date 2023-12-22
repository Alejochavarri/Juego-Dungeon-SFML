#pragma once

#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Pinchos : public sf::Drawable, public Colisionable {
private:
    sf::Texture _Textura;
    sf::Sprite _Sprite;

public:
    Pinchos();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void Update(float X, float Y);
    sf::FloatRect getBounds() const override;
    void reposicionar();
    ~Pinchos();
    sf::Sprite getSprite();

};
