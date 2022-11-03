#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::pGraphics = nullptr;

GerenciadorGrafico::GerenciadorGrafico() : window(new sf::RenderWindow(sf::VideoMode(1200, 800), "Knight Journey")) 
{
	if (window == nullptr)
	{
		std::cout << "Nao foi possivel criar uma janela grafica." << std::endl;
		exit(1);
	}
	window->setFramerateLimit(60);
}

GerenciadorGrafico::~GerenciadorGrafico()
{
	if (window) {
		delete(window);
		window = nullptr;
	}
}

sf::RenderWindow* GerenciadorGrafico::getJanela()
{
	return window;
}

const bool GerenciadorGrafico::verificaJanelaAberta()
{
	return window->isOpen();
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico()
{
	if (pGraphics == nullptr) {
		pGraphics = new GerenciadorGrafico();
	}
	return pGraphics;
}

void GerenciadorGrafico::limpaJanela()
{
	window->clear();
}

void GerenciadorGrafico::desenhaSprites(sf::Sprite sprite)
{
	window->draw(sprite);
}

void GerenciadorGrafico::desenhaElementos(sf::RectangleShape body)
{
	window->draw(body);
}

void GerenciadorGrafico::mostraElementos()
{
	window->display();
}

void GerenciadorGrafico::fechaJanela()
{
	window->close();
}
