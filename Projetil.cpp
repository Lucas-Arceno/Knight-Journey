#include "Projetil.h"
#include <iostream>
using namespace std;

Projetil::Projetil(sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(posicao, tamanho) {
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

void Projetil::updateProjetil(float posX, float posY){
	updateMovimentoProjetil(posX, posY);
}

void Projetil::updateMovimentoProjetil(float posX, float posY) {
	if (colisaoProjetil) { // Reseta o projetil
		corpo.setPosition(sf::Vector2f(posX, posY));
		cout << "posicao x" << posX << "posicao y" << posY << endl;
	}
	else {

	}
}