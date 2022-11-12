#pragma once
#include "FaseCastelo.h"
#include "Menu.h"

class Game
{
private:
	GerenciadorGrafico* pGrafico;
	GerenciadorEvento* pEvento;
	/*
	List::ListaEntidade listaEntidades;
	List::ListaEntidade listaObstaculos;
	List::ListaEntidade listaInimigos;
	List::ListaEntidade listaPlataformas;
	*/

public:
	Game();
	~Game();
	void exec();
};

