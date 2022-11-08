#pragma once
#include "Entidade.h"

class Plataforma : public Entidade
{
private:

public:
	Plataforma(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(0.0f, 0.0f));
	~Plataforma();

	void update();
	void updateEmpuxo();
	void updateMovimento();
};

