#pragma once
#include "Fase.h"

class FasePalacio : public Fase
{
private:
	Jogador* pJogador;

	listaPos listaPosCobras[20];
	listaPos listaPosObstaculus[20];

	int num_Cobras;
	int num_Teias;
	int num_Portais;
public:
	FasePalacio();
	~FasePalacio();

	void setPosicoesLivres();

	void criaMapa();
	void criaInimigos();
	void criaObstaculos();

	bool checkTerminou();

	void update();
	void render();
};

