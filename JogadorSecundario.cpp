#include "JogadorSecundario.h"

JogadorSecundario::JogadorSecundario(List::ListaEntidade* pListaEntidade, sf::Vector2f posicao, sf::Vector2f tamanho) : Jogador(pListaEntidade, posicao, tamanho)
{
}

JogadorSecundario::~JogadorSecundario()
{
}

void JogadorSecundario::updateMovimento()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
		this->move(-1.0f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		this->move(1.f, 0.f);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::I) && coldownPulo == true)) {
		this->velocidade.y -= 20.0 * this->gravity;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
		atacarEsq();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
		atacarDir();
	}
}
