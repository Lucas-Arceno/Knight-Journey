#include "Teia.h"

Teia::Teia(sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(11, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/teia.png");
	this->corpo.setTexture(&texture);

	this->estagio = rand() % 15;
}

Teia::~Teia()
{
}

const int Teia::getEstagio()
{
	return estagio;
}

void Teia::update()
{
	updateMovimento();
	updatePhysics();
}

void Teia::updateMovimento()
{
}
