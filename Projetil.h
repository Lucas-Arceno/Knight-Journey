#pragma once
#include "Entidade.h"

class Projetil : public Entidade 
{
	private: 

	public:
		Projetil();
		~Projetil();

		void update();
		void updateMovimento() ;

};

