#pragma once
#include "Fase.h"

class FasePalacio : public Fase
{
private:
	Jogador* pJogador;

	listaPos listaPosMorcegos[20];
	listaPos listaPosCobras[20];
	listaPos listaPosObstaculos[14];

	int num_sala;

	int num_Morcegos;
	int num_Cobras;

	int num_Teias;
	int num_Portais;
public:
	FasePalacio();
	~FasePalacio();

	void setPosicoesLivres();

	void checkQuarto();

	void criaMapa();
	void criaInimigos();
	void criaObstaculos();

	bool checkTerminou();

	void update();
	void render();
};

