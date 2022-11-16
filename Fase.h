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

struct listaPos {
	sf::Vector2f cord;
	bool isLivre = true;
};

class Fase : public Ente
{
protected:
	sf::RectangleShape background;
	sf::Texture backgroundTexture;

	List::ListaEntidade listaEntidades;
	List::ListaEntidade listaObstaculos;
	List::ListaEntidade listaInimigos;
	List::ListaEntidade listaPlataformas;

	//GerenciadorGrafico* pGrafico;
	GerenciadorEvento* pEvento;
	GerenciadorColisoes* GerenciadorColisao;
public:
	Fase();
	virtual ~Fase();
	virtual void update() = 0;
	virtual void render() = 0;
};

