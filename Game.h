#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "ListaEntidade.h"
#include "Plataforma.h"
#include "Inimigo.h"
#include "Cobra.h"
#include "Morcego.h"


class Game
{
private:
	GerenciadorGrafico* pGrafico;

	List::ListaEntidade listaEntidades;

	List::ListaEntidade listaInimigos;
	List::ListaEntidade listaPlataformas;

public:
	Game();
	~Game();
	void exec();
};

