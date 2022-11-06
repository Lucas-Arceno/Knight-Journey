#include "Caixa.h"

Caixa::Caixa(sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/spider-web-drawing-desenho-de-teia-de-aranha-para-colorir-11563467477xgvcfeu44p.png");
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
