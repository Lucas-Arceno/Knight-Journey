#pragma once
#include "MenuBase.h"

class Menu : public MenuBase
{
private:
public:
	Menu(float widht, float height);
	~Menu();

	void Update(int& aux);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
};

