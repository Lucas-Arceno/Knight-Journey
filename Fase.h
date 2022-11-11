#pragma once

#include<cstdlib>
#include<ctime>

#include "GerenciadorEvento.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"

#include "ListaEntidade.h"

#include "Plataforma.h"

#include "Caixa.h"
#include "Espinhos.h"
#include "Portal.h"

#include "Inimigo.h"
#include "Cobra.h"
#include "Morcego.h"
#include "Rei.h"


class Fase
{
protected:
	sf::RectangleShape background;
	sf::Texture backgroundTexture;

	List::ListaEntidade listaEntidades;
	List::ListaEntidade listaObstaculos;
	List::ListaEntidade listaInimigos;
	List::ListaEntidade listaPlataformas;

	GerenciadorGrafico* pGrafico;
	GerenciadorEvento* pEvento;
	GerenciadorColisoes* GerenciadorColisao;
public:
	Fase();
	virtual ~Fase();
	virtual void update() = 0;
	virtual void render() = 0;
};

