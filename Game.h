#pragma once
#include "GerenciadorGrafico.h"
#include "Jogador.h"

class Game
{
private:
	GerenciadorGrafico* pGrafico;
public:
	Game();
	~Game();
	void exec();
};

