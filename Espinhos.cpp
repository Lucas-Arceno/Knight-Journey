#include "Espinhos.h"

Espinhos::Espinhos(sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(12,posicao,tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/espinhos.png");
	this->corpo.setTexture(&texture);
}

Espinhos::~Espinhos()
{
}

void Espinhos::update()
{
	updateMovimento();
	updatePhysics();
}

void Espinhos::updateMovimento()
{
}
