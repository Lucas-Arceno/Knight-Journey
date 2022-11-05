#include "Cobra.h"

Cobra::Cobra(Jogador* pJogador, sf::Vector2f posicao, sf::Vector2f tamanho) : Inimigo(pJogador, posicao, tamanho)
{
}

Cobra::~Cobra()
{
}

void Cobra::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
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

void Cobra::update()
{
	updateMovimento();
	updatePhysics();	
}

void Cobra::updateMovimento()
{
	sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= 500 && fabs(posJogador.y - posInimigo.y) <= 500) {
		persegueJogador(posJogador, posInimigo);
	}
}
