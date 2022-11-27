#include "Rei.h"
#include <iostream>

Entidades::Personagens::Inimigos::Rei::Rei(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao, sf::Vector2f tamanho) : Entidades::Personagens::Inimigos::Inimigo(24, pJogadores, posicao, tamanho), vidaMaxima(1000)
{
	this->corpo.setFillColor(sf::Color::Magenta);
	this->vida = vidaMaxima;
}

Entidades::Personagens::Inimigos::Rei::~Rei() {

}

void Entidades::Personagens::Inimigos::Rei::update() {
	updateMovimento();
	updatePhysics();

	// cooldown do pulo
	cont_CD++;
	if (cont_CD > 200) {
		cooldownPulo = false;
		cont_CD = 0;
	}
}

void Entidades::Personagens::Inimigos::Rei::updateMovimento() {
	sf::Vector2f posInimigo = corpo.getPosition();
	sf::Vector2f posJogador;

	for (auto const& pJogador : *pJogadores)
	{
		if (pJogador == pJogadores->front()) {
			posJogador = pJogador->getCorpo().getPosition();
		}
		else {
			if (pJogador->getCorpo().getPosition().x < posJogador.x) {
				posJogador = pJogador->getCorpo().getPosition();
			}
		}
	}

	if (fabs(posJogador.x - posInimigo.x) <= 400 && fabs(posJogador.y - posInimigo.y) <= 400) {
		persegueJogador(posJogador, posInimigo);
	}
	if (fabs(posJogador.x - posInimigo.x) <= 200 && fabs(posJogador.y - posInimigo.y) <= 100) {
		ataqueJogador(posJogador, posInimigo);
	}
}

void Entidades::Personagens::Inimigos::Rei::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo) {
	if (posJogador.x - posInimigo.x > 0.0f) {
		corpo.move(2.f, 0.0f);
	}
	else {
		corpo.move(-2.f, 0.0f);
	}
}

// O ataque do rei é um super pulo
void Entidades::Personagens::Inimigos::Rei::ataqueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo) {
	
	if (cooldownPulo == false) {
		this->velocidade.y -= 40 * this->gravity;
		cooldownPulo = true;
	}
}

void Entidades::Personagens::Inimigos::Rei::reagir() {

}