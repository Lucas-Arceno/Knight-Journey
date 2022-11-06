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
	int aux = 0;
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
	for (int i = 0; i < pListaPlataformas->getTamanho(); i++) {
		if (pJogador->GetColisao().CheckCollision((*pListaPlataformas)[i]->GetColisao(), 0.0f)) {
			pJogador->resetVelocity();
			if ((*pListaPlataformas)[i]->getCorpo().getPosition().y  >
				pJogador->getCorpo().getPosition().y + pJogador->getCorpo().getGlobalBounds().height/2.0f) {
				pJogador->setColdownPulo(true);
				aux++;
			}
		}
		else if(aux==0) {
			pJogador->setColdownPulo(false);
		}
	}
}

void GerenciadorColisoes::checkColObstaculos()
{
	for (int i = 0; i < pListaObstaculos->getTamanho(); i++) {
		if (pJogador->GetColisao().verificaColisao((*pListaObstaculos)[i]->getCorpo())) {
			pJogador->setVelocityX(0.1f);
		}
	}
}

void GerenciadorColisoes::checkColInimigos()
{
	for (int i = 0; i < pListaInimigos->getTamanho(); i++) {
		if (pJogador->getCorpoEspada().getGlobalBounds().intersects((*pListaInimigos)[i]->getCorpo().getGlobalBounds())) {
			printf("acertei");
		}
	}
}
