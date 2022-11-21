#include "Teia.h"

Entidades::Obstaculos::Teia::Teia(sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(11, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/teia.png");
	this->corpo.setTexture(&texture);

	this->estagio = rand() % 15;
}

Entidades::Obstaculos::Teia::~Teia()
{
}

const int Entidades::Obstaculos::Teia::getEstagio()
{
	return estagio;
}

void Entidades::Obstaculos::Teia::update()
{
	updateMovimento();
	updatePhysics();
}

void Entidades::Obstaculos::Teia::updateMovimento()
{
}
