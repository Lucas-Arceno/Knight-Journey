#pragma once
#include "Fase.h"

class PrimeiraFase : public Fase
{
private:

public:
	PrimeiraFase(Game* Principal);
	~PrimeiraFase();
	void init();
	void exec();
	void update();
};

