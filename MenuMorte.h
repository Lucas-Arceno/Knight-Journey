#pragma once
#include "MenuBase.h"

class MenuMorte : public MenuBase
{
private:

public:
	MenuMorte(float widht, float height);
	~MenuMorte();

	void updateEstado(int& aux);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void update();
};

