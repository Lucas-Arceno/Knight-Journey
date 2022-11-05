#include "Morcego.h"

Morcego::Morcego(Jogador* pJogador, sf::Vector2f posicao, sf::Vector2f tamanho) : Inimigo(pJogador, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::White);
}

Morcego::~Morcego()
{
}

void Morcego::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	if (posJogador.x - posInimigo.x > 200.0f) {
		corpo.move(3.f, 0.0f);
	}
	else {
		corpo.move(-3.f, 0.0f);
	}
	if (posJogador.y - posInimigo.y > 200.0f) {
		corpo.move(0, 3.f);
	}
	else {
		corpo.move(0, -3.f);
	}
}

void Morcego::updateEmpuxo()
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

void Morcego::update()
{
	updateMovimento();
	updatePhysics();
	updateEmpuxo();
	projetil.update();
}

void Morcego::updateMovimento()
{
	sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) < 300 && fabs(posJogador.y - posInimigo.y) < 300) {
		persegueJogador(posJogador, posInimigo);
	}
}
