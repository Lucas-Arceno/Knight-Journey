#include "Inimigo.h"
#include <cmath>

Inimigo::Inimigo(int id, Jogador* pJogador,sf::Vector2f posicao, sf::Vector2f tamanho) : Personagem(2, posicao, tamanho), pJogador(nullptr)
{
	this->corpo.setFillColor(sf::Color::Green);
	this->pJogador = pJogador;
	cont_mov = 0;
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
	if (iFrame > 0) {
		iFrame++;
		if (iFrame > 30) {
			iFrame = 0;
		}
	}

	//Verifica se morto
	if (this->getVida() <= 0) {
		this->setCorpoPosicao(sf::Vector2f(0.0f, 6000.f));
	}

	// Dano do player no inimigo
	if (pJogador->espadaP->getEspadaProjetilGlobal().intersects(this->getCorpo().getGlobalBounds())) {
		printf("%d\n", this->getVida());
		if (iFrame == 0) {
			this->giveDano(1);
			this->isVivo = false;
			iFrame++;
			printf("hit : %d\n", this->getVida());
		}
		//int pont = 1;
		//	if (this->id == 5) { pont = 2; }
		pJogador->givePontuacao(1);
	}
	// Dano do inimigo no player
	else if (this->getCorpo().getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds()) && pJogador->getInvFrame() == 0) {
		printf("dano player %d \n", pJogador->getVida());
		pJogador->giveDano(dano);
		pJogador->setInvFrame();
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

	if (cont_mov > 250) {
		cont_mov = rand() % 50;
		dir_mov = -(dir_mov);
	}
	cont_mov++;
}
