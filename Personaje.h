#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Iostream>
#include "Colisionable.h"

class Personaje : public Colisionable
{
private:
	sf::Sprite _Sprite;
	sf::Texture Texture;
	float movementSpeed;
	float cooldown;
	float cooldownMax;
	int Puntos;
	int Vida;
	sf::Vector2f currentPos;
	void initVariables();

	sf::SoundBuffer* buffer1, *buffer2, *buffer3, *buffer4;
	sf::Sound* sound1, *sound2, *sound3, *sound4;

	sf::Music* music;

public:
	Personaje();
	virtual ~Personaje();
	
	void Update();
	void updateCooldown();
	const bool canAtack();
	void chocaEnemigo();	
	void Choca();	//Pared
	void chocaEnemigo(sf::Vector2f speedEnemigo);
	void agarrarMoneda();
	int getPuntos();
	int getVida();
	void restarVida(int danio);	//danio del enemigo
	sf::FloatRect getBounds() const override;
	const sf::Vector2f& getPos()const;
	void Move(float dirx, float diry);
	void Render(sf::RenderTarget &target);
	sf::Sprite getSprite();
	void rotar(int x);
	void musicHit();
	void musicCoin();
	void musicDoor();
	void musicSlash();
	void musicBG();
	void musicStop();
};

