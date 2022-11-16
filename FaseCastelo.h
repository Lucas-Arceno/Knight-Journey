#pragma once
#include "Fase.h"

class FaseCastelo : public Fase 
{
private:
	JogadorPrincipal* pJogador;

	listaPos listaPosCobras[19];
	listaPos listaPosMorcegos[27];
	listaPos listaPosObstaculos[29];

	int num_Morcegos;
	int num_Cobras;
	int num_Espinhos;
	int num_Portais;
	int num_Teias;

public:
	FaseCastelo();
	~FaseCastelo();

	void setPosicoesLivres();

	void criaMapa();
	void criaInimigos();
	void criaObstaculos();

	const int getPontuacao();

	bool checkMorreu();
	bool checkTerminou();

	void update();
	void render();

	// teste 

	//Save salve;
};

