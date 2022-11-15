#pragma once
#include "Obstaculo.h"

class Teia : public Obstaculo
{
private:
public:
	Teia(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(30.f, 50.f));
	~Teia();

	void update();
	void updateMovimento();
};

