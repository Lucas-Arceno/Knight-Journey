#include "Espinhos.h"

Espinhos::Espinhos(sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(12,posicao,tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/espinhos.png");
	this->corpo.setTexture(&texture);

	this->nivelAfiado = rand() % 3 + 1;
}

Espinhos::~Espinhos()
{
}

const int Espinhos::getNivelAfiado()
{
	if (clock == 0) {
		clock++;
		return nivelAfiado;
	}
	else {
		return 0;
	}
}

void Espinhos::update()
{
	updateMovimento();
	updatePhysics();

	if (clock > 0) {
		clock++;
		if (clock > 50)
			clock = 0;
	}
}

void Espinhos::updateMovimento()
{
}
