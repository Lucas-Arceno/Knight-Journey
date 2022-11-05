#include "Caixa.h"

Caixa::Caixa(sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(posicao, tamanho)
{
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
