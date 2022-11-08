#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(3, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/teste2.png");
	this->corpo.setTexture(&texture);
}

Plataforma::~Plataforma()
{
}

void Plataforma::update()
{
	updateMovimento();
	updatePhysics();
	updateEmpuxo();
}

void Plataforma::updateEmpuxo()
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

	this->corpo.move(-(this->velocidade));
}

void Plataforma::updateMovimento()
{
}
