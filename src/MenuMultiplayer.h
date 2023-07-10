#pragma once
#include "MenuBase.h"

namespace Menus{
	class MenuMultiplayer : public MenuBase
	{
	private:

	public:
		MenuMultiplayer(float widht, float height);
		~MenuMultiplayer();

		void updateEstado(int& aux);
		void draw(sf::RenderWindow& window);
		void MoveUp();
		void MoveDown();
		void update();
	};

}

