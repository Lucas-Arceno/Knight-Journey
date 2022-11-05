#include "PrimeiraFase.h"

PrimeiraFase::PrimeiraFase(Game* Principal) : Fase()
{
	pEvento = GerenciadorEvento::getGerenciadorEvento();
	pGrafico = GerenciadorGrafico::getGerenciadorGrafico();
	listaEntidades = new List::ListaEntidade();
	listaInimigos = new List::ListaEntidade();
	listaObstaculos = new List::ListaEntidade();
	listaPlataformas = new List::ListaEntidade();
	pJogador = new Jogador(sf::Vector2f(50.f, 50.f), sf::Vector2f(100.f, 100.f));
}
PrimeiraFase::~PrimeiraFase()
{
}

void PrimeiraFase::init()
{
}

void PrimeiraFase::exec()
{
}

void PrimeiraFase::update()
{
}
