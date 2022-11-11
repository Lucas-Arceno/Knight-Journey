#include "Jogador.h"

int Jogador::vidaJogador = 100;

Jogador::Jogador(sf::Vector2f posicao, sf::Vector2f tamanho) : Personagem(0,posicao, tamanho) ,vidaMaxima(100)
{
	initVariables();
	initPhysics();
}

Jogador::~Jogador()
{
}

void Jogador::initVariables()
{
	this->vida = 500;

	//Personagem e afins
	this->coldownPulo = false;
	this->vidaJogador = vidaMaxima;
	this->corpo.setFillColor(sf::Color::Blue);

	//Textura e cor
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/knight.png");
	this->corpo.setTexture(&texture);

	//Espada e afins
	this->Espada.setSize(sf::Vector2f(70.f, 10.f));
	this->Espada.setPosition(sf::Vector2f(0.0f, 5000.0f));
	this->Espada.setFillColor(sf::Color::Green);
	this->Espada.setOrigin(this->Espada.getSize() / 2.0f);
}

const sf::FloatRect Jogador::getGlobalBounds() const
{
	return corpo.getGlobalBounds();
}

const sf::FloatRect Jogador::getEspadaGlobal() const
{
	return this->Espada.getGlobalBounds();
}

void Jogador::setEspadaPosicao(sf::Vector2f(newPosicao))
{
	this->Espada.setPosition(newPosicao);
}

void Jogador::setPosition(const float x, const float y)
{
	this->corpo.setPosition(x, y);
}

sf::RectangleShape Jogador::getCorpoEspada()
{
	return Espada;
}

void Jogador::atacarDir()
{
	this->Espada.setPosition(this->corpo.getPosition().x + 50, this->corpo.getPosition().y);
}

void Jogador::atacarEsq()
{
	this->Espada.setPosition(this->corpo.getPosition().x - 50, this->corpo.getPosition().y);
}

void Jogador::resetVelocity()
{
	this->velocidade.y = 0.0f;
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

void Jogador::setVelocityX(float vel_x)
{
	this->velocidade.x = vel_x;
}

void Jogador::setVelocityY(float vel_y)
{
	this->velocidade.y = vel_y;
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
		this->velocidade.y -= 20.0 * this->gravity;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		atacarEsq();
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		atacarDir();
	}
}
