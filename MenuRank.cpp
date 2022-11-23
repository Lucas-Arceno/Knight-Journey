#include "MenuRank.h"

Menus::MenuRank::MenuRank(float width, float height) : MenuBase(1, width, height)
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
	menu[0].setString("Voltar");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (2 + 1) * 1));
	botoes[0].setPosition(sf::Vector2f(width / 2, height / (2 + 1) * 1));
	
	infos = saves.getPontos();

	for (int i = 0; i < infos.size(); i++) {
		printf("%d infosPT %d \n", i+1, infos[i].pont);
	}
}

Menus::MenuRank::~MenuRank()
{
}

void Menus::MenuRank::updateEstado(int& aux) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		MoveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		MoveDown();
	}
	for (int i = 0; i < 1; i++) {
		if (botoes[i].getGlobalBounds().contains(pGrafico->getJanela()->mapPixelToCoords(sf::Mouse::getPosition(*pGrafico->getJanela())))) {
			menu[selectedItemIndex].setFillColor(sf::Color::Black);
			menu[i].setFillColor(sf::Color::Red);
			botoes[i].isPressed(true);
			selectedItemIndex = i;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (selectedItemIndex == 0) {
					aux = 1;
				}
			}
		}
		else {
			botoes[i].isPressed(false);
		}
	}
}

void Menus::MenuRank::draw(sf::RenderWindow& window)
{
	sf::View view;
	pGrafico->getJanela()->setView(view);

	window.draw(background);

	for (int i = 0; i < 1; i++) {
		window.draw(botoes[i].getCorpo());
		window.draw(menu[i]);
	}

	// Imprime as dez posicoes do placar.
	for (int i = 0; i < 10; i++) {
		placar.setFont(font);
		placar.setFillColor(sf::Color::White);
		placar.setString((to_string(i)) + "  " + (to_string(infos[i].pont)) + "  " + infos[i].nome);
		placar.setCharacterSize(25);
		placar.setPosition(sf::Vector2f(100, (40.0f * i)));

		window.draw(placar);
	}
}

void Menus::MenuRank::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menus::MenuRank::MoveDown()
{
	if (selectedItemIndex + 1 < 1) {
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menus::MenuRank::update() {

}