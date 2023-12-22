#include "MainMenu.h"
#include <iostream>
using namespace std;
using namespace sf;

MainMenu::MainMenu(float x, float y) {
	if (!font.loadFromFile("Fonts/8-bit-hud.ttf")) {
		cout << "No hay fuente" << endl;
	}

	//Play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::White);
	mainMenu[0].setString("Jugar");
	mainMenu[0].setCharacterSize(20);
	mainMenu[0].setPosition(300, 200);
	//Options
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Puntajes");
	mainMenu[1].setCharacterSize(20);
	mainMenu[1].setPosition(300, 250);
	//Creditos
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("Creditos");
	mainMenu[2].setCharacterSize(20);
	mainMenu[2].setPosition(300, 300);
	//Salir
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color::White);
	mainMenu[3].setString("Salir");
	mainMenu[3].setCharacterSize(20);
	mainMenu[3].setPosition(300, 350);

	MainMenuSelected = -1;
}

void MainMenu::draw(RenderWindow& window){
	for (int i = 0; i < Max_main_menu; i++) {
		window.draw(mainMenu[i]);
	}
}

void MainMenu::moveUp(){
	if (MainMenuSelected - 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected--;

		if (MainMenuSelected == -1) {
			MainMenuSelected = 2;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Black);
	}
}

void MainMenu::moveDown() {
	if (MainMenuSelected + 1 <= Max_main_menu) {
		mainMenu[MainMenuSelected].setFillColor(sf::Color::White);
		MainMenuSelected++;

		if (MainMenuSelected == 4) {
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(sf::Color::Black);
	}
}

MainMenu::~MainMenu() {}
