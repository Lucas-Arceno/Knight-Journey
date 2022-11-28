#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Espinhos : public Obstaculo
		{
		private:
			// nivelAfiado determina que o jogador recebe
			int nivelAfiado;

		public:
			Espinhos(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(150.f, 200.f));
			virtual ~Espinhos();

			void update();
			void updateMovimento();
			void reagir();
		};
	}
}


