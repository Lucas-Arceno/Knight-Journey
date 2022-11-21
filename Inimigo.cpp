#include "Inimigo.h"
#include <cmath>

Entidades::Personagens::Inimigos::Inimigo::Inimigo(int id, std::list<Entidades::Personagens::Jogadores::Jogador*>* Jogadores,sf::Vector2f posicao, sf::Vector2f tamanho) : Entidades::Personagens::Personagem(id, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::Green);
	this->pJogadores = Jogadores;
	cont_mov = 0;
	
	// Inicia o inimigo com a direção do movimento aleatorio.
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


// Função que atualiza o dano recebido ou dado ao jogador
void Entidades::Personagens::Inimigos::Inimigo::updateDano(int dano)
{
	
	// Contador para o frame de invulnerabilidade
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

	for (auto const& pJogador : *pJogadores)
	{
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
			if (this->vida <= 0) {
				pJogador->givePontuacao(5);
			}
		}
		// Dano do inimigo no player
		else if (this->getCorpo().getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds()) && pJogador->getInvFrame() == 0) {
			printf("dano player %d \n", pJogador->getVida());
			pJogador->operator-(dano);
			//pJogador->giveDano(dano);
			//pJogador->setInvFrame();
		}
	}
}


// Função para movimento aleatorio dos inimigos
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
