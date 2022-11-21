#include "MenuMorte.h"

MenuMorte::MenuMorte(float widht, float height) : MenuBase(2, widht, height)
{
	if (!font.loadFromFile("unispace bd.ttf")) {
		//handle error
	}

	background.setSize(sf::Vector2f(1600, 960));
	backgroundTexture.loadFromFile("assets/teste333.jpg");
	background.setTexture(&backgroundTexture);
	background.setPosition(sf::Vector2f(0, -100));
	background.setScale(1.0f, 1.3f);

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Salvar");
	menu[0].setPosition(sf::Vector2f(widht / 2, height / (2 + 1) * 1));
	botoes[0].setPosition(sf::Vector2f(widht / 2, height / (2 + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Sair");
	menu[1].setPosition(sf::Vector2f(widht / 2, height / (2 + 1) * 2));
	botoes[1].setPosition(sf::Vector2f(widht / 2, height / (2 + 1) * 2));

	pontPlayers = 0;
}

MenuMorte::~MenuMorte()
{
}

void MenuMorte::updateEstado(int& aux) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		MoveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		MoveDown();
	}
	for (int i = 0; i < 2; i++) {
		if (botoes[i].getGlobalBounds().contains(pGrafico->getJanela()->mapPixelToCoords(sf::Mouse::getPosition(*pGrafico->getJanela())))) {
			menu[selectedItemIndex].setFillColor(sf::Color::Black);
			menu[i].setFillColor(sf::Color::Red);
			botoes[i].isPressed(true);
			selectedItemIndex = i;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (selectedItemIndex == 0) {
					printf("%d \n", pontPlayers);
					saves.savePontos(pontPlayers, 0);
					exit(1);
				}
				else if (selectedItemIndex == 1) {
					printf("botao 2");
					exit(1);
				}
			}
		}
		else {
			botoes[i].isPressed(false);
		}
	}
}

void MenuMorte::draw(sf::RenderWindow& window)
{
	sf::View view;
	pGrafico->getJanela()->setView(view);

	window.draw(background);

	for (int i = 0; i < 2; i++) {
		window.draw(botoes[i].getCorpo());
		window.draw(menu[i]);
	}
}

void MenuMorte::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MenuMorte::MoveDown()
{
	if (selectedItemIndex + 1 < 2) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MenuMorte::update() {

}

void MenuMorte::setPontPlayers(int pont)
{
	pontPlayers += pont;
}
