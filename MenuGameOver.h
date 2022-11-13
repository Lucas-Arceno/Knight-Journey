#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"

class MenuGameOver
{
private:
	int selectedItemIndex;

	GerenciadorGrafico* pGraphics;

	sf::Font font;
	sf::RectangleShape botoes[2];
	sf::Text menu[2];
public:
	MenuGameOver(float widht, float height);
	~MenuGameOver();

	void Update(int& aux);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
};

