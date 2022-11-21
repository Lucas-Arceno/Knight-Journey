#include "Plataforma.h"

Entidades::Plataforma::Plataforma(sf::Vector2f posicao, sf::Vector2f tamanho, const int tipo) : tipo(tipo), Entidades::Entidade(31, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	if (this->tipo == 0) {
		this->texture.loadFromFile("assets/teste2.png");
	}
	else {
		this->texture.loadFromFile("assets/chao.jpg");
	}
	this->corpo.setTexture(&texture);
}

Entidades::Plataforma::~Plataforma()
{
}

void Entidades::Plataforma::update()
{
	updateMovimento();
	updatePhysics();
	updateEmpuxo();
}

void Entidades::Plataforma::updateEmpuxo()
{
	//Gravity
	this->velocidade.y += 1 * this->gravity;
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

void Entidades::Plataforma::updateMovimento()
{
}
