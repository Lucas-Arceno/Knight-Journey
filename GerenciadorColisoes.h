#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "ListaEntidade.h"

class GerenciadorColisoes
{
private:
	Jogador* pJogador;
	List::ListaEntidade* pListaInimigos;
	List::ListaEntidade* pListaPlataformas;
	List::ListaEntidade* pListaObstaculos;
public:
	GerenciadorColisoes(Jogador* jogador, List::ListaEntidade* listaInimigos, List::ListaEntidade* listaPlataformas, List::ListaEntidade* ListaObstaculos);
	~GerenciadorColisoes();
	void updateColisao();
	void checkColPlataforma();
	void checkColObstaculos();
	void checkColInimigos();
};

