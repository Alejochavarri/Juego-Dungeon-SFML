#pragma once
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include "Colisionable.h"

class Moneda : public sf::Drawable, public Colisionable {
private:
    sf::Texture _Textura;
    sf::Sprite _Sprite;
    //sf::SoundBuffer buffer;
    //sf::Sound sound;

public:
    Moneda();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void Update(float X, float Y);
    sf::FloatRect getBounds() const override;
    void reposicionar();
    //void music();
    ~Moneda();
    sf::Sprite getSprite();

};
