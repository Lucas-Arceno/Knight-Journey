#include "FaseCastelo.h"

FaseCastelo::FaseCastelo() : Fase()
{

	this->background.setSize(sf::Vector2f(1920.0f , 1080.0f));
	this->backgroundTexture.loadFromFile("assets/castle.png");
	background.setTexture(&backgroundTexture);

	this->pJogador = new Jogador(sf::Vector2f(150.f, 250.f), sf::Vector2f(100.f, 100.f));

	this->GerenciadorColisao = new GerenciadorColisoes(pJogador,&listaInimigos, &listaPlataformas, &listaObstaculos);

									/*cria e add na lista entidades geral*/
	//plataformas(posicao, tamanho)
	
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

	//jogadores
	listaEntidades.addEntidade(pJogador);

	//inimigos
	listaEntidades.addEntidade(new Morcego(&listaEntidades,pJogador, sf::Vector2f(500.f, 400.f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Cobra(pJogador, sf::Vector2f(800.f, 600.f), sf::Vector2f(50.0f, 50.0f)));

	//obstaculos
	//teias
	listaEntidades.addEntidade(new Caixa(sf::Vector2f(400.0f, 300.0f), sf::Vector2f(100.0f, 100.0f)));
	listaEntidades.addEntidade(new Caixa(sf::Vector2f(300.0f, 300.0f), sf::Vector2f(100.0f, 100.0f)));
	listaEntidades.addEntidade(new Caixa(sf::Vector2f(200.0f, 300.0f), sf::Vector2f(100.0f, 100.0f)));
	listaEntidades.addEntidade(new Caixa(sf::Vector2f(100.0f, 300.0f), sf::Vector2f(100.0f, 100.0f)));
	//espinhos
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(850.f, 625.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(1000.f, 625.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(2000.f, 800.f)));

	//portais
	listaEntidades.addEntidade(new Portal(pJogador, sf::Vector2f(100.f, 100.f), sf::Vector2f(700.0f, 300.0f), sf::Vector2f(70.f, 70.f)));
	listaEntidades.addEntidade(new Portal(pJogador, sf::Vector2f(100.f, 100.f), sf::Vector2f(1200.0f, 300.0f), sf::Vector2f(70.f, 70.f)));

	for (int i = 0; i < listaEntidades.getTamanho(); i++) {
		/// 1 = teia
		/// 6 = espinhos
		/// 7 = portal
		if (listaEntidades[i]->getID() == 1 || listaEntidades[i]->getID() == 6 || listaEntidades[i]->getID() == 7) {
			listaObstaculos.addEntidade(listaEntidades[i]);
		}
		/// 2 = cobra
		/// 4 = morcego
		/// 
		else if (listaEntidades[i]->getID() == 2 || listaEntidades[i]->getID() == 4) {
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

void FaseCastelo::update()
{
	sf::View view;
	while (pGrafico->verificaJanelaAberta()) {
		pEvento->exec();
		pGrafico->limpaJanela();
		pGrafico->getJanela()->setView(view);
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
		}
		pGrafico->mostraElementos();
		pJogador->setEspadaPosicao(sf::Vector2f(0.0f, 5000.0f));
	}
}

void FaseCastelo::render()
{
}
