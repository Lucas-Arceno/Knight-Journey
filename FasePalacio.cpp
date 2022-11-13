#include "FasePalacio.h"


FasePalacio::FasePalacio()
{

	this->num_Cobras = -1;
	this->num_Teias = -1;
	this->num_Portais = -1;

	this->pJogador = new Jogador(sf::Vector2f(150.f, 250.f), sf::Vector2f(100.f, 100.f));

	this->GerenciadorColisao = new GerenciadorColisoes(pJogador, &listaInimigos, &listaPlataformas, &listaObstaculos);

	listaEntidades.addEntidade(pJogador);

	setPosicoesLivres();

	criaMapa();
	criaInimigos();
	criaObstaculos();

	for (int i = 0; i < listaEntidades.getTamanho(); i++) {
		/// 1 = teia
		/// 6 = espinhos
		/// 7 = portal
		if (listaEntidades[i]->getID() == 1 || listaEntidades[i]->getID() == 6 || listaEntidades[i]->getID() == 7) {
			listaObstaculos.addEntidade(listaEntidades[i]);
		}
		/// 2 = cobra
		/// 4 = morcego
		/// 5 = rei
		else if (listaEntidades[i]->getID() == 2 || listaEntidades[i]->getID() == 4 || listaEntidades[i]->getID() == 5) {
			listaInimigos.addEntidade(listaEntidades[i]);
		}
		/// 3 = plataforma
		else if (listaEntidades[i]->getID() == 3) {
			listaPlataformas.addEntidade(listaEntidades[i]);
		}
	}
}

FasePalacio::~FasePalacio()
{
}

void FasePalacio::setPosicoesLivres()
{
}

void FasePalacio::criaMapa()
{
	int k = 1;
	for (int i = 0; i < 10; i++) {
		if (i <= 5) {
			listaEntidades.addEntidade(new Plataforma(sf::Vector2f(200.0f + (i * 500), 700.0f), sf::Vector2f(500.0f, 50.0f), "assets/chao.png"));
			listaEntidades.addEntidade(new Plataforma(sf::Vector2f(200.0f + (i * 500), 100.0f), sf::Vector2f(500.0f, 50.0f), "assets/chao.png"));
		}
		else {
			listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2400 + (i*100), 700.0f - (50 * k)), sf::Vector2f(100.0f, 50.0f), "assets/chao.png"));
			listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2400 + (i * 100), 100.0f - (50 * k)), sf::Vector2f(100.0f, 50.0f), "assets/chao.png"));
			k++;
		}
	}
}

void FasePalacio::criaInimigos()
{
}

void FasePalacio::criaObstaculos()
{
}

bool FasePalacio::checkTerminou()
{
	return true;
}

void FasePalacio::update()
{
	this->GerenciadorColisao->updateColisao();
	render();
}

void FasePalacio::render()
{
	pGrafico->setView(sf::Vector2f(pJogador->getCorpo().getPosition().x, 300.0f));
	for (int i = 0; i < listaEntidades.getTamanho(); i++) {
		listaEntidades[i]->seImprime(listaEntidades[i]->getCorpo());
		pGrafico->desenhaElementos(pJogador->getCorpoEspada());
	}
	for (int i = 0; i < listaEntidades.getTamanho(); i++) {
		listaEntidades[i]->update();
	}

	pJogador->setEspadaPosicao(sf::Vector2f(0.0f, 5000.0f));
}
