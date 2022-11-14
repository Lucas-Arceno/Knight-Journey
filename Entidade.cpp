#include "Entidade.h"

Entidade::Entidade(int id, sf::Vector2f posicao, sf::Vector2f tamanho) : Ente(id), velocidadeMax(5.f), velocidadeMaxY(15.f), velocidadeMin(1.f)
{
	this->corpo.setOrigin(tamanho / 2.0f);
	this->velocidade.x = 0.3f;
	this->velocidade.y = 0.3f;
	this->corpo.setPosition(posicao);
	this->corpo.setSize(tamanho);
	this->initPhysics();
}

Entidade::~Entidade()
{
}

void Entidade::setCorpoPosicao(sf::Vector2f pos)
{
	this->corpo.setPosition(pos);
}

void Entidade::initPhysics()
{
	this->acceleration = 3.0f;
	this->drag = 0.87f;
	this->gravity = 4.f;
}

const sf::RectangleShape Entidade::getCorpo()
{
	return corpo;
}

void Entidade::updatePhysics()
{
	//Gravity
	this->velocidade.y += 1.0 * this->gravity;
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
