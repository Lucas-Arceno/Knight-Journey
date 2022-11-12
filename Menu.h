#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
private:
	int selectedItemIndex;

	GerenciadorGrafico* pGraphics;

	sf::Font font;
	sf::RectangleShape botoes[MAX_NUMBER_OF_ITEMS];
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
public:
	Menu(float widht, float height);
	~Menu();

	void Update(int& aux);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
};

