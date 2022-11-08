#include "Cobra.h"

Cobra::Cobra(Jogador* pJogador, sf::Vector2f posicao, sf::Vector2f tamanho) : Inimigo(2,pJogador, posicao, tamanho), vidaMaxima(200)
{
	this->vida = vidaMaxima;
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/cobra.png");
	this->corpo.setTexture(&texture);
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
