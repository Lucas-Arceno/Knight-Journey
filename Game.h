#pragma once
#include "GerenciadorGrafico.h"
#include "Inimigo.h"

class Game
{
private:
	GerenciadorGrafico* pGrafico;
public:
	Game();
	~Game();
	void exec();
};

