#include "Portal.h"

Entidades::Obstaculos::Portal::Portal(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores,sf::Vector2f(destino), sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(13, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/portal.png");
	this->corpo.setTexture(&texture);
	this->pJogadores = pJogadores;
	this->destino = destino;
}

Entidades::Obstaculos::Portal::~Portal()
{
}

void Entidades::Obstaculos::Portal::update()
{
	updateMovimento();
	updatePhysics();


	
	for (auto const& pJogador : *pJogadores)
	{
		// Portal é um obstaculo destrutivel
		// Se houver colisão com a espada o objeto é desligado.
		if (this->corpo.getGlobalBounds().intersects(pJogador->espadaP->getEspadaProjetilGlobal())) {
			//this->corpo.setPosition(0.f, 6000.f);
			this->isVivo = false;
		}

		// Se o jogador colidir com o portal ele é teleportado para o inicio
		if (this->corpo.getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds())) {
			pJogador->setPosition(destino.x, destino.y);
		}
	}
}

void Entidades::Obstaculos::Portal::updateMovimento()
{
}

void Entidades::Obstaculos::Portal::reagir()
{
}
