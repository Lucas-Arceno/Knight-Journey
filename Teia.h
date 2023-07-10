#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Teia : public Obstaculo
		{
		private:
			// A teia irá causar lentidão nos inimigos
			// Quanto menor mais complicado de passar
			int estagio; 
		public:
			Teia(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(30.f, 50.f));
			virtual ~Teia();

			void update();
			void updateMovimento();
			void reagir();
		};
	}
}


