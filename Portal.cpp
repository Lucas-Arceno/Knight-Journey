#include "Portal.h"

Portal::Portal(Jogador* pJogador,sf::Vector2f(destino), sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(13, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/portal.png");
	this->corpo.setTexture(&texture);
	this->pJogador = pJogador;
	this->destino = destino;
}

Portal::~Portal()
{
}

void Portal::update()
{
	updateMovimento();
	updatePhysics();

	if (this->corpo.getGlobalBounds().intersects(pJogador->espadaP->getEspadaProjetilGlobal())) {
		this->corpo.setPosition(-1441.f, 421.f);
	}

	if (this->corpo.getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds())) {
		pJogador->setPosition(destino.x, destino.y);
	}
}

void Portal::updateMovimento()
{
}
