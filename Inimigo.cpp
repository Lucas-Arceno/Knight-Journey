#include "Inimigo.h"
#include <cmath>

Entidades::Personagens::Inimigos::Inimigo::Inimigo(int id, std::list<Entidades::Personagens::Jogadores::Jogador*>* Jogadores,sf::Vector2f posicao, sf::Vector2f tamanho) : Entidades::Personagens::Personagem(id, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::Green);
	this->pJogadores = Jogadores;
	cont_mov = 0;
	
	// Inicia o inimigo com a dire��o do movimento aleatorio.
	dir_mov = rand() % 2;
		if (dir_mov == 1) {
			dir_mov = -1; // esquerda
		}
		else{
			dir_mov = 1; // direita
		}
}

Entidades::Personagens::Inimigos::Inimigo::~Inimigo()
{
}

// Fun��o para movimento aleatorio dos inimigos
void Entidades::Personagens::Inimigos::Inimigo::randomMovimento()
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

void Entidades::Personagens::Inimigos::Inimigo::reagirDano()
{
	// Contador para o frame de invulnerabilidade
	if (iFrame > 0) {
		iFrame++;
		if (iFrame > 30) {
		iFrame = 0;
		}
	}
	for (auto const& pJogador : *pJogadores)
	{
		if (pJogador->espadaP->getEspadaProjetilGlobal().intersects(this->getCorpo().getGlobalBounds())) {
			if (iFrame == 0) {
				this->giveDano(1);
				iFrame++;
			}
			//verifica se morto
			if (this->vida <= 0) {
				pJogador->operator++();
				this->isVivo = false;
				this->update();
			}
		}
	}
}

void Entidades::Personagens::Inimigos::Inimigo::updateDano(int dano) {
	for (auto const& pJogador : *pJogadores) {
		if (!pJogador->isInvencivel()) {
			pJogador->operator-(dano);
			printf("vida %d", pJogador->getVida());
		}
	}
}