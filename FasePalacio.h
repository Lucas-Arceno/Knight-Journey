#pragma once
#include "Fase.h"

class FasePalacio : public Fase
{
private:
	std::list<Jogador*>Jogadores;

	listaPos listaPosMorcegos[6];
	listaPos listaPosCobras[10];
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

