#include "Gano.h"
#include <iostream>
using namespace std;
using namespace sf;

Gano::Gano() { 
	if (!font.loadFromFile("Fonts/8-bit-hud.ttf")) {
		cout << "No hay fuente" << endl;
	}
} 

void Gano::draw(RenderWindow& window) {
	window.draw(Cartel);
	window.draw(Salir);
	window.draw(Puntos);
	window.draw(Nombre);
	window.draw(cartelNombre);
}

void Gano::drawWin(sf::RenderWindow* window, int P) {

	sf::RectangleShape fondo; 
	fondo.setSize(sf::Vector2f(1300, 700)); 
	sf::Texture fondoT; 
	fondoT.loadFromFile("Img/fondoT.png"); 
	fondo.setTexture(&fondoT); 

	Cartel.setFont(font);
	Salir.setFont(font);
	Puntos.setFont(font);
	Nombre.setFont(font);
	cartelNombre.setFont(font);

	Cartel.setFillColor(sf::Color::Black);
	Cartel.setString("NIVEL SUPERADO");
	Cartel.setCharacterSize(20);
	Cartel.setPosition(430, 230);

	Puntos.setFillColor(sf::Color::Black);
	Puntos.setString("PUNTOS : " + to_string(P));
	Puntos.setCharacterSize(20);
	Puntos.setPosition(430, 330);

	Salir.setFillColor(sf::Color::Black);
	Salir.setString("Presione Space Para Salir...");
	Salir.setCharacterSize(10);
	Salir.setPosition(940, 640);

	Nombre.setFillColor(sf::Color::Black);
	Nombre.setString("Ingrese Nombre - ");
	Nombre.setCharacterSize(15);
	Nombre.setPosition(430, 430);

	window->clear();
	window->draw(fondo);
	draw(*window);
	window->display();

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			else {
				if ((event.type == sf::Event::TextEntered) && (nombre.size() < 6))
				{
					if (event.text.unicode < 128)
					{
						char letra = static_cast<char>(event.text.unicode);
						nombre += letra;
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					window->close();
					generarArchivo(P);
					claseMenu menu;
					menu.SuperMenu(1300, 700);
				}
	
				Nombre.setString("Ingrese Nombre - " + nombre);
				window->clear();
				window->draw(fondo);
				draw(*window);
				window->display();
			}
		}
	}
}

void Gano::drawLose(sf::RenderWindow* window, int P)
{
	sf::RectangleShape fondo;
	fondo.setSize(sf::Vector2f(1300, 700));
	sf::Texture fondoT;
	fondoT.loadFromFile("Img/fondoT.png");
	fondo.setTexture(&fondoT);

	Cartel.setFont(font);
	Salir.setFont(font);
	Puntos.setFont(font);
	Nombre.setFont(font);
	cartelNombre.setFont(font);

	Cartel.setFillColor(sf::Color::Black);
	Cartel.setString("NIVEL FALLIDO");
	Cartel.setCharacterSize(20);
	Cartel.setPosition(430, 230);

	Puntos.setFillColor(sf::Color::Black);
	Puntos.setString("PUNTOS : " + to_string(P));
	Puntos.setCharacterSize(20);
	Puntos.setPosition(430, 330);

	Salir.setFillColor(sf::Color::Black);
	Salir.setString("Presione Space Para Salir...");
	Salir.setCharacterSize(10);
	Salir.setPosition(940, 640);

	Nombre.setFillColor(sf::Color::Black);
	Nombre.setString("Ingrese Nombre - ");
	Nombre.setCharacterSize(15);
	Nombre.setPosition(430, 430);

	window->clear();
	window->draw(fondo);
	draw(*window);
	window->display();

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			else {
				if ((event.type == sf::Event::TextEntered) && (nombre.size() < 6))
				{
					if (event.text.unicode < 128)
					{
						char letra = static_cast<char>(event.text.unicode);
						nombre += letra;
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					window->close();
					generarArchivo(P);
					claseMenu menu;
					menu.SuperMenu(1300, 700);
				}

				Nombre.setString("Ingrese Nombre - " + nombre);
				window->clear();
				window->draw(fondo);
				draw(*window);
				window->display();
			}
		}
	}
}

void Gano::generarArchivo(int P)
{
	FILE* p = fopen("ArchivoPuntos.dat", "ab");
	if (p == NULL) {
		cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
		return;
	};
	Archivo Registro;
	Registro.setNombre(nombre.c_str());
	Registro.setPuntos(P);
	fwrite(&Registro, sizeof(Archivo), 1, p);
	fclose(p);
}

void Gano::mostrarArchivo(sf::RenderWindow* window)
{
	Cartel.setFont(font);
	Salir.setFont(font);
	Puntos.setFont(font);
	Ordenar();
	FILE* p = fopen("ArchivoPuntos.dat", "rb");

	Archivo E;
	int Aux = 230;

	//mostrar registro

	Salir.setFillColor(sf::Color::Black);
	Salir.setString("Presione Space Para Salir...");
	Salir.setCharacterSize(10);
	Salir.setPosition(940, 640);

	sf::RectangleShape fondo;
	fondo.setSize(sf::Vector2f(1300, 700));
	sf::Texture fondoT;
	fondoT.loadFromFile("Img/fondoT.png");
	fondo.setTexture(&fondoT);

	window->clear();
	window->draw(fondo);
	draw(*window);
	if (p == NULL) {
		Cartel.setFillColor(sf::Color::Black);
		Cartel.setString("No hay Partidas Cargadas");
		Cartel.setCharacterSize(20);
		Cartel.setPosition(430, 130);
		draw(*window);
	}
	else {
		while ((fread(&E, sizeof(Archivo), 1, p) != 0)) {

			Puntos.setFillColor(sf::Color::Black);
			Puntos.setString("TOP 5");
			Puntos.setCharacterSize(20);
			Puntos.setPosition(550, 130);

			Cartel.setFillColor(sf::Color::Black);
			std::string n;
			n += E.getNombre();
			n += "  -  ";
			Cartel.setString(n + to_string(E.getPuntos()));
			Cartel.setCharacterSize(20);
			Cartel.setPosition(530, Aux);
			draw(*window);
			Aux += 50;
		}
		fclose(p);
	}
	window->display();
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				window->close();
				claseMenu menu;
				menu.SuperMenu(1300, 700);
			}
		}
	}
}

void Gano::mostrarUsuario(sf::RenderWindow* window)
{
	Cartel.setFont(font);
	Salir.setFont(font);
	Puntos.setFont(font);

	Salir.setFillColor(sf::Color::Black);
	Salir.setString("Presione Space Para Salir...");
	Salir.setCharacterSize(10);
	Salir.setPosition(940, 640);

	sf::RectangleShape fondo;
	fondo.setSize(sf::Vector2f(1300, 700));
	sf::Texture fondoT;
	fondoT.loadFromFile("Img/fondoT.png");
	fondo.setTexture(&fondoT);

	Cartel.setFillColor(sf::Color::Black);
	Cartel.setString("Chavarri Alejo , 27516");
	Cartel.setCharacterSize(20);
	Cartel.setPosition(400, 130);

	Puntos.setFillColor(sf::Color::Black);
	Puntos.setString("Beltran Teo , 24921");
	Puntos.setCharacterSize(20);
	Puntos.setPosition(400, 230);

	window->clear();
	window->draw(fondo);
	draw(*window);
	
	window->display();
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				window->close();
				claseMenu menu;
				menu.SuperMenu(1300, 700);
			}
		}
	}
}

void Gano::Ordenar()
{	
	
	FILE* p = fopen("ArchivoPuntos.dat", "rb");
	
	if (p == NULL) {
		return;
		//delete p;
	}else{
		archivoManager Am;
		Archivo E;
		int Size = Am.contarRegistros();
		Archivo* vReg = nullptr;

		vReg = new Archivo[Size];

		for (int i = 0; i < Size; i++) {//recorro el archivo
			E = Am.leerRegistro(i);
			vReg[i].setPuntos(E.getPuntos());
			vReg[i].setNombre(E.getNombre());
		}
		ordenarVectores(vReg, Am.contarRegistros());
		//for (int i = 0; i < Size; i++) {
			//vReg[i].mostrarRegistro();
		//}
		fclose(p);

		FILE* p = fopen("ArchivoPuntos.dat", "wb");
		if (p == NULL) {
			cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
			return;
		};
		if (Size > 5) {
		for (int i = 0; i < 5; i++) {
			E.setNombre(vReg[i].getNombre());
			E.setPuntos(vReg[i].getPuntos());
			fwrite(&E, sizeof(Archivo), 1, p);
			}
		}
		else {
			for (int i = 0; i < Size; i++) {
				E.setNombre(vReg[i].getNombre());
				E.setPuntos(vReg[i].getPuntos());
				fwrite(&E, sizeof(Archivo), 1, p);
			}
		}

		fclose(p);
		delete []vReg;
		
	}
}

void Gano::ordenarVectores(Archivo* v, int tam) {
	int i, j;
	for (i = 0; i < tam - 1; i++)
		for (j = 0; j < tam - i - 1; j++)
			if (v[j].getPuntos() < v[j + 1].getPuntos())
				swap(v[j], v[j + 1]);
}

Gano::~Gano() {}

