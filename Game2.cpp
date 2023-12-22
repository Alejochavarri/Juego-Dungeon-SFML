#include "Game2.h"
#include <SFML/Audio.hpp>

void Game2::initPlayer()
{
	Player = new Personaje();
}

void Game2::initMelee()
{
	_melee1 = new Melee({ 750,250 });
	golem = new Golem({ 1000,200 });
	ranged = new Ranged({ 750,525 });
	gargola = new Gargola({ 1250,300 });
	gargola2 = new Gargola({ 350,250 });
	gargola3 = new Gargola({ 400,400 });
	meleeExist1 = true;
	meleeExist2 = true;
	meleeExist3 = true;
	activadorMelee1 = false;
	activadorMelee2 = false;
	activadorMelee3 = false;
}

void Game2::initTextures()
{
	texturesP["BULLET"] = new sf::Texture;
	texturesP["BULLET"]->loadFromFile("Img/fireball.png");
	//texturesE["BULLET"] = new sf::Texture;
	//texturesE["BULLET"]->loadFromFile("Img/fireball.png");
}

void Game2::initNivel()
{
	Niv2 = new Nivel2();
	Niv2->cargarMatriz();
	clock = new Clock();
	tiempo = new Time();
	TiempoMax = 180;
}

void Game2::initFont()
{
	font.loadFromFile("Fonts/8-bit-hud.ttf");
	textVida.setFont(font);
	textMoneda.setFont(font);
	textPuntos.setFont(font);
	Cronometro.setFont(font);

	textVida.setString("Vida : " + to_string(Player->getVida()));
	textVida.setCharacterSize(20);
	textVida.setPosition(1060, 15);

	textMoneda.setString(to_string(contador) + " X ");
	textMoneda.setCharacterSize(15);
	textMoneda.setPosition(1210, 670);

	textPuntos.setString("Puntos : " + to_string(Puntos));
	textPuntos.setCharacterSize(15);
	textPuntos.setPosition(25, 670);

	Cronometro.setString("Tiempo : " + to_string(TiempoMax));
	Cronometro.setCharacterSize(15);
	Cronometro.setPosition(25, 15);
}

Game2::Game2(sf::RenderWindow* w, int P, int V)
{
	initPlayer();
	initMelee();
	initTextures();
	initNivel();
	initFont();
	window = w;
	contador = 0;
	Puntos = P;
	if (V < 3) {
		V++;
	}
	for (int i = V; i<3; i++) {
		Player->restarVida(ranged->getDanio());
		Niv2->borrarCorazon();
	}
	
}

Game2::~Game2()
{
	//delete window;
	delete Player;
	delete Niv2;
	delete _melee1;
	delete golem;
	delete ranged;
	delete gargola;
	//delete textures
	for (auto& i : texturesP)
	{
		i.second;
	}
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

void Game2::updatePollEvents()
{
	sf::Event e;
	while (window->pollEvent(e)) {
		if (e.Event::type == sf::Event::Closed) {
			window->close();
		}
	}
}

void Game2::updateInput()
{
	// Personaje Move
	bool izquierda = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool derecha = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	bool arriba = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	bool abajo = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
	bool disparoDerecha = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && Player->canAtack();
	bool disparoIzquierda = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && Player->canAtack();

	// controles
	if (izquierda && !derecha && !arriba && !abajo) {
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
	if (disparoDerecha) {
		Player->musicSlash();
		bulletsP.push_back(new Bullet(texturesP["BULLET"], Player->getPos().x, Player->getPos().y, 1.f, 0.f, 7.f));
	}
	if (disparoIzquierda) {
		Player->musicSlash();
		bulletsP.push_back(new Bullet(texturesP["BULLET"], Player->getPos().x, Player->getPos().y, -1.f, 0.f, 7.f));
	}

	//choque personaje con pared
	if (Niv2->chocoPersonaje(Player)) {
		Player->Choca();
	}
	//activador melee
	if (((Player->getPos().x > 350) && (Player->getPos().x < 500)) && ((Player->getPos().y > 175) && (Player->getPos().y < 250))) {
		activadorMelee1 = true;
		activadorMelee2 = false;
		activadorMelee3 = false;

	}
	if (activadorMelee1) {
		_melee1->perseguir(6, 600, 7, 50);
	}
	//activador golem 
	if (((Player->getPos().x > 900) && (Player->getPos().x < 950)) && ((Player->getPos().y > 30) && (Player->getPos().y < 150))) {
		activadorMelee1 = false;
		activadorMelee2 = true;
		activadorMelee3 = false;
	}
	if (activadorMelee2) {
		golem->perseguir(5, 950, 6, 50);
	}
	//activador ranged
	if (((Player->getPos().x > 1130) && (Player->getPos().x < 1250)) && ((Player->getPos().y > 390) && (Player->getPos().y < 450))) {
		activadorMelee1 = false;
		activadorMelee2 = false;
		activadorMelee3 = true;
	}
	//activador ranged (volviendo del golem)
	if (((Player->getPos().x > 500) && (Player->getPos().x < 550)) && ((Player->getPos().y > 500) && (Player->getPos().y < 600))) {
		activadorMelee1 = false;
		activadorMelee2 = false;
		activadorMelee3 = true;
	}
	if (activadorMelee3 && ranged->canAtack() && meleeExist3) {//hacer ranged can atak y sacar clase 2
		//_melee3->perseguir(9, 800, 4, 50);
		//bulletsE.push_back(new Bullet(texturesP["BULLET"], _melee3->getPos().x, _melee3->getPos().y, (_melee3->Seguir(Player->getPos())).x, (_melee3->Seguir(Player->getPos())).y, 7.f));
		bulletsE.push_back(new Bullet(texturesP["BULLET"], ranged->getPos().x + 10, ranged->getPos().y + 10, 0.f, 1.f, 3.f));
		bulletsE.push_back(new Bullet(texturesP["BULLET"], ranged->getPos().x + 10, ranged->getPos().y + 10, 1.f, 0.f, 3.f));
		bulletsE.push_back(new Bullet(texturesP["BULLET"], ranged->getPos().x + 10, ranged->getPos().y + 10, 0.f, -1.f, 3.f));
		bulletsE.push_back(new Bullet(texturesP["BULLET"], ranged->getPos().x + 10, ranged->getPos().y + 10, -1.f, 0.f, 3.f));
	}

	if (gargola->canAtack()) {
		bulletsG.push_back(new Bullet(texturesP["BULLET"], gargola->getPos().x - 30, gargola->getPos().y + 10, -1.f, 0.f, 3.f));
	}
	if (gargola2->canAtack()) {
		bulletsG.push_back(new Bullet(texturesP["BULLET"], gargola2->getPos().x + 10, gargola2->getPos().y - 25, 0.f, -1.f, 3.f));
	}
	if (gargola3->canAtack()) {
		bulletsG.push_back(new Bullet(texturesP["BULLET"], gargola3->getPos().x + 10, gargola3->getPos().y - 25, 0.f, -1.f, 3.f));
	}

	// choques con melees
	if (Niv2->chocoPersonajeMelee(Player, _melee1) && meleeExist1) {
		Player->chocaEnemigo(_melee1->getSpeed());
		Player->restarVida(_melee1->getDanio());
		Puntos -= 100;
		Niv2->borrarCorazon();
		Player->musicHit();
	}
	if (Niv2->chocoPersonajeGolem(Player, golem) && meleeExist2) {
		Player->chocaEnemigo(golem->getSpeed());
		Player->restarVida(golem->getDanio());
		Puntos -= 100;
		Niv2->borrarCorazon();
		Player->musicHit();
	}
	if (Niv2->chocoPersonajeRanged(Player, ranged) && meleeExist3) {
		Player->chocaEnemigo(ranged->getSpeed());
		Player->restarVida(ranged->getDanio());
		Puntos -= 100;
		Niv2->borrarCorazon();
		Player->musicHit();
	}

	// choque con la puerta
	if (Niv2->chocoPuerta(Player)) {
		Player->musicDoor();
		Puntos += TiempoMax * 10;
		Gano G;
		G.drawWin(window, Puntos);
	}
	// player murio
	if (Player->getVida() <= 0) {
		Gano G;
		G.drawLose(window, Puntos);
	}
	// choque con monedas
	if (Niv2->agarroMoneda(Player)) {
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
		//G.drawWin(window, Puntos);
	}
}

void Game2::updateBulletP()
{
	unsigned counter = 0;
	for (auto* bullet : bulletsP)
	{
		bullet->Update();

		//choques melee con bala
		if ((bullet->getPosition().x > 1300) || (bullet->getPosition().x < 0) || (bullet->getPosition().y > 700) || (bullet->getPosition().x < 0) ||
			Niv2->chocoBala(bulletsP) || (meleeExist1 && Niv2->chocoMelee(_melee1, bulletsP)) || (meleeExist2 && Niv2->chocoGolem(golem, bulletsP)) || (meleeExist3 && Niv2->chocoRanged(ranged, bulletsP))) {
			// descuenta vida melee1
			if (Niv2->chocoMelee(_melee1, bulletsP)) {
				_melee1->restarVida(danioProyectil);
				Puntos += 50;
				if (!_melee1->tieneVida()) {
					meleeExist1 = false;
					Puntos += 300;
				}
			}
			// descuenta vida golem
			if (Niv2->chocoGolem(golem, bulletsP)) {
				golem->restarVida(danioProyectil);
				Puntos += 50;
				if (!golem->tieneVida()) {
					meleeExist2 = false;
					Puntos += 300;
				}
			}
			// descuenta vida melee3
			if (Niv2->chocoRanged(ranged, bulletsP)) {
				ranged->restarVida(danioProyectil);
				Puntos += 50;
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

void Game2::updateBulletE()
{
	unsigned counter = 0;
	for (auto* BulletE : bulletsE)
	{
		BulletE->Update();

		//choques melee con bala
		if ((BulletE->getPosition().x > 1300) || (BulletE->getPosition().x < 0) || (BulletE->getPosition().y > 700) ||
			(BulletE->getPosition().x < 0) || Niv2->chocoBalaE(bulletsE) || (Niv2->chocoBulletPersonaje(Player, bulletsE))) {
			// descuenta vida Personaje
			if (Niv2->chocoBulletPersonaje(Player, bulletsE)) {
				Player->chocaEnemigo(ranged->getSpeed()); // Respawn al personaje
				Player->restarVida(ranged->getDanio());
				Puntos -= 100;
				Player->musicHit();
				Niv2->borrarCorazon();
				if (Player->getVida() <= 0) {
					Gano G;
					G.drawLose(window,Puntos);
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

void Game2::updateBulletG()
{
	unsigned counter = 0;
	for (auto* BulletsG : bulletsG)
	{
		BulletsG->Update();

		//choques melee con bala
		if ((BulletsG->getPosition().x > 1300) || (BulletsG->getPosition().x < 0) || (BulletsG->getPosition().y > 700) ||
			(BulletsG->getPosition().x < 0) || Niv2->chocoBalaE(bulletsG) || (Niv2->chocoBulletPersonaje(Player, bulletsG))) {
			// descuenta vida Personaje
			if (Niv2->chocoBulletPersonaje(Player, bulletsG)) {
				Player->chocaEnemigo(ranged->getSpeed()); // Respawn al personaje
				Player->restarVida(ranged->getDanio());
				Puntos -= 100;
				Player->musicHit();
				Niv2->borrarCorazon();
				if (Player->getVida() <= 0) {
					Gano G;
					G.drawLose(window, Puntos);
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

void Game2::run()
{
	while (window->isOpen()) {
		Update();
		Render();
	}
}

void Game2::Update()
{
	updatePollEvents();
	updateInput();
	Player->Update();
	ranged->Update();
	gargola->Update();
	gargola2->Update();
	gargola3->Update();
	updateBulletP();
	updateBulletE();
	updateBulletG();
}

void Game2::Render()
{
	window->clear();

	Niv2->Dibujar(window);

	Niv2->dibujarPuerta(window);

	Player->Render(*window);

	gargola->Render(*window);

	gargola2->Render(*window);

	gargola3->Render(*window);

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

void Game2::tocoBorde(int b)
{
	delete bulletsP.at(b);
	bulletsP.erase(bulletsP.begin() + (b - 1));

	delete bulletsE.at(b);
	bulletsE.erase(bulletsE.begin() + (b - 1));

}
