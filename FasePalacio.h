#pragma once
#include "Fase.h"

class FasePalacio : public Fase
{
private:
	listaPos listaPosMorcegos[6];
	listaPos listaPosCobras[10];
	listaPos listaPosObstaculos[14];

	int num_sala;

	int num_Morcegos;
	int num_Cobras;

	int num_Teias;
	int num_Portais;
public:
	FasePalacio(std::list<Jogador*>* pJogadores);
	~FasePalacio();

	void setPosicoesLivres();

	void checkQuarto();

	void criaMapa();
	void criaInimigos();
	void criaObstaculos();

	void multiplayer(bool status);

	bool checkTerminou();

	void update();
	void render();
};

