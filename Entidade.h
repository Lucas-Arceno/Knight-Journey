#pragma once
#include <SFML/Graphics.hpp>
#include "Colisao.h"

class Entidade
{
protected:
	const int ID;
	int vida;

	sf::Vector2f velocidade;
	const int velocidadeMax;
	const int velocidadeMin;

	sf::RectangleShape corpo;
	sf::Vector2f posicao;
	sf::Vector2f tamanho;

	sf::Texture texture;

	//Physics
	float acceleration;
	float drag;
	float gravity;
	const int velocidadeMaxY;

public:
	Entidade(int id = 0, sf::Vector2f posicao = sf::Vector2f(0.f,0.f),sf::Vector2f tamanho = sf::Vector2f(0.f, 0.f));
	~Entidade();

	void setVida(int vida);
	int getVida();

	void setCorpoPosicao(sf::Vector2f pos);

	void initPhysics();

	Colisao GetColisao() { return Colisao(corpo); }

	const int getID() { return ID; }

	virtual void update() = 0;
	void updatePhysics();
	virtual void updateMovimento() = 0;

	void setPosicao(sf::Vector2f pos);
	const sf::RectangleShape getCorpo();
	sf::Vector2f getPosicao() const;
	sf::Vector2f getTamanho() const;
};

