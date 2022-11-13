#include "MenuFases.h"

MenuFases::MenuFases(float widht, float height) : MenuBase(2, widht, height)
{
	if (!font.loadFromFile("arial.ttf")) {
		//handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Fase 1");
	menu[0].setPosition(sf::Vector2f(widht / 2, height / (2 + 1) * 1));
	botoes[0].setPosition(sf::Vector2f(widht / 2, height / (2 + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Fase 2");
	menu[1].setPosition(sf::Vector2f(widht / 2, height / (2 + 1) * 2));
	botoes[1].setPosition(sf::Vector2f(widht / 2, height / (2 + 1) * 2));
}

MenuFases::~MenuFases()
{
}

void MenuFases::Update(int& aux) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		MoveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		MoveDown();
	}
	for (int i = 0; i < 2; i++) {
		if (botoes[i].getGlobalBounds().contains(pGraphics->getJanela()->mapPixelToCoords(sf::Mouse::getPosition(*pGraphics->getJanela())))) {
			menu[selectedItemIndex].setFillColor(sf::Color::Black);
			menu[i].setFillColor(sf::Color::Red);
			selectedItemIndex = i;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (selectedItemIndex == 0) {
					printf("botao 1");
					aux = 2;
				}
				else if (selectedItemIndex == 1) {
					printf("botao 2");
					aux = 4;
				}
			}
		}
	}
}

void MenuFases::draw(sf::RenderWindow& window)
{
	sf::View view;
	pGraphics->getJanela()->setView(view);

	for (int i = 0; i < 2; i++) {
		window.draw(botoes[i].getCorpo());
		window.draw(menu[i]);
	}
}

void MenuFases::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MenuFases::MoveDown()
{
	if (selectedItemIndex + 1 < 2) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}