#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.h"
class Bullet : public Colisionable
{
private:
	sf::Sprite _Sprite;
	sf::Texture Texture;
	sf::Vector2f Direction;
	float movimentSpeed;
	int danio;
public:
	Bullet();
	Bullet(sf::Texture *texture,float posX, float posY, float dirX, float dirY, float Speed);
	virtual ~Bullet();

	const sf::FloatRect getBound() const;
	sf::FloatRect getBounds() const override;
	void Update();
	//void Move(float dirx, float diry);
	void Render(sf::RenderTarget& target);
	sf::Vector2f getPosition();
	int getDanio();
	
};

