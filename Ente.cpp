#include "Ente.h"

Ente::Ente(int id) : ID(id), pGraphics(pGraphics->getGerenciadorGrafico())
{
}

Ente::~Ente()
{
}

void Ente::seImprime(sf::RectangleShape corpo)
{
	pGraphics->desenhaElementos(corpo);
}
