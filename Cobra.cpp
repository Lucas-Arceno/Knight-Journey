#include "Cobra.h"

Cobra::Cobra(Jogador* pJogador, sf::Vector2f posicao, sf::Vector2f tamanho) : Inimigo(21,pJogador, posicao, tamanho), vidaMaxima(2), venenosa(false)
{
	int aux = rand() % 2 + 1;
	if (aux == 1) {
		this->venenosa = false;
		this->texture.loadFromFile("assets/cobra.png");
	}
	if (aux == 2) {
		this->venenosa = true;
		this->texture.loadFromFile("assets/cobravenenosa.png");
	}
	setVida(vidaMaxima);
	this->corpo.setFillColor(sf::Color::White);
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

void Cobra::darBote()
{
	if (this->venenosa == true) {
		updateDano(2);
	}
	else {
		updateDano(1);
	}
}

void Cobra::update()
{
	updateMovimento();
	updatePhysics();	
	darBote();
}

void Cobra::updateMovimento()
{
	sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= 300 && fabs(posJogador.y - posInimigo.y) <= 300) {
		persegueJogador(posJogador, posInimigo);
	}
	else randomMovimento();
}
