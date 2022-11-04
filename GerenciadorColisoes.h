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
public:
	GerenciadorColisoes(Jogador* jogador, List::ListaEntidade* listaInimigos, List::ListaEntidade* listaPlataformas);
	~GerenciadorColisoes();
	void updateColisao();
	void checkColPlataforma();
};

