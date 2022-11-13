#pragma once
#include "MenuBase.h"

class MenuFases : public MenuBase
{
private:

public:
	MenuFases(float widht, float height);
	~MenuFases();

	void Update(int& aux);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
};

