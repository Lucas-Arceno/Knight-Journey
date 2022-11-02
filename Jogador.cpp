#include "Jogador.h"

int Jogador::vidaJogador = 100;

Jogador::Jogador(sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(posicao, tamanho) ,vidaMaxima(100), velocidadeMax(5.f), velocidadeMaxY(15.f), velocidadeMin(1.f)
{
	initVariables();
}

Jogador::~Jogador()
{
}

void Jogador::initVariables()
{
	velocidade.x = 0.3f;
	velocidade.y = 0.3f;
	vidaJogador = vidaMaxima;

	corpo.setFillColor(sf::Color::Blue);
}

const sf::FloatRect Jogador::getGlobalBounds() const
{
	return sprite.getGlobalBounds();
}

void Jogador::update()
{
	updateMovimento();
}

void Jogador::updateMovimento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		corpo.move(-velocidade.x, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		corpo.move(velocidade.x, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		corpo.move(0, -velocidade.y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		corpo.move(0, velocidade.y);
	}
}
