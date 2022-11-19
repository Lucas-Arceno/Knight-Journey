#include "JogadorSecundario.h"

JogadorSecundario::JogadorSecundario(sf::Vector2f posicao, sf::Vector2f tamanho) : Jogador(posicao, tamanho)
{
	this->texture.loadFromFile("assets/teste.png");
	this->corpo.setTexture(&texture);
}

JogadorSecundario::~JogadorSecundario()
{
}

void JogadorSecundario::updateMovimento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
		this->move(-1.0f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		this->move(1.f, 0.f);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && coldownPulo == true)) {
		this->velocidade.y -= 20 * this->gravity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
		atacarEsq();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
		atacarDir();
	}
}
