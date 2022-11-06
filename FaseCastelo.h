#pragma once
#include "Fase.h"

class FaseCastelo : public Fase 
{
private:
	Jogador* pJogador;
public:
	FaseCastelo();
	~FaseCastelo();
	void update();
	void render();
};

