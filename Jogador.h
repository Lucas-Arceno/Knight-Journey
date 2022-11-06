#pragma once
#include "Entidade.h"
#include <iostream>

class Jogador : public Entidade
{
private:
	sf::Sprite sprite;

	sf::RectangleShape Espada;

	bool coldownPulo;

	const int vidaMaxima;
	static int vidaJogador;

public:
	//Constructors
	Jogador(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
	~Jogador();

	//Init variaveis
	void initVariables();

	//Pegar posicoes 
	const sf::FloatRect getGlobalBounds() const;
	const sf::FloatRect getEspadaGlobal() const;
	void setEspadaPosicao(sf::Vector2f(newPosicao));

	//Pulo manager
	void setColdownPulo(bool cd) { this->coldownPulo = cd; }

	//Colisao Janela
	void collisionWindow(unsigned int y);

	//Movimentacao Jogador
	void move(const float dir_x, const float dir_y);
	void setPosition(const float x, const float y);

	//Espada
	sf::RectangleShape getCorpoEspada();

	//Ataque
	void atacarDir();
	void atacarEsq();

	//Velocidade
	void resetVelocity();
	void setVelocityX(float vel_x);
	void setVelocityY(float vel_y);

	//Updates
	void update();
	void updateMovimento();
};

