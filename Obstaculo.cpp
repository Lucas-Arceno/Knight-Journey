#include "Obstaculo.h"

Entidades::Obstaculos::Obstaculo::Obstaculo(int id, std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(id, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::Yellow);
	this->pJogadores = pJogadores;
}

Entidades::Obstaculos::Obstaculo::~Obstaculo()
{
}

void Entidades::Obstaculos::Obstaculo::reagirDano()
{
	//
}
