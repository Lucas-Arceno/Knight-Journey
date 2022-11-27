#pragma once
#include "Entidade.h"
#include <math.h>

namespace Entidades {
	class ProjetilBase : public Entidade
	{
		protected : 
			int tempVida = 0; // Tempo de vida do projetil
			bool disparo = false;
		public : 
			ProjetilBase(int id, sf::Vector2f posicao = sf::Vector2f(150.f, 250.f), sf::Vector2f tamanho = sf::Vector2f(20.f, 10.f));
			~ProjetilBase();
			
			virtual void update() = 0 ;
			virtual void updateMovimento() = 0;
			virtual void reagir() = 0;
			void reagirDano();
	};
}