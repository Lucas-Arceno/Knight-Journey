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

FaseCastelo::~FaseCastelo()
{
}

void FaseCastelo::criaMapa()
{
	//chao
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(200.0f, 700.0f), sf::Vector2f(500.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(700.0f, 700.0f), sf::Vector2f(500.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1200.0f, 700.0f), sf::Vector2f(500.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1700.0f, 700.0f), sf::Vector2f(500.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1950.0f, 800.0f), sf::Vector2f(50.0f, 250.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1950.0f, 900.0f), sf::Vector2f(500.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2150.0f, 800.0f), sf::Vector2f(50.0f, 250.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2400.0f, 700.0f), sf::Vector2f(500.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2700.0f, 700.0f), sf::Vector2f(500.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(3200.0f, 700.0f), sf::Vector2f(500.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(3700.0f, 700.0f), sf::Vector2f(500.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(4200.0f, 700.0f), sf::Vector2f(500.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(4700.0f, 700.0f), sf::Vector2f(500.0f, 50.0f)));

	//blocos
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(500.0f, 540.0f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(700.0f, 500.0f), sf::Vector2f(200.0f, 350.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(950.0f, 400.0f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1200.0f, 500.0f), sf::Vector2f(200.0f, 350.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1400.0f, 540.0f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2050.0f, 540.0f), sf::Vector2f(50.0f, 50.0f)));
}

void FaseCastelo::criaInimigos()
{
	std::srand(std::time(0));

	this->num_Cobras = std::rand() % (15 + 1 - 3) + 5;
	this->num_Morcegos = std::rand() % (15 + 1 - 3) + 5;



	for (int i = 0; i < num_Cobras; i++) {
		listaEntidades.addEntidade(new Cobra(pJogador, sf::Vector2f(500.f + (100.f * i), 600.f), sf::Vector2f(100.0f, 100.0f)));
	}
	for (int i = 0; i < num_Morcegos; i++) {
		listaEntidades.addEntidade(new Morcego(&listaEntidades, pJogador, sf::Vector2f(500.f + (100.f * i), 400.f), sf::Vector2f(50.0f, 50.0f)));
	}

}

void FaseCastelo::criaObstaculos()
{
	std::srand(std::time(0));
	this->num_Espinhos = std::rand() % (15 + 1 - 3) + 5;
	this->num_Portais = std::rand() % (15 + 1 - 3) + 5;
	this->num_Teias = std::rand() % (15 + 1 - 3) + 5;

	for (int i = 0; i < num_Espinhos; i++) {
		
	}

	for (int i = 0; i < num_Teias; i++) {
		
	}

	for (int i = 0; i < num_Portais; i++) {
		
	}

	num_Espinhos = num_Espinhos + 3;
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(850.f, 625.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(1000.f, 625.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(2000.f, 800.f)));

	num_Portais = num_Portais + 2;
	listaEntidades.addEntidade(new Portal(pJogador, sf::Vector2f(100.f, 100.f), sf::Vector2f(700.0f, 300.0f), sf::Vector2f(70.f, 70.f)));
	listaEntidades.addEntidade(new Portal(pJogador, sf::Vector2f(100.f, 100.f), sf::Vector2f(1200.0f, 300.0f), sf::Vector2f(70.f, 70.f)));

}

void FaseCastelo::update()
{
	sf::View view;
	Menu Menu(1200, 800);
	while (pGrafico->verificaJanelaAberta()) {
		pEvento->exec();
		pGrafico->limpaJanela();

		/*pGrafico->getJanela()->setView(view);
		pGrafico->desenhaElementos(this->background);

		for (int i = 0; i < listaEntidades.getTamanho(); i++) {
				listaEntidades[i]->update();
		}	
		sf::Vector2f pos;
		if (pJogador->getPosicao().y < 300.0f) {
			pos = sf::Vector2f(pJogador->getCorpo().getPosition().x - 1200/2.0f, -200 );
        }
        else {
			pos = sf::Vector2f(pJogador->getCorpo().getPosition().x - 1200 / 2.0f , 300 );
        }
		background.setPosition(pos);
		view.setCenter(pJogador->getCorpo().getPosition().x, 300);
		this->GerenciadorColisao->updateColisao();

		for (int i = 0; i < listaEntidades.getTamanho(); i++) {
			listaEntidades[i]->seImprime(listaEntidades[i]->getCorpo());
			pGrafico->desenhaElementos(pJogador->getCorpoEspada());
		}*/
		Menu.Update();
		Menu.draw(*pGrafico->getJanela());
		pGrafico->mostraElementos();
		//pJogador->setEspadaPosicao(sf::Vector2f(0.0f, 5000.0f));
	}
}

void FaseCastelo::render()
{
}
