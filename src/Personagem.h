#pragma once
#include "Entidade.h"

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			int vida;
		public:
			Personagem(int id = 0, sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(0.f, 0.f));
			virtual ~Personagem();

			void giveDano(int dano);
			void setVida(int vida);
			int getVida();

			void reagirDano();
			//void updateDano(int dano);
		};
	}
}


