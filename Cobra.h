#pragma once
#include "Inimigo.h"
class Cobra : public Inimigo
{
private:

public:
	Cobra(Jogador* pJogador, sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
	virtual ~Cobra();

	void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);

	void update();
	void updateMovimento();
};

