#include "Portal.h"

Portal::Portal(std::list<Jogador*>* pJogadores,sf::Vector2f(destino), sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(13, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/portal.png");
	this->corpo.setTexture(&texture);
	this->pJogadores = pJogadores;
	this->destino = destino;
}

Portal::~Portal()
{
}

void Portal::update()
{
	updateMovimento();
	updatePhysics();

	for (auto const& pJogador : *pJogadores)
	{
		if (this->corpo.getGlobalBounds().intersects(pJogador->espadaP->getEspadaProjetilGlobal())) {
			this->corpo.setPosition(-1441.f, 5931.f);
		}

		if (this->corpo.getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds())) {
			pJogador->setPosition(destino.x, destino.y);
		}
	}
}

void Portal::updateMovimento()
{
}
