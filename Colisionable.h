#pragma once
#include <SFML/Graphics.hpp>

class Colisionable {
private:
    virtual sf::FloatRect getBounds() const = 0;
    //bool isColision(Colisionable& col) const;

public:
    bool isColision(Colisionable* col) const;

};
