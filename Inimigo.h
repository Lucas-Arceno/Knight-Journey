#pragma once
#include "Entidade.h"
#include "Jogador.h"

class Inimigo : public Entidade
{
private:
	Jogador* pJogador;
public:
	Inimigo(Jogador* pJogador,sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
	~Inimigo(); 

	void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);

	void update();
	void updateMovimento();
};

