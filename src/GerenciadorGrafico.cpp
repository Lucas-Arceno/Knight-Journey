#include "GerenciadorGrafico.h"

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::pGraphics = nullptr;

Gerenciadores::GerenciadorGrafico::GerenciadorGrafico() : window(new sf::RenderWindow(sf::VideoMode(1200, 800), "Knight Journey"))
{
	if (window == nullptr)
	{
		std::cout << "Nao foi possivel criar uma janela grafica." << std::endl;
		exit(1);
	}
	window->setFramerateLimit(60);
}

Gerenciadores::GerenciadorGrafico::~GerenciadorGrafico()
{
	if (window) {
		delete(window);
		window = nullptr;
	}
}

sf::RenderWindow* Gerenciadores::GerenciadorGrafico::getJanela()
{
	return window;
}

const bool Gerenciadores::GerenciadorGrafico::verificaJanelaAberta()
{
	return window->isOpen();
}

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico()
{
	if (pGraphics == nullptr) {
		pGraphics = new GerenciadorGrafico();
	}
	return pGraphics;
}

void Gerenciadores::GerenciadorGrafico::limpaJanela()
{
	window->clear();
}

void Gerenciadores::GerenciadorGrafico::desenhaSprites(sf::Sprite sprite)
{
	window->draw(sprite);
}

void Gerenciadores::GerenciadorGrafico::desenhaElementos(sf::RectangleShape body)
{
	window->draw(body);
}

void Gerenciadores::GerenciadorGrafico::mostraElementos()
{
	window->display();
}

void Gerenciadores::GerenciadorGrafico::fechaJanela()
{
	window->close();
}

void Gerenciadores::GerenciadorGrafico::setView(sf::Vector2f(pos))
{
	sf::View view;
	view.setCenter(pos);
	this->getJanela()->setView(view);
}
