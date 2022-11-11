#include "Personagem.h"

Personagem::Personagem(int id, sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(id, posicao, tamanho)
{
	this->vida = 100;
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

