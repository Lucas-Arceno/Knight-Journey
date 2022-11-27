#pragma once
#include "Inimigo.h"
#include<cstdlib>
#include<ctime>

namespace Entidades {
	namespace Personagens {
		namespace Inimigos {
			class Cobra : public Inimigo
			{
			private:
				const int vidaMaxima;
				bool venenosa;
			public:
				Cobra(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, float posX, float posY, float tamX, float tamY);
				Cobra(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
				virtual ~Cobra();

				void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);

				void update();
				void updateMovimento();
				void reagir();
			};
		}
	}
}

