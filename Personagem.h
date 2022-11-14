#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
protected:
	int vida;
public:
	Personagem(int id = 0, sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(0.f, 0.f));
	~Personagem();

	void giveDano(int dano);
	void setVida(int vida);
	int getVida();

	//void updateDano(int dano);
};

