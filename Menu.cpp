#include "Menu.h"

Menus::Menu::Menu(float widht, float height) : MenuBase(3, widht, height)
{
	if (!font.loadFromFile("unispace bd.ttf")) {
		//handle error
	}

	background.setSize(sf::Vector2f(1600, 960));
	backgroundTexture.loadFromFile("assets/menuteste2.png");
	background.setTexture(&backgroundTexture);
	background.setPosition(sf::Vector2f(-150, 0));
	background.setScale(0.8f, 1.2f);

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Jogar");
	menu[0].setPosition(sf::Vector2f((widht / 2) - 125, (height / (3 + 1) * 1) + 320));
	botoes[0].setPosition(sf::Vector2f((widht / 2) - 150, (height / (3 + 1) * 1)+300));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString(" Ver\nRanking");
	menu[1].setPosition(sf::Vector2f((widht / 2) - 125, (height / (3 + 1) * 2) + 320));
	botoes[1].setPosition(sf::Vector2f((widht / 2) - 150, (height / (3 + 1) * 2)+300));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("Sair");
	menu[2].setPosition(sf::Vector2f((widht / 2) - 115, (height / (3 + 1) * 3) + 320));
	botoes[2].setPosition(sf::Vector2f((widht / 2) - 150, (height / (3 + 1) * 3)+300));
}

Menus::Menu::~Menu()
{
}

void Menus::Menu::updateEstado(int& aux) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		MoveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		MoveDown();
	}
	for (int i = 0; i < 3; i++) {
		if (botoes[i].getGlobalBounds().contains(pGrafico->getJanela()->mapPixelToCoords(sf::Mouse::getPosition(*pGrafico->getJanela())))) {
			menu[selectedItemIndex].setFillColor(sf::Color::Black);
			menu[i].setFillColor(sf::Color::Red);
			selectedItemIndex = i;
			botoes[i].isPressed(true);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (selectedItemIndex == 0) {
					printf("botao 1");
					aux = 3;
				}
				else if (selectedItemIndex == 1) {
					printf("botao 2");
					aux = 11;
				}
				else if (selectedItemIndex == 2) {
					printf("botao 3");
					exit(1);
				}
			}
		}
		else {
			botoes[i].isPressed(false);
		}
	}
}

void Menus::Menu::draw(sf::RenderWindow& window)
{
	sf::View view;
	pGrafico->getJanela()->setView(view);

	window.draw(background);

	for (int i = 0; i < 3; i++) {
		window.draw(botoes[i].getCorpo());
		window.draw(menu[i]);
	}
}

void Menus::Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menus::Menu::MoveDown()
{
	if (selectedItemIndex + 1 < 3) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menus::Menu::update() {

}	