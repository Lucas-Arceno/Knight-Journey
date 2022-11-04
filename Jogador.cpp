#include "Jogador.h"

int Jogador::vidaJogador = 100;

Jogador::Jogador(sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(posicao, tamanho) ,vidaMaxima(100)
{
	initVariables();
	initPhysics();
}

Jogador::~Jogador()
{
}

void Jogador::initVariables()
{
	this->coldownPulo = false;
	this->vidaJogador = vidaMaxima;
	this->corpo.setFillColor(sf::Color::Blue);
}

const sf::FloatRect Jogador::getGlobalBounds() const
{
	return corpo.getGlobalBounds();
}

void Jogador::collisionWindow(unsigned int y)
{
	
	if (this->corpo.getPosition().y + 50 > y) {
		resetVelocity();
		setPosition(corpo.getPosition().x, y - 50);
	}

	/*if (getGlobalBounds().top + getGlobalBounds().height > y) {
		resetVelocity();
		setPosition(
			getGlobalBounds().left, y - getGlobalBounds().height
		);
	}*/
}

void Jogador::setPosition(const float x, const float y)
{
	this->corpo.setPosition(x, y);
}

void Jogador::resetVelocity()
{
	this->velocidade.y = 0.f;
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

void Jogador::updateMovimento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->move(-1.0f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->move(1.f, 0.f);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && coldownPulo == true)){
	}
}
