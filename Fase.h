#pragma once

#include<cstdlib>
#include<ctime>

#include "Save.h"

#include "GerenciadorEvento.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"

#include "ListaEntidade.h"

#include "Plataforma.h"

#include "Teia.h"
#include "Espinhos.h"
#include "Portal.h"

#include "Inimigo.h"
#include "Cobra.h"
#include "Morcego.h"
#include "Rei.h"

namespace Fases {
	struct listaPos {
		sf::Vector2f cord;
		bool isLivre = true;
	};

	class Fase : public Ente
	{
	protected:
		//Corpo, textura e afins
		sf::RectangleShape background;
		sf::Texture backgroundTexture;

		//Listas
		List::ListaEntidade listaEntidades;
		List::ListaEntidade listaObstaculos;
		List::ListaEntidade listaInimigos;
		List::ListaEntidade listaPlataformas;

		//Jogadores
		std::list<Entidades::Personagens::Jogadores::Jogador*>* Jogadores;

		//GerenciadorGrafico* pGrafico;
		Gerenciadores::GerenciadorEvento* pEvento;
		Gerenciadores::GerenciadorColisoes* GerenciadorColisao;
	public:
		Fase();
		virtual ~Fase();
		virtual void update() = 0;
		virtual void render() = 0;
	};
}

