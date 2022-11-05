#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes(Jogador* jogador, List::ListaEntidade* listaInimigos, List::ListaEntidade* listaPlataformas, List::ListaEntidade* ListaObstaculos)
{
	this->pJogador = jogador;
	this->pListaObstaculos = ListaObstaculos;
	this->pListaInimigos = listaInimigos;
	this->pListaPlataformas = listaPlataformas;
}

GerenciadorColisoes::~GerenciadorColisoes()
{
}

void GerenciadorColisoes::updateColisao()
{
	checkColObstaculos();
	checkColPlataforma();
	checkColInimigos();
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
	for (int j = 0; j < pListaInimigos->getTamanho(); j++) {
		for (int k = 0; k < pListaPlataformas->getTamanho(); k++) {
			(*pListaInimigos)[j]->GetColisao().CheckCollision((*pListaPlataformas)[k]->GetColisao(), 0.0f);
		}
	}
	for (int h = 0; h < pListaObstaculos->getTamanho(); h++) {
		for (int o = 0; o < pListaPlataformas->getTamanho(); o++) {
			(*pListaObstaculos)[h]->GetColisao().CheckCollision((*pListaPlataformas)[o]->GetColisao(), 0.0f);
		}
	}
}

void GerenciadorColisoes::checkColObstaculos()
{
	for (int i = 0; i < pListaObstaculos->getTamanho(); i++) {
		if (pJogador->GetColisao().CheckCollision((*pListaObstaculos)[i]->GetColisao(), 1.0f)) {
			pJogador->setColdownPulo(true);
		}
	}
}

void GerenciadorColisoes::checkColInimigos()
{
	for (int i = 0; i < pListaInimigos->getTamanho(); i++) {
		if (pJogador->GetColisao().CheckCollision((*pListaInimigos)[i]->GetColisao(), 0.0f)) {
			std::cout << "Jogador tomou dano" << std::endl;
		}
	}
	for (int j = 0; j < pListaInimigos->getTamanho(); j++) {
		for (int k = 0; k < pListaObstaculos->getTamanho(); k++) {
			(*pListaInimigos)[j]->GetColisao().CheckCollision((*pListaObstaculos)[k]->GetColisao(), 0.0f);
		}
	}
}
