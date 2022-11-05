#include "Obstaculo.h"

Obstaculo::Obstaculo(sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::Yellow);
}

Obstaculo::~Obstaculo()
{
}
