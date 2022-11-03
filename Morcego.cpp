#include "Morcego.h"

Morcego::Morcego(Jogador* pJogador, sf::Vector2f posicao, sf::Vector2f tamanho) : Inimigo(pJogador, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
}

Morcego::~Morcego()
{
}

void Morcego::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	if (posJogador.x - posInimigo.x > 100.0f) {
		corpo.move(3.f, 0.0f);
	}
	else {
		corpo.move(-3.f, 0.0f);
	}
	if (posJogador.y - posInimigo.y > 100.0f) {
		corpo.move(0, 3.f);
	}
	else {
		corpo.move(0, -3.f);
	}
}

void Morcego::update()
{
	updateMovimento();
}

void Morcego::updateMovimento()
{
	sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) < 500 && fabs(posJogador.y - posInimigo.y) < 500) {
		persegueJogador(posJogador, posInimigo);
	}
}
