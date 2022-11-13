#pragma once
#include "Fase.h"

class FaseCastelo : public Fase 
{
private:
	Jogador* pJogador;

	listaPos listaPosCobras[50];
	listaPos listaPosMorcegos[30];
	listaPos listaPosObstaculos[40];


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
};

