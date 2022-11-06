#include "Projetil.h"
#include <iostream>
using namespace std;

Projetil::Projetil(sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(2, posicao, tamanho) {
	this->corpo.setFillColor(sf::Color::Red);
}

Projetil::~Projetil() {

}

// Redundante 
void Projetil::update()
{
}

// Redundante 
void Projetil::updateMovimento()
{
}

void Projetil::updateProjetil(float posX, float posY, float JposX, float JposY) {
	updateMovimentoProjetil(posX, posY, JposX, JposY);
}

void Projetil::updateMovimentoProjetil(float posX, float posY, float JposX, float JposY) {
	if (colisaoProjetil) { // Reseta o projetil
		corpo.setPosition(sf::Vector2f(posX, posY));
		colisaoProjetil = 0;
		contTempVida = 0;
		// cout << "posicao x" << posX << "posicao y" << posY << endl;
	}
	else {
		cout << "JOGADOR x e y :" << JposX << " " << JposY << " MORCEGO x e y :" << posX << " " << posY << endl;
		Direcao.x = fabs(posX - JposX);
		Direcao.y = fabs(posY - JposY);
		corpo.move(0.01f * Direcao);
		contTempVida++;
	}
	if (contTempVida >= 100) {
		colisaoProjetil = 1;
	}
}