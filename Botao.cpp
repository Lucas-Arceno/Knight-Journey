#include "Botao.h"

Botao::Botao(const char* path)
{
	this->forma.setSize(sf::Vector2f(150.0f, 100.0f));
	this->Texture.loadFromFile(path);
	this->forma.setTexture(&Texture);
}

Botao::~Botao()
{
}

sf::RectangleShape Botao::getCorpo()
{
	return this->forma;
}

void Botao::setPosition(sf::Vector2f(pos))
{
	this->forma.setPosition(pos);
}

sf::FloatRect Botao::getGlobalBounds()
{
	return this->forma.getGlobalBounds();
}
