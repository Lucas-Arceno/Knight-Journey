#include "Projetil.h"
#include <iostream>
using namespace std;

Entidades::Projetil::Projetil(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao, sf::Vector2f tamanho) : ProjetilBase(23, posicao, tamanho) {
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

// Vetor unitario
// Retorna um vetor de comprimento 1
sf::Vector2f Entidades::Projetil::normalizedVector(sf::Vector2f direcao)
{
	float m = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
	
	sf::Vector2f vetorNormalizado;

	vetorNormalizado.x = direcao.x / m;
	vetorNormalizado.y = direcao.y / m;

	return vetorNormalizado;
}

void Entidades::Projetil::updateProjetil(float posX, float posY) {
	if (disparo == true) { 
		corpo.setPosition(sf::Vector2f(posX, posY));

		// O alvo se torna o jogador mais proximo
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

		disparo = false;
		tempVida = 0;
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
		// Movimento da bala, velocidade constante.
		corpo.setPosition(corpo.getPosition() + 10.0f * Direcao); 
		
		if (this->corpo.getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds())) {
			pJogador->giveDano(1);
			this->corpo.setPosition(sf::Vector2f(5000.f, 2000.f));
		}
		tempVida++;
	}
	if (tempVida >= 200) {
		disparo = true;
	}
}

void Entidades::Projetil::reagir() {
	//pJogador->giveDano(1);
}