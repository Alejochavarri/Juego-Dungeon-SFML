#include "Nivel1.h"

Nivel1::Nivel1() 
{
    _bloque = new Bloque();
    _piso = new Piso();
    _moneda = new Moneda(); 
    _puerta = new Door();
    pincho = new Pinchos();
    corazon = new Corazon();
    torch = new Antorcha();
    contador = 0;
    posCorazon = 23; // 23/0
}

Nivel1::~Nivel1()
{
    delete _bloque;
    delete _piso;
    delete _moneda;
    delete _puerta;
}

void Nivel1::cargarMatriz(/*bool& monedaA*/) {
    const int filas = 14;
    const int columnas = 26;

    int MAux[filas][columnas] = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4,
                                  2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                                  2, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                                  2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                                  2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                                  2, 1, 1, 1, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2,
                                  2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                                  2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                  2, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                  2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                                  2, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                                  2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                                  2, 1, 1, 1, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
                                  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5 };

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            //M[i][j] = MAux[i][j];
            Matriz[i][j] = MAux[i][j];
        }
    }

}

void Nivel1::Dibujar(sf::RenderWindow* window) {

    for (int j = 0; j < 14; j++) {
        for (int i = 0; i < 26; i++) {
            if (Matriz[j][i] == 2) {
                _bloque->Update(i * celX, j * celY);
                window->draw(_bloque->getSprite());
                    
            }
            else {
                if (Matriz[j][i] == 1) {
                    _piso->Update(i * celX, j * celY);
                    window->draw(_piso->getSprite());
                    
                }
                if (Matriz[j][i] == 3) {
                    _piso->Update(i * celX, j * celY);
                    window->draw(_piso->getSprite());
                    _moneda->Update(i * celX + 15, j * celY + 15);
                    window->draw(_moneda->getSprite());

                }
                if (Matriz[j][i] == 5) {
                    _bloque->Update(i * celX, j * celY);
                    window->draw(_bloque->getSprite());
                    _moneda->Update(i * celX + 15, j * celY + 15);
                    window->draw(_moneda->getSprite());

                }
                if (Matriz[j][i] == 6) {
                    _piso->Update(i * celX, j * celY);
                    window->draw(_piso->getSprite());
                    pincho->Update(i * celX, j * celY);
                    window->draw(pincho->getSprite());

                }
                if (Matriz[j][i] == 4) {
                    _bloque->Update(i * celX, j * celY);
                    window->draw(_bloque->getSprite());
                    corazon->Update(i * celX + 10, j * celY + 10);
                    window->draw(corazon->getSprite());
                }
                if (Matriz[j][i] == 7) {
                    _bloque->Update(i * celX, j * celY);
                    window->draw(_bloque->getSprite());
                    torch->Update(i * celX, j * celY);
                    window->draw(torch->getSprite());
                }
            }
        }
    }
}

void Nivel1::dibujarPuerta(sf::RenderWindow* window)
{
    _puerta->Update(screenX - 100, screenY - 100);
    window->draw(_puerta->getSprite());
}

bool Nivel1::chocoPersonaje(Personaje* Player, Gargola* G) {
    //Bloque* _bloque = new Bloque();
    //Piso _piso;

    for (int j = 0; j < 14; j++) {
        for (int i = 0; i < 26; i++) {
            if (Matriz[j][i] == 2) {
                _bloque->Update(i * celX, j * celY);
                if ((Player->isColision(_bloque)) ||  (Player->isColision(G))) {
                    
                    return true;
                }
            }  
            if (Matriz[j][i] == 4) {
                corazon->Update(i * celX + 10, j * celY + 10);
                if ((Player->isColision(_bloque)) || (Player->isColision(corazon))) {

                    return true;
                }
            }
        }
    }
    return false;
}

bool Nivel1::chocoBala(std::vector<Bullet*> bullets) {

    for (int j = 0; j < 14; j++) {
        for (int i = 0; i < 26; i++) {
            if (Matriz[j][i] == 2) {
                _bloque->Update(i * celX, j * celY);
                for (size_t i = 0; i < bullets.size(); i++)
                {
                    if (bullets[i]->isColision(_bloque)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Nivel1::chocoBalaE(std::vector<Bullet*> bullets)
{
    for (int j = 0; j < 14; j++) {
        for (int i = 0; i < 26; i++) {
            if (Matriz[j][i] == 2) {
                _bloque->Update(i * celX, j * celY);
                for (size_t i = 0; i < bullets.size(); i++)
                {
                    if (bullets[i]->isColision(_bloque)) {
                        return true;
                    }
                }

            }

        }

    }
    return false;
}

bool Nivel1::chocoMelee(Melee* _melee, std::vector<Bullet*> bullets) {
    for (size_t i = 0; i < bullets.size(); i++)
    {
        if (bullets[i]->isColision(_melee)) {
            return true;
        }
    }
    return false;
}

bool Nivel1::chocoPersonajeMelee(Personaje* Player, Melee* _melee)
{
    if (Player->isColision(_melee)) {
        return true;
    }
    return false;
}

bool Nivel1::chocoPersonajeGolem(Personaje* Player, Golem* _melee)
{
    if (Player->isColision(_melee)) {
        return true;
    }
    return false;
}

bool Nivel1::chocoRanged(Ranged* _melee, std::vector<Bullet*> bullets)
{
    for (size_t i = 0; i < bullets.size(); i++)
    {
        if (bullets[i]->isColision(_melee)) {

            return true;
        }
    }

    return false;
}

bool Nivel1::chocoGolem(Golem* _melee, std::vector<Bullet*> bullets)
{
    for (size_t i = 0; i < bullets.size(); i++)
    {
        if (bullets[i]->isColision(_melee)) {

            return true;
        }
    }

    return false;
}

bool Nivel1::chocoBulletPersonaje(Personaje* _melee, std::vector<Bullet*> bullets)
{
    for (size_t i = 0; i < bullets.size(); i++)
    {
        if (bullets[i]->isColision(_melee)) {

            return true;

        }
    }

    return false;
}

bool Nivel1::chocoPersonajeRanged(Personaje* Player, Ranged* _melee)
{
    if (Player->isColision(_melee)) {
        return true;
    }
    return false;
}

void Nivel1::borrarCorazon()
{
    Matriz[0][posCorazon] = 2;
    posCorazon++;
}

bool Nivel1::chocoPuerta(Personaje* Player)
{
    if (Player->isColision(_puerta)) {
        return true;
    }
    return false;
}

bool Nivel1::agarroMoneda(Personaje* Player)
{
    for (int j = 0; j < 14; j++) {
        for (int i = 0; i < 26; i++) {
            if (Matriz[j][i] == 3) { 
                _moneda->Update(i * celX + 15, j * celY + 15);
                    if (Player->isColision(_moneda)) {
                        Matriz[j][i] = 1; 
                        contador++;
                        if (contador == 3) {
                            Matriz[8][16] = 1;
                            Matriz[8][17] = 1;
                        }
                        return true;
                    }

            }

        }

    }
    return false;
}
