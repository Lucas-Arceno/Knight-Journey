#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "ListaEntidade.h"
#include "Plataforma.h"
#include "Caixa.h"
#include "GerenciadorEvento.h"
#include "Inimigo.h"
#include "Cobra.h"
#include "Morcego.h"



class Game
{
private:
	GerenciadorGrafico* pGrafico;
	GerenciadorEvento* pEvento;
	

	List::ListaEntidade listaEntidades;
	List::ListaEntidade listaObstaculos;
	List::ListaEntidade listaInimigos;
	List::ListaEntidade listaPlataformas;

public:
	Game();
	~Game();
	void exec();
};

