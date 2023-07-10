#include "Fase.h"

Fases::Fase::Fase() : Jogadores(), GerenciadorColisao(), background(), pEvento(pEvento->getGerenciadorEvento())
{
}
Fases::Fase::~Fase()
{
}

Entidades::Obstaculos::Teia* Fases::Fase::criaTeia(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f(posicao), sf::Vector2f(tamanho))
{
	return new Entidades::Obstaculos::Teia(pJogadores, posicao, tamanho);
}

Entidades::Obstaculos::Portal* Fases::Fase::criaPortal(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f(destino), sf::Vector2f(posicao), sf::Vector2f(tamanho))
{
	return new Entidades::Obstaculos::Portal(pJogadores, destino, posicao, tamanho);
}

Entidades::Plataforma* Fases::Fase::criaPlataforma(sf::Vector2f(posicao), sf::Vector2f(tamanho), const int tipo)
{
	return new Entidades::Plataforma(sf::Vector2f(posicao), sf::Vector2f(tamanho), tipo);
}

Entidades::Personagens::Inimigos::Cobra* Fases::Fase::criaCobra(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f(posicao), sf::Vector2f(tamanho))
{
	return new Entidades::Personagens::Inimigos::Cobra(pJogadores, posicao, tamanho);
}

Entidades::Personagens::Inimigos::Morcego* Fases::Fase::criaMorcego(List::ListaEntidade* pListaEntidade, std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f(posicao), sf::Vector2f(tamanho))
{
	return new Entidades::Personagens::Inimigos::Morcego(pListaEntidade, pJogadores, posicao, tamanho);
}

