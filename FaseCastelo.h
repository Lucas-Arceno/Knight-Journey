#pragma once
#include "Fase.h"
#include "Menu.h"

struct listaPos{
	sf::Vector2f cord;
	bool isLivre = true;
};

class FaseCastelo : public Fase 
{
private:
	Jogador* pJogador;

	listaPos listaPosCobras[20];
	listaPos listaPosMorcegos[20];
	listaPos listaPosObstaculus[20];


	int num_Morcegos;
	int num_Cobras;
	int num_Teias;
	int num_Espinhos;
	int num_Portais;
public:
	FaseCastelo();
	~FaseCastelo();

	void setPosicoesLivres();

	void criaMapa();
	void criaInimigos();
	void criaObstaculos();

	bool checkTerminou();

	void update();
	void render();
};

