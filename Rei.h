#pragma once
#include "Inimigo.h"
#include <iostream>

namespace Entidades {
	namespace Personagens {
		namespace Inimigos {
			class Rei : public Inimigo
			{
			private:
				const int vidaMaxima;
				bool cooldownPulo = false;

				// Contador para cooldownPulo
				int cont_CD = 0; 

			public:
				Rei(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, float posX, float posY, float tamX, float tamY);
				Rei(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
				virtual ~Rei();

				void setColdownPulo(bool cd) { this->cooldownPulo = cd; }

				void update();
				void updateMovimento();

				void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
				void ataqueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);

				void reagir();
			};
		}
	}
}
