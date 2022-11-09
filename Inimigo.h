#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem
{
protected:
	Jogador* pJogador;
	int vida;
public:
	Inimigo(int id, Jogador* pJogador,sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
	virtual ~Inimigo(); 

	void verificaDano();
	virtual void update() = 0;
	virtual void updateMovimento() = 0;
};

