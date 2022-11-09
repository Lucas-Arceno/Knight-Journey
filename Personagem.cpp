#include "Personagem.h"

Personagem::Personagem(int id, sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(id, posicao, tamanho)
{
	this->vida = 100;
}

Personagem::~Personagem()
{
}

void Personagem::setVida(int dano) {
	this->vida = this->vida - dano;
}

int Personagem::getVida() {
	return this->vida;
}