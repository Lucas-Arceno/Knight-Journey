#pragma once
#include "GerenciadorGrafico.h"
#include "Botao.h"
#include "Ente.h"

// Os menus foram feitos com a ajuda de : www.youtube.com/watch?v=h8-Q4eu3Qt4

namespace Menus{
	class MenuBase : public Ente
	{
	protected:
		int selectedItemIndex;
		sf::Font font;

		sf::RectangleShape background;
		sf::Texture backgroundTexture;

		Botao* botoes;
		sf::Text* menu;
	public:
		MenuBase(int numItems, float widht, float height);
		virtual ~MenuBase();

		virtual void updateEstado(int& aux) = 0;
		virtual void draw(sf::RenderWindow& window) = 0;
		virtual void MoveUp() = 0;
		virtual void MoveDown() = 0;
		virtual void update() = 0;
	};

}
