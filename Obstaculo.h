#pragma once
#include "Entidade.h"

class Obstaculo : public Entidade
{
protected:

public:
	Obstaculo(int id = 1, sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
	virtual ~Obstaculo();

	virtual void update() = 0;
	virtual void updateMovimento() = 0;
};

 