#pragma once

#include "GerenciadorEvento.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "ListaEntidade.h"
#include "Plataforma.h"
#include "Inimigo.h"
#include "Morcego.h"
#include "Caixa.h"
#include "Cobra.h"
#include "Game.h"

class Fase
{
protected:
	GerenciadorGrafico* pGrafico;
	GerenciadorEvento* pEvento;

	Jogador* pJogador;

	List::ListaEntidade* listaEntidades;
	List::ListaEntidade* listaObstaculos;
	List::ListaEntidade* listaInimigos;
	List::ListaEntidade* listaPlataformas;
public:
	Fase();	
	virtual ~Fase();
	virtual void init() = 0;
	virtual void exec() = 0;
	virtual void update() = 0;
};

