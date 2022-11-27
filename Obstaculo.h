#pragma once
#include "Entidade.h"
#include "Jogador.h"

namespace Entidades {
	namespace Obstaculos {
		class Obstaculo : public Entidades::Entidade
		{
		protected:
			std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores;
		public:
			Obstaculo(int id , std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
			virtual ~Obstaculo();

			virtual void update() = 0;
			virtual void updateMovimento() = 0;
			virtual void reagir() = 0;

			void reagirDano();
		};
	}
}


 