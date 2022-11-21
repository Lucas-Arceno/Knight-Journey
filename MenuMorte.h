#pragma once
#include "MenuBase.h"
#include "Save.h"

class MenuMorte : public MenuBase
{
private:
	int pontPlayers;
	Save saves;

public:
	MenuMorte(float widht, float height);
	~MenuMorte();

	void updateEstado(int& aux);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void update();

	void setPontPlayers(int pont);
};

