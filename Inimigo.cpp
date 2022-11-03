#include "Inimigo.h"
#include <cmath>

Inimigo::Inimigo(Jogador* pJogador,sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(posicao, tamanho), pJogador(nullptr)
{
	this->corpo.setFillColor(sf::Color::Green);
	this->pJogador = pJogador;
}

Inimigo::~Inimigo()
{
}
