#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include "Botao.h"
#include "Ente.h"

class MenuBase : public Ente
{
protected:
	int selectedItemIndex;
	sf::Font font;

	sf::RectangleShape background;
	sf::Texture backgroundTexture;

	Botao *botoes;
	sf::Text *menu;
public:
	MenuBase(int numItems, float widht, float height);
	virtual ~MenuBase();

	virtual void updateEstado(int& aux) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;
	virtual void update() = 0;
};

