#pragma once
#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Menu.h"

namespace Gerenciadores {
	class GerenciadorEvento
	{
	private:
		GerenciadorGrafico* pGrafico;
		Entidades::Personagens::Jogadores::Jogador* pJogador;

		static GerenciadorEvento* pEvento;
		GerenciadorEvento();
	public:
		~GerenciadorEvento();
		static GerenciadorEvento* getGerenciadorEvento();
		void setJogador(Entidades::Personagens::Jogadores::Jogador* pJogador);
		void verificarTeclaPressionada(sf::Keyboard::Key tecla);
		void verificarTeclaSolta(sf::Keyboard::Key tecla);
		void exec();
	};
}

