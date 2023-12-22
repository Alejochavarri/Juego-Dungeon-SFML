#pragma once
#include <SFML/Graphics.hpp>
#include"Colisionable.h"

class Enemigo : public sf::Drawable, public Colisionable {
protected:
    sf::Sprite _Sprite;
    sf::Texture _Textura;
    sf::Vector2f speed;
    sf::Vector2f _currentPos;
    int vida;
    int damage;


public:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    //void Update(float X, float Y);
    sf::FloatRect getBounds() const override;
    //void choca();
    //void moverse();
    void restarVida(int danio);
    bool tieneVida();
    sf::Vector2f getCurrentPos();
    sf::Vector2f getPosActual();
    sf::Vector2f getSpeed();
    void Render(sf::RenderTarget& target);
};
