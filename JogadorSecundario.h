#pragma once
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		namespace Jogadores {
			enum JogadorSecundarioAnimation_States { IDLE2 = 0, MOVING_LEFT2 = 1, MOVING_RIGHT2 = 2, JUMPING2 = 3 };

			class JogadorSecundario : public Jogador
			{
			private:
				const int vidaMaxima;

				sf::Vector2i size;
				sf::Clock animationTimer;

				//Animation
				short animState;
				sf::IntRect currentFrame;
				bool animationSwitch;
			private:
				void initAnimations();
			public:
				JogadorSecundario(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
				~JogadorSecundario();

				const bool& getAnimSwitch();
				void resetAnimationTimer();

				void initSprite();

				void update();
				void updateMovimento();
				void updateAnimations();
				void reagir();
			};
		}
	}
}