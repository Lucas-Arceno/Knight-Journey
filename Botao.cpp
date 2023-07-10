#include "Botao.h"

Botao::Botao(const char* path)
{
	this->forma.setSize(sf::Vector2f(150.0f, 100.0f));
	this->botaoNormal.loadFromFile(path);
	this->forma.setTexture(&botaoNormal);

	this->botaoPress.loadFromFile("assets/botaopress.png");
}

Botao::~Botao()
{
}

sf::RectangleShape Botao::getCorpo()
{
	return this->forma;
}

void Botao::isPressed(bool pressionado)
{
	if (pressionado) {
		this->forma.setTexture(&botaoPress);
	}
	else {
		this->forma.setTexture(&botaoNormal);
	}
}

void Botao::setPosition(sf::Vector2f(pos))
{
	this->forma.setPosition(pos);
}

sf::FloatRect Botao::getGlobalBounds()
{
	return this->forma.getGlobalBounds();
}
