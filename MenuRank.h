#pragma once
#include "MenuBase.h"
#include "Save.h"

class MenuRank : public MenuBase
{
private:
	Save saves;
	vector<info> infos;
	sf::Text placar;

public:
	MenuRank(float widht, float height);
	~MenuRank();

	void updateEstado(int& aux);
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void update();
};

