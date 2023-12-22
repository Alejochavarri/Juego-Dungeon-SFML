#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

//num maximo de opciones
#define Max_main_menu 4

class MainMenu {
private:
	int MainMenuSelected;
	Font font;
	Text mainMenu[Max_main_menu];

public:
	MainMenu(float x, float y);

	void draw(RenderWindow& window);
	void moveUp();
	void moveDown();

	int MainMenuPressed() { return MainMenuSelected; }
	~MainMenu();

};
