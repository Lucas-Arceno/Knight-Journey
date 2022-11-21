#pragma once
#include "MenuBase.h"

namespace Menus {
	class MenuFases : public MenuBase
	{
	private:

	public:
		MenuFases(float widht, float height);
		~MenuFases();

		void updateEstado(int& aux);
		void draw(sf::RenderWindow& window);
		void MoveUp();
		void MoveDown();
		void update();
	};

}

