#pragma once
#include "Obstaculo.h"

class Caixa : public Obstaculo
{
private:
public:
	Caixa(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(30.f, 50.f));
	~Caixa();

	void update();
	void updateMovimento();
};

