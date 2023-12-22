#include "Bullet.h"



Bullet::Bullet()
{
	
}

Bullet::Bullet(sf::Texture *texture, float posX, float posY, float dirX, float dirY, float Speed)
{
	_Sprite.setTexture(*texture);
	Direction.x = dirX;
	Direction.y = dirY;
	_Sprite.setPosition(posX, posY);
	movimentSpeed = Speed;
	danio = 50;
}

Bullet::~Bullet()
{
}

const sf::FloatRect Bullet::getBound() const
{
	return _Sprite.getGlobalBounds();
}

void Bullet::Update()
{
	_Sprite.move(movimentSpeed * Direction);
}

void Bullet::Render(sf::RenderTarget& target)
{
	target.draw(_Sprite);
}

sf::Vector2f Bullet::getPosition()
{
	return _Sprite.getPosition();
}

int Bullet::getDanio()
{
	return danio;
}

sf::FloatRect Bullet::getBounds() const {
	return _Sprite.getGlobalBounds();
}

