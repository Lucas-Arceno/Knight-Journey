#pragma once
#include "Fase.h"

class FaseCastelo : public Fase 
{
private:
	Jogador* pJogador;
	int num_Morcegos;
	int num_Cobras;
	int num_Teias;
	int num_Espinhos;
	int num_Portais;
public:
	FaseCastelo();
	~FaseCastelo();
	void criaMapa();
	void criaInimigos();
	void criaObstaculos();
	void update();
	void render();
};

