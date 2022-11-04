#include "ColisaoTeste.h"
#include <iostream>

ColisaoTeste::ColisaoTeste()
{
}

ColisaoTeste::~ColisaoTeste()
{
}

void ColisaoTeste::checkColisao(sf::RectangleShape corpo1, sf::RectangleShape corpo2)
{
	if (corpo1.getGlobalBounds().intersects(corpo2.getGlobalBounds())) {
		std::cout << "Collision" << std::endl;
	}
}
