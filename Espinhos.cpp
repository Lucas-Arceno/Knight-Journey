#include "Espinhos.h"

Espinhos::Espinhos(sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(12,posicao,tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/espinhos.png");
	this->corpo.setTexture(&texture);

	this->nivelAfiado = rand() % 100;
}

Espinhos::~Espinhos()
{
}

const int Espinhos::getNivelAfiado()
{
	return nivelAfiado;
}

void Espinhos::update()
{
	updateMovimento();
	updatePhysics();
}

void Espinhos::updateMovimento()
{
}
