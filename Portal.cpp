#include "Portal.h"

Portal::Portal(Jogador* pJogador,sf::Vector2f(destino), sf::Vector2f posicao, sf::Vector2f tamanho) : Obstaculo(7, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/portal.png");
	this->corpo.setTexture(&texture);
	this->pJogador = pJogador;
	this->destino = destino;
}

Portal::~Portal()
{
}

void Portal::update()
{
	updateMovimento();
	updatePhysics();

	if (this->corpo.getGlobalBounds().intersects(pJogador->getCorpoEspada().getGlobalBounds())) {
		this->corpo.setPosition(-1441.f, 421.f);
	}

	if (this->corpo.getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds())) {
		pJogador->setPosition(destino.x, destino.y);
	}
}

void Portal::updateMovimento()
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
