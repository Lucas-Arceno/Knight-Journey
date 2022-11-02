#pragma once
#include <SFML/Graphics.hpp>

class Entidade
{
protected:
	sf::RectangleShape corpo;
	sf::Vector2f posicao;
	sf::Vector2f tamanho;

public:
	Entidade(sf::Vector2f posicao = sf::Vector2f(0.f,0.f),sf::Vector2f tamanho = sf::Vector2f(0.f, 0.f));
	~Entidade();

	void setPosicao(sf::Vector2f pos);
	const sf::RectangleShape getCorpo();
	sf::Vector2f getPosicao() const;
	sf::Vector2f getTamanho() const;

	virtual void update() = 0;
};

