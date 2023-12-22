#include "Personaje.h"

void Personaje::initVariables()
{
	movementSpeed = 5.f;
	cooldownMax = 30.f;
	cooldown = cooldownMax;
	_Sprite.setPosition(76, 51);
	_Sprite.setOrigin(_Sprite.getGlobalBounds().width / 2, 0);
	currentPos = _Sprite.getPosition();
	Vida = 150;

	buffer1 = new sf::SoundBuffer();
	sound1 = new sf::Sound();
	buffer2 = new sf::SoundBuffer();
	sound2 = new sf::Sound();
	buffer3 = new sf::SoundBuffer();
	sound3 = new sf::Sound();
	buffer4 = new sf::SoundBuffer();
	sound4 = new sf::Sound();
	music = new sf::Music();
}

Personaje::Personaje()
{
	Texture.loadFromFile("Img/warrior.png");
	_Sprite.setTexture(Texture);
	initVariables();
}

Personaje::~Personaje()
{
}

void Personaje::Update()
{
	updateCooldown();
}

void Personaje::updateCooldown()
{
	if (cooldown < cooldownMax) {
		cooldown += 0.5f;
	}
	
}

const bool Personaje::canAtack()
{
	if (cooldown >= cooldownMax) {
		cooldown = 0.f;
		return true;
	}
	return false;
}

const sf::Vector2f& Personaje::getPos()const
{
	return _Sprite.getPosition();
}

void Personaje::Move(float dirx, float diry)
{
	//currentPos.x = _Sprite.getPosition().x-1*dirx;
	//currentPos.y = _Sprite.getPosition().y-1 * diry;
	currentPos = _Sprite.getPosition();
	_Sprite.move(movementSpeed *dirx, movementSpeed *diry);
}

void Personaje::Render(sf::RenderTarget& target)
{
	target.draw(_Sprite);
}

sf::Sprite Personaje::getSprite()
{
	return _Sprite;
}

void Personaje::rotar(int x) 
{
	//_Sprite.setOrigin(_Sprite.getGlobalBounds().width/2, 0);
	_Sprite.setScale(x, 1);
	
}

void Personaje::musicHit()
{
	buffer1->loadFromFile("Sound/HitSound.wav");
	sound1->setBuffer(*buffer1);
	music->setVolume(50.f);
	sound1->play();
}

void Personaje::musicCoin()
{
	buffer2->loadFromFile("Sound/Coin.wav");
	sound2->setBuffer(*buffer2);
	sound2->play();
}

void Personaje::musicDoor()
{
	buffer3->loadFromFile("Sound/Level++.wav");
	sound3->setBuffer(*buffer3);
	sound3->play();
}

void Personaje::musicSlash()
{
	buffer4->loadFromFile("Sound/Fireball.wav");
	sound4->setBuffer(*buffer4);
	sound4->setVolume(10.f);
	sound4->play();
}

void Personaje::musicBG()
{
	if (!music->openFromFile("Sound/Background.wav")) {
		std::cout << "1" << std::endl;
	}
	music->setVolume(5.f);
	music->play();
}

void Personaje::musicStop()
{
	music->stop();
}

// Nuevos 

void Personaje::chocaEnemigo() {
	movementSpeed = movementSpeed * -10;
}

void Personaje::Choca() {
	_Sprite.setPosition(currentPos);
}

void Personaje::chocaEnemigo(sf::Vector2f speedEnemigo)
{
	//_Sprite.move(movementSpeed * (speedEnemigo.x * 5), movementSpeed * (speedEnemigo.y * 5));
	_Sprite.setPosition(76, 51);
}

void Personaje::agarrarMoneda()
{
	Puntos++;
}

int Personaje::getPuntos()
{
	return Puntos;
}

int Personaje::getVida()
{
	return Vida;
}

void Personaje::restarVida(int danio)
{
	Vida = Vida - danio;
}

sf::FloatRect Personaje::getBounds() const {
	return _Sprite.getGlobalBounds();
}


