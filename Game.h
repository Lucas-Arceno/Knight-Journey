#pragma once

#include "FaseCastelo.h"
#include "FasePalacio.h"

#include "Menu.h"
#include "MenuFases.h"
#include "MenuGameOver.h"
#include "MenuEscolhaOnline.h"

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

