#include "Inimigo.h"
#include <cmath>

Inimigo::Inimigo(Jogador* pJogador,sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(posicao, tamanho), pJogador(nullptr)
{
	this->corpo.setFillColor(sf::Color::Red);
	this->pJogador = pJogador;
}

Inimigo::~Inimigo()
{
}

void Inimigo::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	if (posJogador.x - posInimigo.x > 0.0f) {
		corpo.move(1.f, 0.0f);
	}
	else {
		corpo.move(-1.f, 0.0f);
	}
	/*if (posJogador.y - posInimigo.y > 0.0f) {
		corpo.move(0, 1.f);
	}
	else {
		corpo.move(0, -1.f);
	}*/
}

void Inimigo::update() 
{
	updateMovimento();
}

void Inimigo::updateMovimento()
{
	sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= 200 && fabs(posJogador.y - posInimigo.y) <= 200) {
		persegueJogador(posJogador, posInimigo);
	}
}
