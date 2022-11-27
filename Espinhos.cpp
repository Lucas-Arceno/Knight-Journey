#include "Espinhos.h"

Entidades::Obstaculos::Espinhos::Espinhos(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao, sf::Vector2f tamanho) : Entidades::Obstaculos::Obstaculo(12,posicao,tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/espinhos.png");
	this->corpo.setTexture(&texture);
	this->pJogadores = pJogadores;

	this->nivelAfiado = rand() % 3 + 1;
}

Entidades::Obstaculos::Espinhos::~Espinhos()
{
}

const int Entidades::Obstaculos::Espinhos::getNivelAfiado()
{
	if (clock == 0) {
		clock++;
		return nivelAfiado;
	}
	else {
		return 0;
	}
}

void Entidades::Obstaculos::Espinhos::update()
{
	updateMovimento();
	updatePhysics();

	if (clock > 0) {
		clock++;
		if (clock > 50)
			clock = 0;
	}
}

void Entidades::Obstaculos::Espinhos::updateMovimento()
{
}

void Entidades::Obstaculos::Espinhos::reagir()
{
	for (auto const& pJogador : *pJogadores) {
		if (!pJogador->isInvencivel()) {
			pJogador->operator-(1 * nivelAfiado);
			printf("vida %d", pJogador->getVida());
		}
	}
}
