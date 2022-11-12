#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"

class MenuFases
{
private:
	int selectedItemIndex;

	GerenciadorGrafico* pGraphics;

	sf::Font font;
	sf::RectangleShape botoes[2];
	sf::Text menu[2];
public:
	MenuFases(float widht, float height);
	~MenuFases();

	void Update(int& aux);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
};

