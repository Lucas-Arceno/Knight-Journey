#pragma once
#include "GerenciadorGrafico.h"

class Ente
{
protected:
	const int ID;
	GerenciadorGrafico* pGraphics;
public:
	Ente(int id = -1);
	~Ente();
	void seImprime(sf::RectangleShape corpo);
	virtual void update() = 0;
};

