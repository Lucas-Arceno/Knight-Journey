#include "Obstaculo.h"

Entidades::Obstaculos::Obstaculo::Obstaculo(int id, sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(id, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::Yellow);
}

Entidades::Obstaculos::Obstaculo::~Obstaculo()
{
}
