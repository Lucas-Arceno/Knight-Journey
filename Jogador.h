#pragma once
#include "Entidade.h"

class Jogador : public Entidade
{
private:
	sf::Sprite sprite;

	sf::Vector2f velocidade;
	const int velocidadeMax;
	const int velocidadeMin;

	const int vidaMaxima;
	static int vidaJogador;

	//Physics
	float acceleration;
	float drag;
	float gravity;
	const int velocidadeMaxY;

public:
	Jogador(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
	~Jogador();

	void initVariables();
	void initPhysics();

	const sf::FloatRect getGlobalBounds() const;

	void move(const float dir_x, const float dir_y);


	void setPosition(const float x, const float y);
	void resetVelocity();

	void update();
	void updatePhysics();
	void updateMovimento();
};

