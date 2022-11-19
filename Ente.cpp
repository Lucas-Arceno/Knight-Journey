#include "Ente.h"

Ente::Ente(int id) : ID(id), pGrafico(pGrafico->getGerenciadorGrafico())
{
}

Ente::~Ente()
{
}

void Ente::seImprime(sf::RectangleShape corpo)
{
	pGrafico->desenhaElementos(corpo);
}

