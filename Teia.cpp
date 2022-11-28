#include "Teia.h"

Entidades::Obstaculos::Teia::Teia(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(11, pJogadores, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/teia.png");
	this->corpo.setTexture(&texture);
	this->estagio = rand() % 15 + 1;
}

Entidades::Obstaculos::Teia::~Teia()
{
}

void Entidades::Obstaculos::Teia::update()
{
	updateMovimento();
	updatePhysics();
}

void Entidades::Obstaculos::Teia::updateMovimento()
{
}

void Entidades::Obstaculos::Teia::reagir()
{
	for (auto const& pJogador : *pJogadores) {
		pJogador->setVelocityX(0.1f * estagio);
	}
}
