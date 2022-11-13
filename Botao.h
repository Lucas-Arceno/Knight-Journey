#pragma once
#include "SFML/Graphics.hpp"

class Botao
{
protected:
	sf::RectangleShape forma;
	sf::Texture Texture;
public:
	Botao(const char* path = "assets/botao.png");
	~Botao();

	sf::RectangleShape getCorpo();
	void setPosition(sf::Vector2f(pos));

	sf::FloatRect getGlobalBounds();
};

