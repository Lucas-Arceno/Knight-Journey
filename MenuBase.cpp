#include "MenuBase.h"

MenuBase::MenuBase(int numItems, float widht, float height) : botoes(), menu(), selectedItemIndex(0), pGraphics(pGraphics->getGerenciadorGrafico()) {
	if (!font.loadFromFile("arial.ttf")) {
		//handle error
	}

	botoes = new Botao[numItems];
	menu = new sf::Text[numItems];
	selectedItemIndex = 0;
}
MenuBase::~MenuBase()
{
}