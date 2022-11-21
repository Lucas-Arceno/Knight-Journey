#pragma once
#include "MenuBase.h"

namespace Menus{
	class MenuEscolhaOnline : public MenuBase
	{
	private:

	public:
		MenuEscolhaOnline(float widht, float height);
		~MenuEscolhaOnline();

		void updateEstado(int& aux);
		void draw(sf::RenderWindow& window);
		void MoveUp();
		void MoveDown();
		void update();
	};

}

