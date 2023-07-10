#include "MenuBase.h"

Menus::MenuBase::MenuBase(int numItems, float widht, float height) : botoes(), menu(), selectedItemIndex(0)/*, pGrafico(pGrafico->getGerenciadorGrafico())*/ {
	if (!font.loadFromFile("arial.ttf")) {
		//handle error
	}

	botoes = new Botao[numItems];
	menu = new sf::Text[numItems];
	selectedItemIndex = 0;
}
Menus::MenuBase::~MenuBase()
{
}
