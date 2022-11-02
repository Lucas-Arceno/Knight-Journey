#include "Jogador.h"

int Jogador::vidaJogador = 100;

Jogador::Jogador(sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(posicao, tamanho) ,vidaMaxima(100), velocidadeMax(5.f), velocidadeMaxY(15.f), velocidadeMin(1.f)
{
	initVariables();
	initPhysics();
}

Jogador::~Jogador()
{
}

void Jogador::initVariables()
{
	this->velocidade.x = 0.3f;
	this->velocidade.y = 0.3f;
	this->vidaJogador = vidaMaxima;

	this->corpo.setFillColor(sf::Color::Blue);
}

void Jogador::initPhysics()
{
	this->acceleration = 3.0f;
	this->drag = 0.87f;
	this->gravity = 4.f;
}

const sf::FloatRect Jogador::getGlobalBounds() const
{
	return sprite.getGlobalBounds();
}

void Jogador::move(const float dir_x, const float dir_y)
{
	//Acceleration
	this->velocidade.x += dir_x * this->acceleration;

	//Limit velocity
	if (std::abs(this->velocidade.x) > this->velocidadeMax) {
		this->velocidade.x = this->velocidadeMax * ((this->velocidade.x < 0.f) ? -1.f : 1.f);
	}
}

void Jogador::update()
{
	updateMovimento();
	updatePhysics();
}

void Jogador::updatePhysics()
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

void Jogador::updateMovimento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->move(-1.0f, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->move(1.f, 0);
	}
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		corpo.move(-velocidade.x, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		corpo.move(velocidade.x, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		corpo.move(0, -velocidade.y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		corpo.move(0, velocidade.y);
	}
	*/
}
