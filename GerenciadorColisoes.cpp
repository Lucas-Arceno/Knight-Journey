#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes(Jogador* jogador, List::ListaEntidade* listaInimigos, List::ListaEntidade* listaPlataformas)
{
	this->pJogador = jogador;
	this->pListaInimigos = listaInimigos;
	this->pListaPlataformas = listaPlataformas;
}

GerenciadorColisoes::~GerenciadorColisoes()
{
}

void GerenciadorColisoes::updateColisao()
{
	checkColPlataforma();
}

void GerenciadorColisoes::checkColPlataforma()
{
	for (int i = 0; i < pListaPlataformas->getTamanho(); i++) {
		if (pJogador->GetColisao().CheckCollision((*pListaPlataformas)[i]->GetColisao(), 0.0f)) {
			pJogador->setColdownPulo(true);
		}
		else {
			pJogador->setColdownPulo(false);
		}
	}
}
