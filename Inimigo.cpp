#include "Inimigo.h"
#include <cmath>

Inimigo::Inimigo(int id, Jogador* pJogador,sf::Vector2f posicao, sf::Vector2f tamanho) : Personagem(2, posicao, tamanho), pJogador(nullptr)
{
	this->vida = 100;
	this->corpo.setFillColor(sf::Color::Green);
	this->pJogador = pJogador;
	
	dir_mov = rand() % 2;
		if (dir_mov == 1) {
			dir_mov = -1; // esquerda
		}
		else{
			dir_mov = 1; // direita
		}
}

Inimigo::~Inimigo()
{
}

void Inimigo::updateDano(int dano)
{
	
	// Dano do player no inimigo
	if (pJogador->getCorpoEspada().getGlobalBounds().intersects(this->getCorpo().getGlobalBounds())) {
		printf("%d\n", this->getVida());
		if (this->getVida() <= 0) {
			this->setCorpoPosicao(sf::Vector2f(0.0f, 6000.f));
		}
		this->giveDano(25);
	}

	// Dano do inimigo no player
	else if (this->getCorpo().getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds())) {
		printf("dano player %d\n", pJogador->getVida());
		pJogador->giveDano(dano);
	}
}

void Inimigo::randomMovimento()
{
	if (dir_mov == 1) {
		this->corpo.move(1.f, 0.0f);
	}
	else {
		this->corpo.move(-1.f, 0.0f);
	}

	if (cont_mov > 300) {
		cont_mov = rand() % 50;
		dir_mov = -(dir_mov);
	}
	cont_mov++;
}
