#pragma once
#include "GerenciadorGrafico.h"
#include <list>

class Ente
{
protected:
	const int ID;
	GerenciadorGrafico* pGrafico;
public:
	Ente(int id = -1);
	~Ente();
	void seImprime(sf::RectangleShape corpo);
	virtual void update() = 0;
};

