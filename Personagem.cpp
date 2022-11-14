#include "Personagem.h"

Personagem::Personagem(int id, sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(id, posicao, tamanho)
{
	this->vida = 1;
}

Personagem::~Personagem()
{
}

void Personagem::giveDano(int dano) {
	this->vida = this->vida - dano;
}

void Personagem::setVida(int vida) {
	this->vida = vida;
}

int Personagem::getVida() {
	return this->vida;
}

//void Personagem::updateDano(int dano)
//{
////	
////	// Dano do player no inimigo
////	if (pJogador->getCorpoEspada().getGlobalBounds().intersects(this->getCorpo().getGlobalBounds())) {
////		printf("%d\n", this->getVida());
////		if (this->getVida() <= 0) {
////			this->setCorpoPosicao(sf::Vector2f(0.0f, 6000.f));
////		}
////		this->giveDano(25);
////		
////		//int pont = 1;
////		//	if (this->id == 5) { pont = 2; }
////		pJogador->givePontuacao(1);
////	}
////
////	// Dano do inimigo no player
////	else if (this->getCorpo().getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds()) && pJogador->getInvFrame() == 0) {
////		printf("dano player %d\n", pJogador->getVida());
////		pJogador->giveDano(dano);
////		pJogador->setInvFrame();
////	}
//}