#pragma once
#include "FaseCastelo.h"
#include "Menu.h"

class Game
{
private:
	GerenciadorGrafico* pGrafico;
	GerenciadorEvento* pEvento;

public:
	Game();
	~Game();
	void exec();
};

