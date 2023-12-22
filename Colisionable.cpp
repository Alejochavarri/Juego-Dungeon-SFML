#include "Colisionable.h"

bool Colisionable::isColision(Colisionable* obj) const {
    return getBounds().intersects(obj->getBounds());
}
