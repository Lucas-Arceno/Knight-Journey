#pragma once
#include "GerenciadorGrafico.h"
#include "ListaEntidade.h"
#include "Cobra.h"
#include "Morcego.h"

class Game
{
private:
	GerenciadorGrafico* pGrafico;
	List::ListaEntidade listaEntidades;
public:
	Game();
	~Game();
	void exec();
};

