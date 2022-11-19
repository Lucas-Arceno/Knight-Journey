#pragma once
#include "Obstaculo.h"

class Espinhos : public Obstaculo
{
private:
	int nivelAfiado;
public:
	Espinhos(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(150.f, 200.f));
	~Espinhos();

	const int getNivelAfiado();

	void update();
	void updateMovimento();
};

