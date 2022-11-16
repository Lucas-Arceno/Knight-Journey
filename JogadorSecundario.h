#pragma once
#include "Jogador.h"

class JogadorSecundario : public Jogador
{
private:

public:
	JogadorSecundario(List::ListaEntidade* pListaEntidade, sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
	~JogadorSecundario();
	void updateMovimento();
};

