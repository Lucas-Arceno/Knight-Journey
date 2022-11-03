#pragma once
#include <SFML/Graphics.hpp>

class Entidade
{
protected:
	sf::Vector2f velocidade;
	const int velocidadeMax;
	const int velocidadeMin;

	sf::RectangleShape corpo;
	sf::Vector2f posicao;
	sf::Vector2f tamanho;

	//Physics
	float acceleration;
	float drag;
	float gravity;
	const int velocidadeMaxY;

public:
	Entidade(sf::Vector2f posicao = sf::Vector2f(0.f,0.f),sf::Vector2f tamanho = sf::Vector2f(0.f, 0.f));
	~Entidade();

	void initPhysics();

	virtual void update() = 0;
	void updatePhysics();
	virtual void updateMovimento() = 0;

	void setPosicao(sf::Vector2f pos);
	const sf::RectangleShape getCorpo();
	sf::Vector2f getPosicao() const;
	sf::Vector2f getTamanho() const;
};

