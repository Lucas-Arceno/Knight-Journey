#pragma once
#include "SFML/Graphics.hpp"

class Botao
{
protected:
	sf::RectangleShape forma;
	sf::Texture botaoNormal;
	sf::Texture botaoPress;
public:
	Botao(const char* path = "assets/botao.png");
	~Botao();

	sf::RectangleShape getCorpo();

	void isPressed(const bool pressionado);
	void setPosition(sf::Vector2f(pos));

	sf::FloatRect getGlobalBounds();
};

