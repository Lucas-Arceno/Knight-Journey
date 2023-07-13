#include "Ente.h"

Gerenciadores::GerenciadorGrafico* Ente::pGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();

Ente::Ente(int id) : ID(id)
{
}

Ente::~Ente()
{
}

void Ente::seImprime(sf::RectangleShape corpo)
{
	pGrafico->desenhaElementos(corpo);
}

