#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "MainMenu.h"
#include "Game.h"
#include "Game2.h"
#include "Nivel1.h"
#include "Gano.h"

class claseMenu {
private:
    int nivelActual = 1;
    sf::Music music;
        
public:
    int SuperMenu(int screenX, int screenY);
    void showLevel1(sf::RenderWindow& window);
    void showLevel2(sf::RenderWindow* window);
    void showOptions(sf::RenderWindow* window);

    void musicBG()
    {
        if (!music.openFromFile("Sound/Background.wav")) {
            std::cout << "1" << std::endl;
        }
        music.setVolume(5.f);
        music.play();
    }

    void musicStop()
    {
        music.stop();
    }
};