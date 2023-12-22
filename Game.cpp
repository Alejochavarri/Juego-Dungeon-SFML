#include "Game.h"
#include <SFML/Audio.hpp>

void Game::initPlayer()
{
	Player = new Personaje();
	Puntos = 0;
}

void Game::initMelee()
{
	_melee1 = new Melee({ 450,550 });
	golem = new Golem({ 950,150 }); 
	ranged = new Ranged({ 450,125 });
	gargola = new Gargola({1250,350});
	meleeExist1 = true;
	meleeExist2 = true;
	meleeExist3 = true;
	activadorMelee1 = false;
	activadorMelee2 = false;
	activadorMelee3 = false;
}

void Game::initTextures()
{
	texturesP["BULLET"] = new sf::Texture;
	texturesP["BULLET"]->loadFromFile("Img/fireball.png");
}

void Game::initNivel()
{
	Niv1 = new Nivel1();
	Niv1->cargarMatriz();
	clock = new Clock();
	tiempo = new Time();
	TiempoMax = 120;
}

void Game::initFont()
{
	font.loadFromFile("Fonts/8-bit-hud.ttf");
	textVida.setFont(font);
	textMoneda.setFont(font);
	textPuntos.setFont(font);
	Cronometro.setFont(font);

	textVida.setString("Vida : " + to_string(Player->getVida()));
	textVida.setCharacterSize(20);
	textVida.setPosition(1060, 15);

	textMoneda.setString( to_string(contador) + " X ");
	textMoneda.setCharacterSize(15);
	textMoneda.setPosition(1210, 670);

	textPuntos.setString("Puntos : " + to_string(Puntos));
	textPuntos.setCharacterSize(15);
	textPuntos.setPosition(25, 670);

	Cronometro.setString("Tiempo : " + to_string(TiempoMax));
	Cronometro.setCharacterSize(15);
	Cronometro.setPosition(25, 15);
}

Game::Game(sf::RenderWindow* w)
{
	initPlayer();
	initMelee();
	initTextures();
	initNivel();
	initFont();
	window = w;
	contador = 0;
	cantVidas = 3;
	//Player->musicBG();
}

Game::~Game()
{
	//delete window;
	delete Player;
	delete Niv1;
	delete _melee1;
	delete golem;
	delete ranged;
	delete gargola;
	//delete textures
	for (auto &i : texturesP)
	{
		i.second;
	}
	//delete bullets
	for (auto* i : bulletsP)
	{
		i;
	}
	for (auto* i : bulletsE)
	{
		i;
	}
	for (auto* i : bulletsG)
	{
		i;
	}
}

void Game::updatePollEvents()
{
	sf::Event e;
	while (window->pollEvent(e)) {
		if (e.Event::type == sf::Event::Closed) {
			window->close();
		}
	}
}

void Game::updateInput()
{
	// Personaje Move
	bool izquierda = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool derecha = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	bool arriba = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	bool abajo = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	bool disparoDerecha = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Player->canAtack();
	bool disparoIzquierda = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Player->canAtack();

	// controles
	if (izquierda && !derecha &&!arriba &&!abajo) {
		Player->rotar(-1);
		Player->Move(-1.f, 0.f);
		
	}
	if (derecha && !izquierda && !arriba && !abajo) {
		Player->rotar(1);
		Player->Move(1.f, 0.f);
		
	}
	if (arriba && !derecha && !izquierda && !abajo) {
		Player->Move(0.f, -1.f);
	}
	if (abajo && !derecha && !arriba && !izquierda) {
		Player->Move(0.f, 1.f);
	}

	// disparos
	if (disparoDerecha)  {
		Player->musicSlash();
		bulletsP.push_back(new Bullet(texturesP["BULLET"], Player->getPos().x, Player->getPos().y, 1.f, 0.f, 7.f));
	}
	if (disparoIzquierda) {
		Player->musicSlash();
		bulletsP.push_back(new Bullet(texturesP["BULLET"], Player->getPos().x, Player->getPos().y, -1.f, 0.f, 7.f));
	}

	//choque personaje con pared
	if (Niv1->chocoPersonaje(Player, gargola)) {
		Player->Choca();
	}
	//activador melee
	if (((Player->getPos().x > 400) && (Player->getPos().x < 550)) && ((Player->getPos().y > 350) && (Player->getPos().y < 450))) {
		activadorMelee1 = true;
		activadorMelee2 = false;
		activadorMelee3 = false;

	}
	if (activadorMelee1) {
		_melee1->perseguir(10, 250, 4, 450);
	}
	//activador golem 
	if  (((Player->getPos().x > 1150) && (Player->getPos().x < 1250)) && ((Player->getPos().y > 250) && (Player->getPos().y < 300))) {
		activadorMelee1 = false;
		activadorMelee2 = true;
		activadorMelee3 = false;
	}
	if (activadorMelee2) {
		golem->perseguir(8, 825, 3, 50);
	}
	//activador ranged
	if (((Player->getPos().x > 250) && (Player->getPos().x < 350)) && ((Player->getPos().y > 250) && (Player->getPos().y < 300))) {
		activadorMelee1 = false;
		activadorMelee2 = false;
		activadorMelee3 = true;
	}
	if (activadorMelee3 && ranged->canAtack() && meleeExist3) {//hacer ranged can atak y sacar clase 2
		//bulletsE.push_back(new Bullet(texturesP["BULLET"], _melee3->getPos().x, _melee3->getPos().y, (_melee3->Seguir(Player->getPos())).x, (_melee3->Seguir(Player->getPos())).y, 7.f));
		bulletsE.push_back(new Bullet(texturesP["BULLET"], ranged->getPos().x + 10, ranged->getPos().y + 10, 0.f, 1.f, 3.f));
		bulletsE.push_back(new Bullet(texturesP["BULLET"], ranged->getPos().x + 10, ranged->getPos().y + 10, 1.f, 0.f, 3.f));
		bulletsE.push_back(new Bullet(texturesP["BULLET"], ranged->getPos().x + 10, ranged->getPos().y + 10, 0.f, -1.f, 3.f));
		bulletsE.push_back(new Bullet(texturesP["BULLET"], ranged->getPos().x + 10, ranged->getPos().y + 10, -1.f, 0.f, 3.f));
	}

	if (gargola->canAtack()) {
		bulletsG.push_back(new Bullet(texturesP["BULLET"], gargola->getPos().x-30, gargola->getPos().y+10, -1.f, 0.f, 3.f));
	}

	// choques con melees
	if (Niv1->chocoPersonajeMelee(Player,_melee1) && meleeExist1) {
		Player->chocaEnemigo(_melee1->getSpeed());
		Player->restarVida(_melee1->getDanio());
		Puntos -= 100;
		Niv1->borrarCorazon();
		cantVidas--;
		Player->musicHit();
	}
	if (Niv1->chocoPersonajeGolem(Player, golem) && meleeExist2) {
		Player->chocaEnemigo(golem->getSpeed());
		Player->restarVida(golem->getDanio());
		Puntos -= 100;
		Niv1->borrarCorazon();
		cantVidas--;
		Player->musicHit();
	}
	if (Niv1->chocoPersonajeRanged(Player, ranged) && meleeExist3) {
		Player->chocaEnemigo(ranged->getSpeed());
		Player->restarVida(ranged->getDanio());
		Puntos -= 100;
		Niv1->borrarCorazon();
		cantVidas--;
		Player->musicHit();
	}

	// choque con la puerta
	if (Niv1->chocoPuerta(Player)) {
		Player->musicDoor();
		Puntos += TiempoMax * 10;
		Game2 game2(window,Puntos,cantVidas);
		game2.run();
	}
	// player murio
	if (Player->getVida() <= 0) {
		Gano G;
		G.drawLose(window, Puntos);
	}
	// choque con monedas
	if (Niv1->agarroMoneda(Player)) {
		contador++;
		Puntos += 100;
		Player->musicCoin();
	}
	//Actualizacion de los textos
	textVida.setString("VIDA : " + to_string(Player->getVida()));
	textMoneda.setString(to_string(contador) + " X ");
	textPuntos.setString("PUNTOS : " + to_string(Puntos));

	//time
	*tiempo = clock->getElapsedTime();
	if (tiempo->asSeconds() >= 1) {
		clock->restart();
		TiempoMax--;
		Cronometro.setString("Tiempo : " + to_string(TiempoMax));
	}
	if (TiempoMax <= 0) {
		Gano G;
		G.drawLose(window,Puntos);
		//G.drawWin(window,Puntos);

	}
}

void Game::updateBulletP()
{	
	unsigned counter = 0;
	for (auto* bullet : bulletsP)
	{
		bullet->Update();

		//choques melee con bala
		if ((bullet->getPosition().x > 1300) || (bullet->getPosition().x < 0) || (bullet->getPosition().y > 700) || (bullet->getPosition().x < 0 ) || 
			Niv1->chocoBala(bulletsP) || (meleeExist1 && Niv1->chocoMelee(_melee1, bulletsP)) || (meleeExist2 && Niv1->chocoGolem(golem, bulletsP)) || (meleeExist3 && Niv1->chocoRanged(ranged, bulletsP)) ) {
			// descuenta vida melee1
			if (Niv1->chocoMelee(_melee1, bulletsP)) {
				_melee1->restarVida(danioProyectil);
				Puntos += 50;
				//Player->musicSlash();
				if (!_melee1->tieneVida()) {
					meleeExist1 = false;
					Puntos += 300;
				}
			}
			// descuenta vida golem
			if (Niv1->chocoGolem(golem, bulletsP)) {
				golem->restarVida(danioProyectil);
				Puntos += 50;
				//Player->musicSlash();
				if (!golem->tieneVida()) {
					meleeExist2 = false;
					Puntos += 300;
				}
			}
			// descuenta vida melee3
			if (Niv1->chocoRanged(ranged, bulletsP)) {
				ranged->restarVida(danioProyectil);
				Puntos += 50;
				//Player->musicSlash();
				if (!ranged->tieneVida()) {
					meleeExist3 = false;
					Puntos += 300;
				}
			}
			//borra las balas con colision
			delete bulletsP.at(counter);
			bulletsP.erase(bulletsP.begin() + counter);
			--counter;
		}
		++counter;
	}	
}

void Game::updateBulletE()
{
	unsigned counter = 0;
	for (auto* BulletE : bulletsE)
	{
		BulletE->Update();

		//choques melee con bala
		if ((BulletE->getPosition().x > 1300) || (BulletE->getPosition().x < 0) || (BulletE->getPosition().y > 700) ||
			(BulletE->getPosition().x < 0) || Niv1->chocoBalaE(bulletsE) || ( Niv1->chocoBulletPersonaje(Player, bulletsE))) {
			// descuenta vida Personaje
			if (Niv1->chocoBulletPersonaje(Player, bulletsE)) {
				Player->chocaEnemigo(ranged->getSpeed()); // Respawn al personaje
				Player->restarVida(ranged->getDanio());
				Puntos -= 100;
				Player->musicHit();
				Niv1->borrarCorazon();
				cantVidas--;
				if (Player->getVida() <= 0) {
					Gano G;
					G.drawLose(window, Puntos);
				}

			}
			
			//borra las balas con colision
			delete bulletsE.at(counter);
			bulletsE.erase(bulletsE.begin() + counter);
			--counter;
		}
		++counter;
	}

}

void Game::updateBulletG()
{
	unsigned counter = 0;
	for (auto* BulletsG : bulletsG)
	{
		BulletsG->Update();

		//choques melee con bala
		if ((BulletsG->getPosition().x > 1300) || (BulletsG->getPosition().x < 0) || (BulletsG->getPosition().y > 700) ||
			(BulletsG->getPosition().x < 0) || Niv1->chocoBalaE(bulletsG) || (Niv1->chocoBulletPersonaje(Player, bulletsG))) {
			// descuenta vida Personaje
			if (Niv1->chocoBulletPersonaje(Player, bulletsG)) {
				Player->chocaEnemigo(ranged->getSpeed()); // Respawn al personaje
				Player->restarVida(ranged->getDanio());
				Puntos -= 100;
				Player->musicHit();
				Niv1->borrarCorazon();
				cantVidas--;
				if (Player->getVida() <= 0) {
					Gano G;
					G.drawLose(window, Puntos );
				}
			}

			//borra las balas con colision
			delete bulletsG.at(counter);
			bulletsG.erase(bulletsG.begin() + counter);
			--counter;
		}
		++counter;
	}
}

void Game::run()
{
	while (window->isOpen()) {
		Update();
		Render();
	}
}

void Game::Update()
{
	updatePollEvents();
	updateInput();
	Player->Update();
	ranged->Update();
	gargola->Update();
	updateBulletP();
	updateBulletE();
	updateBulletG();
}

void Game::Render()
{
	window->clear();
	
	Niv1->Dibujar(window);

	Niv1->dibujarPuerta(window);
	
	Player->Render(*window);
	gargola->Render(*window);
	//dibujo melees
	if (meleeExist1) {
		_melee1->Render(*window);
	}	
	if (meleeExist2) {
		golem->Render(*window);
	}
	if (meleeExist3) {
		ranged->Render(*window);
	}

	//window->draw(textVida);

	window->draw(textMoneda);

	window->draw(textPuntos);

	window->draw(Cronometro);

	for (auto* bullet : bulletsP)
	{
		bullet->Render(*window);
	}

	for (auto* BulletE : bulletsE)
	{
		BulletE->Render(*window);
	}

	for (auto* BulletG : bulletsG)
	{
		BulletG->Render(*window);
	}

	window->display();
}

void Game::tocoBorde(int b)
{
	delete bulletsP.at(b);
	bulletsP.erase(bulletsP.begin() + (b-1));

	delete bulletsE.at(b);
	bulletsE.erase(bulletsE.begin() + (b - 1));
	
}
