#include "Entidade.h"

Entidades::Entidade::Entidade(int id, sf::Vector2f posicao, sf::Vector2f tamanho) : Ente(id), velocidadeMax(5), velocidadeMaxY(15), velocidadeMin(1)
{
	this->corpo.setOrigin(tamanho / 2.0f);
	this->velocidade.x = 0.3f;
	this->velocidade.y = 0.3f;
	this->corpo.setPosition(posicao);
	this->corpo.setSize(tamanho);
	this->initPhysics();
}

Entidades::Entidade::~Entidade()
{
}

void Entidades::Entidade::setCorpoPosicao(sf::Vector2f pos)
{
	this->corpo.setPosition(pos);
}

void Entidades::Entidade::initPhysics()
{
	this->acceleration = 3.0f;
	this->drag = 0.87f;
	this->gravity = 4.f;
}

const sf::RectangleShape Entidades::Entidade::getCorpo()
{
	return corpo;
}

void Entidades::Entidade::updatePhysics()
{
	//Gravity
	this->velocidade.y += 1* this->gravity;
	if (std::abs(this->velocidade.x) > this->velocidadeMaxY) {
		this->velocidade.y = this->velocidadeMaxY * ((this->velocidade.y < 0.f) ? -1.f : 1.f);
	}

	//Deceleration
	this->velocidade *= this->drag;

	//Limit deceleration
	if (std::abs(this->velocidade.x) < this->velocidadeMin) {
		this->velocidade.x = 0.0f;
	}
	if (std::abs(this->velocidade.y) < this->velocidadeMin) {
		this->velocidade.y = 0.0f;
	}

	this->corpo.move(this->velocidade);
}
