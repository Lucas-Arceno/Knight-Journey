#pragma once
#include "JogadorPrincipal.h"
#include "JogadorSecundario.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "ListaEntidade.h"

namespace Gerenciadores {
	class GerenciadorColisoes
	{
	private:
		std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores;
		List::ListaEntidade* pListaInimigos;
		List::ListaEntidade* pListaPlataformas;
		List::ListaEntidade* pListaObstaculos;
	public:
		GerenciadorColisoes(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, List::ListaEntidade* listaInimigos, List::ListaEntidade* listaPlataformas, List::ListaEntidade* ListaObstaculos);
		~GerenciadorColisoes();
		void updateColisao();
		void checkColPlataforma();
		void checkColObstaculos();
		void checkColInimigos();
	};
}

