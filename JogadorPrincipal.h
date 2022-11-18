#pragma once
#include "Jogador.h"

class JogadorPrincipal : public Jogador
{
private:

public:
	JogadorPrincipal(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
	~JogadorPrincipal();
	void updateMovimento();
};

