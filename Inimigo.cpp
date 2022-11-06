#include "Inimigo.h"
#include <cmath>

Inimigo::Inimigo(int id, Jogador* pJogador,sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(2, posicao, tamanho), pJogador(nullptr)
{
	this->vida = 100;
	this->corpo.setFillColor(sf::Color::Green);
	this->pJogador = pJogador;
}

Inimigo::~Inimigo()
{
}

