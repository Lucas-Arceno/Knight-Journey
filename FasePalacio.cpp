#include "FasePalacio.h"


FasePalacio::FasePalacio()
{
	this->num_sala = 0;

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
	//CONSTRUCAO BASE DAS SALAS (CHAO E PAREDES)
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(35.0f, 15.0f), sf::Vector2f(50.0f, 1000.0f), "assets/chao.jpg"));
	for (int i = 0; i < 2; i++) {
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(250.0f + (500 * i), 550.0f), sf::Vector2f(525.0f, 70.0f), "assets/chao.jpg"));
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(250.0f + (500 * i), -400.0f), sf::Vector2f(525.0f, 70.0f), "assets/chao.jpg"));
	}
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(985.0f, 15.0f), sf::Vector2f(50.0f, 1000.0f), "assets/chao.jpg"));
	//

	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(200.0f, 400.0f), sf::Vector2f(50.0f, 50.0f), "assets/chao.jpg"));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(500.0f, 300.0f), sf::Vector2f(300.0f, 50.0f), "assets/chao.jpg"));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(900.0f, 200.0f), sf::Vector2f(300.0f, 50.0f), "assets/chao.jpg"));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(950.0f, 0.0f), sf::Vector2f(50.0f, 50.0f), "assets/chao.jpg"));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(650.0f, -100.0f), sf::Vector2f(300.0f, 50.0f), "assets/chao.jpg"));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(350.0f, 10.0f), sf::Vector2f(100.0f, 50.0f), "assets/chao.jpg"));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(50.0f, -100.0f), sf::Vector2f(300.0f, 50.0f), "assets/chao.jpg"));
}

void FasePalacio::criaInimigos()
{
}

void FasePalacio::criaObstaculos()
{
	listaEntidades.addEntidade(new Portal(pJogador, sf::Vector2f(10000.f, 1000.f), sf::Vector2f(70.0f, -150.0f), sf::Vector2f(70.f, 70.f)));
}

bool FasePalacio::checkTerminou()
{
	return true;
}

void FasePalacio::update()
{
	printf("%f %f\n", pJogador->getCorpo().getPosition().x, pJogador->getCorpo().getPosition().y);
	this->GerenciadorColisao->updateColisao();
	render();
}

void FasePalacio::render()
{
	if (num_sala == 0) {
		pGrafico->setView(sf::Vector2f(509.987488, 66.165459));
	}
	for (int i = 0; i < listaEntidades.getTamanho(); i++) {
		listaEntidades[i]->seImprime(listaEntidades[i]->getCorpo());
		pGrafico->desenhaElementos(pJogador->getCorpoEspada());
	}
	for (int i = 0; i < listaEntidades.getTamanho(); i++) {
		listaEntidades[i]->update();
	}

	pJogador->setEspadaPosicao(sf::Vector2f(0.0f, 5000.0f));
}
