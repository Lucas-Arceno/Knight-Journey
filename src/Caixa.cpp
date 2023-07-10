#include "Teia.h"

Teia::Teia(sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(11, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/teia.png");
	this->corpo.setTexture(&texture);
}

Caixa::~Caixa()
{
}

void Caixa::update()
{
	updateMovimento();
	updatePhysics();
}

void Caixa::updateMovimento()
{
}
