#pragma once
#include "Obstaculo.h"
#include "Jogador.h"

class Portal : public Obstaculo
{
private:
	Jogador* pJogador;
	sf::Vector2f destino;
public:
	Portal(Jogador* pJogador, sf::Vector2f(destino), sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(150.f, 50.f));
	~Portal();
	void update();
	void updateMovimento();
};

