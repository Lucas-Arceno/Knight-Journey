#pragma once
#include "Entidade.h"

class Jogador : public Entidade
{
private:
	sf::Sprite sprite;

	const int vidaMaxima;
	static int vidaJogador;

public:
	Jogador(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
	~Jogador();

	void initVariables();

	const sf::FloatRect getGlobalBounds() const;

	void collisionWindow(unsigned int y);

	void move(const float dir_x, const float dir_y);

	void setPosition(const float x, const float y);
	void resetVelocity();

	void update();
	void updateMovimento();
};

