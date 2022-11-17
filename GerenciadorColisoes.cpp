#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes(std::list<Jogador*>*Jogadores, List::ListaEntidade* listaInimigos, List::ListaEntidade* listaPlataformas, List::ListaEntidade* ListaObstaculos)
{
	this->pJogadores = Jogadores;
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
	for (unsigned int j = 0; j < pListaInimigos->getTamanho(); j++) {
		for (unsigned int k = 0; k < pListaPlataformas->getTamanho(); k++) {
			if((*pListaInimigos)[j]->GetColisao().CheckCollision((*pListaPlataformas)[k]->GetColisao(), 0.0f) && (*pListaInimigos)[j]->getID() == 10){
				(*pListaInimigos)[j]->setCorpoPosicao(sf::Vector2f(-14004.f, 50041.f));
			}
		}
	}
	for (unsigned int h = 0; h < pListaObstaculos->getTamanho(); h++) {
		for (unsigned int o = 0; o < pListaPlataformas->getTamanho(); o++) {
			(*pListaObstaculos)[h]->GetColisao().CheckCollision((*pListaPlataformas)[o]->GetColisao(), 0.0f);
		}
	}
	for (unsigned int i = 0; i < pListaPlataformas->getTamanho(); i++) {
		for (auto const& pJogador : *pJogadores)
		{
			if (pJogador->GetColisao().CheckCollision((*pListaPlataformas)[i]->GetColisao(), 0.0f)) {
				pJogador->resetVelocity();
				if ((*pListaPlataformas)[i]->getCorpo().getPosition().y >
					pJogador->getCorpo().getPosition().y + pJogador->getCorpo().getGlobalBounds().height / 2.0f) {
					pJogador->setColdownPulo(true);
					aux++;
				}
			}
			else if (aux == 0) {
				pJogador->setColdownPulo(false);
			}
		}
	}
}

void GerenciadorColisoes::checkColObstaculos()
{
	for (unsigned int i = 0; i < pListaObstaculos->getTamanho(); i++) {
		if ((*pListaObstaculos)[i]->getID() == 11) { // Teia
			for (auto const& pJogador : *pJogadores)
			{
				if (pJogador->GetColisao().verificaColisao((*pListaObstaculos)[i]->getCorpo())) {
					pJogador->setVelocityX(0.1f);
				}
			}
		}
		if ((*pListaObstaculos)[i]->getID() == 12) { // Espinho
			for (auto const& pJogador : *pJogadores)
			{
				if (pJogador->GetColisao().verificaColisao((*pListaObstaculos)[i]->getCorpo())) {
					pJogador->giveDano(5);
					printf("%d\n", pJogador->getVida());
				}
			}
		}
	}
}

void GerenciadorColisoes::checkColInimigos()
{
	for (unsigned int i = 0; i < pListaInimigos->getTamanho(); i++) {
		//(*pListaInimigos)[i]->GetColisao().CheckCollision(pJogador->GetColisao(), 1.0f);
	}
}
