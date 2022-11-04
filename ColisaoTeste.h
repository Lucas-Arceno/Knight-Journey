#pragma once
#include "GerenciadorGrafico.h"

class ColisaoTeste
{
private:
public:
	ColisaoTeste();
	~ColisaoTeste();
	void checkColisao(sf::RectangleShape corpo1, sf::RectangleShape corpo2);
};

