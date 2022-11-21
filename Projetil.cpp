#include "Projetil.h"
#include <iostream>
using namespace std;

Entidades::Projetil::Projetil(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(23, posicao, tamanho) {
	this->corpo.setFillColor(sf::Color::Red);
	this->pJogadores = pJogadores;
	pJogador = NULL;
}


Entidades::Projetil::~Projetil() {

}

 
void Entidades::Projetil::update()
{
	updatePhysics();
	updateMovimento();
}


void Entidades::Projetil::updateMovimento()
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


sf::Vector2f Entidades::Projetil::normalizedVector(sf::Vector2f direcao)
{
	float m = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
	
	sf::Vector2f vetorNormalizado;

	vetorNormalizado.x = direcao.x / m;
	vetorNormalizado.y = direcao.y / m;

	return vetorNormalizado;
}

void Entidades::Projetil::updateProjetil(float posX, float posY) {
	if (colisaoProjetil == true) { 
		corpo.setPosition(sf::Vector2f(posX, posY));

		if (pJogadores->front()->getCorpo().getPosition().x > pJogadores->back()->getCorpo().getPosition().x) {
			pJogador = pJogadores->back();
		}
		else {
			pJogador = pJogadores->front();
		}

		posJogador = pJogador->getCorpo().getPosition();
		Direcao.x = -(posX - posJogador.x);
		Direcao.y = -(posY - posJogador.y);
		Direcao = normalizedVector(Direcao);

		colisaoProjetil = false;
		contTempVida = 0;
	}
	else {

		if (pJogadores->front()->getCorpo().getPosition().x > pJogadores->back()->getCorpo().getPosition().x) {
			pJogador = pJogadores->back();
		}
		else {
			pJogador = pJogadores->front();
		}

		if (fabs(pJogador->getCorpo().getPosition().x - this->corpo.getPosition().x) > 300 || fabs(pJogador->getCorpo().getPosition().y - this->corpo.getPosition().y) > 1000) {
			this->corpo.setPosition(sf::Vector2f(5000.f, 2000.f));
		}
		corpo.setPosition(corpo.getPosition() + 10.0f * Direcao); // Movimento da bala, velocidade constante.
		if (this->corpo.getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds())) {
			pJogador->giveDano(1);
			this->corpo.setPosition(sf::Vector2f(5000.f, 2000.f));
		}
		contTempVida++;
	}
	if (contTempVida >= 200) {
		colisaoProjetil = true;
	}
}

