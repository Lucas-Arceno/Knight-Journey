#include "Inimigo.h"
#include <cmath>

Inimigo::Inimigo(int id, Jogador* pJogador,sf::Vector2f posicao, sf::Vector2f tamanho) : Personagem(2, posicao, tamanho), pJogador(nullptr)
{
	this->vida = 100;
	this->corpo.setFillColor(sf::Color::Green);
	this->pJogador = pJogador;
}

Inimigo::~Inimigo()
{
}

void Inimigo::verificaDano()
{
	if (pJogador->getCorpoEspada().getGlobalBounds().intersects(this->getCorpo().getGlobalBounds())) {
		if (this->getVida() <= 0) {
			this->setCorpoPosicao(sf::Vector2f(0.0f, 6000.f));
		}
		this->giveDano(25);
	}
}

