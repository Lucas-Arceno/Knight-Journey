#include "FaseCastelo.h"

FaseCastelo::FaseCastelo() : Fase()
{
	this->num_Morcegos = -1;
	this->num_Cobras = -1;
	this->background.setSize(sf::Vector2f(1920.0f , 1080.0f));
	this->backgroundTexture.loadFromFile("assets/castle.png");
	background.setTexture(&backgroundTexture);

	this->pJogador = new Jogador(sf::Vector2f(150.f, 250.f), sf::Vector2f(100.f, 100.f));

	this->GerenciadorColisao = new GerenciadorColisoes(pJogador,&listaInimigos, &listaPlataformas, &listaObstaculos);

	listaEntidades.addEntidade(pJogador);

	setPosicoesLivres();

	criaMapa();
	criaInimigos();
	criaObstaculos();

	// REI - PARA TESTES//
	listaEntidades.addEntidade(new Rei(pJogador, sf::Vector2f(500.0f, 500.0f), sf::Vector2f(100.0f, 100.0f))); 

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

FaseCastelo::~FaseCastelo()
{
}

void FaseCastelo::setPosicoesLivres()
{
	int j = 9;
	int k = 9;
	for (int i = 0; i < 30; i++) {
		if (i <= 20) {
			listaPosCobras[i].cord = sf::Vector2f(250.0f * i, 100.0f);
		}
		else {
			listaPosCobras[i].cord = sf::Vector2f(250.0f * k, 600.0f);
			k++;
		}
	}
	for (int i = 0; i < 30; i++) {
		if (i <= 20) {
			listaPosMorcegos[i].cord = sf::Vector2f(300.0f * i, 100.0f);
		}
		else {
			listaPosMorcegos[i].cord = sf::Vector2f(300.0f * j, 600.0f);
			j++;
		}
	}

	for (int i = 0; i < 20; i++) {
		if (i <= 20) {
			listaPosObstaculos[i].cord = sf::Vector2f(250.0f * i + 150, 625.f);
		}
		listaPosObstaculos[19+i].cord = sf::Vector2f(250.0f * i + 200, 250.0f);
	}
}

void FaseCastelo::criaMapa()
{
	//chao
	for (int i = 0; i < 4; i++) {
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(200.0f + (i*500), 700.0f), sf::Vector2f(500.0f, 50.0f)));
	}
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1950.0f, 800.0f), sf::Vector2f(50.0f, 250.0f)));

	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1950.0f, 900.0f), sf::Vector2f(500.0f, 50.0f)));

	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2150.0f, 800.0f), sf::Vector2f(50.0f, 250.0f)));

	for (int i = 0; i < 6; i++) {
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2400.0f + (i * 500), 700.0f), sf::Vector2f(500.0f, 50.0f)));
	}
	for (int i = 0; i < 6; i++) {
		if (i == 3) {
			continue;
		}
		else {
			listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2400.0f + (i * 500), 350.0f), sf::Vector2f(500.0f, 50.0f)));
		}
	}
	for (int i = 0; i < 6; i++) {
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2400.0f + (i * 500), 50.0f), sf::Vector2f(500.0f, 50.0f)));
	}
	for (int i = 0; i < 15; i++) {
		if (i <= 2){
			listaEntidades.addEntidade(new Plataforma(sf::Vector2f(5000.0f + (i * 500), 700.0f + (i * 50)), sf::Vector2f(500.0f, 50.0f)));
		}
		else {
			listaEntidades.addEntidade(new Plataforma(sf::Vector2f(5000.0f + (i * 500), 900.0f - (i * 50)), sf::Vector2f(500.0f, 50.0f)));
		}
	}
	//blocos
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(500.0f, 540.0f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(700.0f, 500.0f), sf::Vector2f(200.0f, 350.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(950.0f, 400.0f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1200.0f, 500.0f), sf::Vector2f(200.0f, 350.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1400.0f, 540.0f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2050.0f, 540.0f), sf::Vector2f(50.0f, 50.0f)));

	int aux_rand = rand() % 3;
	if (aux_rand == 2) {
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(5000.0f, 200.0f), sf::Vector2f(200.0f, 350.0f)));
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(3600.0f, 500.0f), sf::Vector2f(200.0f, 350.0f)));
	}
	else {
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(5050.0f, 500.0f), sf::Vector2f(200.0f, 350.0f)));
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(3600.0f, 200.0f), sf::Vector2f(200.0f, 350.0f)));
	}

	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(4000.0f, 540.0f), sf::Vector2f(50.0f, 50.0f)));
	
}

void FaseCastelo::criaInimigos()
{
	this->num_Cobras = (rand() % (10 + 1 - 3) + 3);
	this->num_Morcegos = (rand() % (10 + 1 - 3) + 3);

	for (int i = 0; i < num_Cobras; i++) {
		int aux = rand() % 30;
		while (!(listaPosCobras[aux].isLivre)) {
			aux = rand() % 30;
		}
		listaEntidades.addEntidade(new Cobra(pJogador, sf::Vector2f(listaPosCobras[aux].cord), sf::Vector2f(100.0f, 100.0f)));
		listaPosCobras[aux].isLivre = false;
	}
	for (int i = 0; i < num_Morcegos; i++) {
		int aux = rand() % 30;
		while (!(listaPosMorcegos[aux].isLivre)) {
			aux = rand() % 30;
		}
		listaEntidades.addEntidade(new Morcego(&listaEntidades, pJogador, sf::Vector2f(listaPosMorcegos[aux].cord), sf::Vector2f(50.0f, 50.0f)));
		listaPosMorcegos[aux].isLivre = false;
	}

}

void FaseCastelo::criaObstaculos()
{
	this->num_Teias = std::rand() % (20 + 1 - 3) + 3;
	this->num_Portais = std::rand() % (5 + 1 - 3) + 3;

	for (int i = 0; i < num_Teias; i++) {
		int aux2 = rand() % 40;
		while (!(listaPosObstaculos[aux2].isLivre)) {
			aux2 = rand() % 40;
		}
		listaEntidades.addEntidade(new Caixa(sf::Vector2f(listaPosObstaculos[aux2].cord), sf::Vector2f(100.0f, 100.0f)));
		listaPosObstaculos[aux2].isLivre = false;
	}

	for (int i = 0; i < num_Portais; i++) {
		int aux3 = rand() % 40;
		while (!(listaPosObstaculos[aux3].isLivre)) {
			aux3 = rand() % 40;
		}
		listaEntidades.addEntidade(new Portal(pJogador, sf::Vector2f(100.f, 100.f),sf::Vector2f(listaPosObstaculos[aux3].cord), sf::Vector2f(100.0f, 100.0f)));
		listaPosObstaculos[aux3].isLivre = false;
	}

	num_Espinhos = num_Espinhos + 3;
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(850.f, 625.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(1000.f, 625.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(2000.f, 800.f)));

	num_Portais = num_Portais + 2;
	listaEntidades.addEntidade(new Portal(pJogador, sf::Vector2f(100.f, 100.f), sf::Vector2f(700.0f, 300.0f), sf::Vector2f(70.f, 70.f)));
	listaEntidades.addEntidade(new Portal(pJogador, sf::Vector2f(100.f, 100.f), sf::Vector2f(1200.0f, 300.0f), sf::Vector2f(70.f, 70.f)));

}


bool FaseCastelo::checkTerminou() {
	sf::RectangleShape final;
	final.setSize(sf::Vector2f(100.f, 10000.f));
	final.setFillColor(sf::Color::Blue);
	final.setPosition(sf::Vector2f(70000.f, 0.f));

	if (pJogador->getCorpo().getGlobalBounds().intersects(final.getGlobalBounds())) {
		pJogador->setPosition(150.f, 600.f);
		return true;
	}
	else {
		return false;
	}
}


void FaseCastelo::update()
{
	this->GerenciadorColisao->updateColisao();
	render();
	//printf("%f %f\n", pJogador->getCorpo().getPosition().x, pJogador->getCorpo().getPosition().y);
}

void FaseCastelo::render()
{
	sf::View view;
	pGrafico->getJanela()->setView(view);
	pGrafico->desenhaElementos(this->background);
	view.setCenter(pJogador->getCorpo().getPosition().x, 300);
	pGrafico->getJanela()->setView(view); 
	
	for (int i = 0; i < listaEntidades.getTamanho(); i++) {
		listaEntidades[i]->seImprime(listaEntidades[i]->getCorpo());
		pGrafico->desenhaElementos(pJogador->getCorpoEspada());
	}
	for (int i = 0; i < listaEntidades.getTamanho(); i++) {
		listaEntidades[i]->update();
	}
	pJogador->setEspadaPosicao(sf::Vector2f(0.0f, 5000.0f));
}
