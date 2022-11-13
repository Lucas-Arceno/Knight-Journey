#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include "Botao.h"

class MenuBase
{
protected:
	int selectedItemIndex;
	sf::Font font;
	GerenciadorGrafico* pGraphics;

	sf::RectangleShape background;
	sf::Texture backgroundTexture;

	Botao *botoes;
	sf::Text *menu;
public:
	MenuBase(int numItems, float widht, float height);
	virtual ~MenuBase();

	virtual void Update(int& aux) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;
};

