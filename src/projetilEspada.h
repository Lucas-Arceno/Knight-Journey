#pragma once
#include "ProjetilBase.h"
#include "Jogador.h"


namespace Entidades {
	namespace Personagens {
		namespace Jogadores {
			class Jogador;

			class projetilEspada : public ProjetilBase
			{
			private:
				//int timerVida = 0; // Tempo de vida da espada.
				//bool disparo = false;
				bool isDireita = false;
				Jogador* pJogador;
			public:

				projetilEspada(Jogador* pJogador, sf::Vector2f posicao = sf::Vector2f(150.f, 250.f), sf::Vector2f tamanho = sf::Vector2f(20.f, 10.f));
				~projetilEspada();

				sf::RectangleShape getEspadaProjetil() { return this->corpo; };
				sf::FloatRect getEspadaProjetilGlobal() { return this->corpo.getGlobalBounds(); }

				void update();
				void updateEmpuxo();
				void updateMovimento();
				void reagir();
				void disparoEspada(bool isDir);

				void setScalee(float x, float y) { this->corpo.setScale(x, y); }
			};
		}
	}
	
}


