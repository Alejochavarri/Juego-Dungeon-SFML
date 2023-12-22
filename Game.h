#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Personaje.h"
#include "Bullet.h";
#include <map>
#include "Nivel1.h"
#include "claseMenu.h"
#include "Melee.h"
#include "Gano.h"
#include "Ranged.h"
#include "Golem.h"
#include "Gargola.h"

class Game
{
private:
	sf::RenderWindow* window;
	// resourses
	std::map < std::string, sf::Texture*>  texturesP;
	std::vector<Bullet*> bulletsP;
	std::vector<Bullet*> bulletsE; 
	std::vector<Bullet*> bulletsG;
	//inits
	void initTextures();
	Personaje* Player;
	void initPlayer();
	Nivel1* Niv1;
	void initNivel();
	Melee* _melee1;
	Golem* golem;
	Ranged* ranged;
	Gargola* gargola;
	void initMelee();
	bool meleeExist1;
	bool meleeExist2;
	bool meleeExist3;
	sf::Font font;
	sf::Text textVida;
	sf::Text textMoneda;
	sf::Text textPuntos;
	sf::Text Cronometro;
	void initFont();
	const int danioProyectil = 25;
	int contador;
	bool activadorMelee1;
	bool activadorMelee2;
	bool activadorMelee3;
	int Puntos;
	sf::Clock* clock;
	sf::Time* tiempo;
	int TiempoMax;
	int cantVidas;

public:
	Game(sf::RenderWindow* w);
	virtual ~Game();
	void updatePollEvents();
	void updateInput();
	void updateBulletP();
	void updateBulletE();
	void updateBulletG();
	void run();
	void Update();
	void Render();
	void tocoBorde(int b);

};

