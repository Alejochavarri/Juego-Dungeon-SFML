#include "claseMenu.h"

int claseMenu::SuperMenu( int screenX, int screenY) {
    sf::RenderWindow* window = new RenderWindow(sf::VideoMode(screenX, screenY), "Dungeon");
    window->setFramerateLimit(60);

    MainMenu mainMenu(window->getSize().x, window->getSize().y);
    musicBG();

    sf::RectangleShape fondo;
    fondo.setSize(sf::Vector2f(1300, 700));
    sf::Texture fondoT;
    fondoT.loadFromFile("Img/fondoT.png");
    fondo.setTexture(&fondoT);

    Nivel1* Nvl1 = nullptr;

    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    mainMenu.moveUp();
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    mainMenu.moveDown();
                }
                else if (event.key.code == sf::Keyboard::Return) {
                    int x = mainMenu.MainMenuPressed();
                    if (x == 0) {
                        std::cout << "Seleccionaste Nivel 1" << std::endl;
                        
                        Game game(window);
                        game.run();
                        
                    }
                    else if (x == 1) {
                        std::cout << "Seleccionaste Puntajes" << std::endl;
                        showLevel2(window);
                    }
                    else if (x == 2) {
                        std::cout << "Seleccionaste Opciones" << std::endl;
                        showOptions(window);
                    }
                    else if (x == 3) {
                        std::cout << "Seleccionaste Salir" << std::endl;
                        return 0;
                    }
                }
            }
        }

        window->clear();
        window->draw(fondo);
        mainMenu.draw(*window);
        window->display();

    }

    return 0;
}

void claseMenu::showLevel1(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
}

void claseMenu::showLevel2(sf::RenderWindow *window) {

     Gano G;
     G.mostrarArchivo(window);
}

void claseMenu::showOptions(sf::RenderWindow* window) {
    Gano G;
    G.mostrarUsuario(window);
}