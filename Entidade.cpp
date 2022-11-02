#include "Entidade.h"

Entidade::Entidade(sf::Vector2f posicao, sf::Vector2f tamanho)
{
	this->corpo.setPosition(posicao);
	this->corpo.setSize(tamanho);
}

Entidade::~Entidade()
{
}

void Entidade::setPosicao(sf::Vector2f pos)
{
	this->posicao = pos;
}

const sf::RectangleShape Entidade::getCorpo()
{
	return corpo;
}

sf::Vector2f Entidade::getPosicao() const
{
	return this->posicao;
}

sf::Vector2f Entidade::getTamanho() const
{
	return this->tamanho;
}
