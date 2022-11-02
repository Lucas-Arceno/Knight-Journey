#pragma once
#include "Entidade.h"

class Jogador : public Entidade
{
private:
	sf::Sprite sprite;
	sf::Vector2f velocidade;
	const int velocidadeMax;
	const int velocidadeMin;
	const int velocidadeMaxY;
	const int vidaMaxima;
	static int vidaJogador;

public:
	Jogador(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
	~Jogador();

	void initVariables();

	const sf::FloatRect getGlobalBounds() const;

	void update();
	void updateMovimento();
};

