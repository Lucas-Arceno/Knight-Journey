#include "JogadorPrincipal.h"

JogadorPrincipal::JogadorPrincipal(sf::Vector2f posicao, sf::Vector2f tamanho) : Jogador(posicao, tamanho)
{
}

JogadorPrincipal::~JogadorPrincipal()
{
}

void JogadorPrincipal::updateMovimento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->move(-1.0f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->move(1.f, 0.f);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && coldownPulo == true)) {
		this->velocidade.y -= 20.0 * this->gravity;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		atacarEsq();
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		atacarDir();
	}
}
