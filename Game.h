#pragma once
#include "GerenciadorGrafico.h"
#include "Cobra.h"
#include "Morcego.h"

class Game
{
private:
	GerenciadorGrafico* pGrafico;
public:
	Game();
	~Game();
	void exec();
};

