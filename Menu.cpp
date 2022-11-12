#include "Menu.h"

Menu::Menu(float widht, float height) : pGraphics(pGraphics->getGerenciadorGrafico())
{
	if (!font.loadFromFile("arial.ttf")) {
		//handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(widht / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	botoes[0].setSize(sf::Vector2f(150.f, 100.f));
	botoes[0].setFillColor(sf::Color::Green);
	botoes[0].setPosition(sf::Vector2f(widht / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(widht / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	botoes[1].setSize(sf::Vector2f(150.f, 100.f));
	botoes[1].setFillColor(sf::Color::Green);
	botoes[1].setPosition(sf::Vector2f(widht / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(widht / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	botoes[2].setSize(sf::Vector2f(150.f, 100.f));
	botoes[2].setFillColor(sf::Color::Green);
	botoes[2].setPosition(sf::Vector2f(widht / 2 , height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;

}

Menu::~Menu()
{
}

void Menu::Update(int& aux) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		MoveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		MoveDown();
	}
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		if (botoes[i].getGlobalBounds().contains(pGraphics->getJanela()->mapPixelToCoords(sf::Mouse::getPosition(*pGraphics->getJanela())))) {
			menu[selectedItemIndex].setFillColor(sf::Color::White);
			menu[i].setFillColor(sf::Color::Red);
			selectedItemIndex = i;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (selectedItemIndex == 0) {
					printf("botao 1");
					aux = 0;
				}
				else if (selectedItemIndex == 1) {
					printf("botao 2");
				}
				else if (selectedItemIndex == 2) {
					printf("botao 3");
				}
			}
		}
	}
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(botoes[i]);
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
