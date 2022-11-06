#include "FaseCastelo.h"

FaseCastelo::FaseCastelo() : Fase()
{
	this->background.setSize(sf::Vector2f(1200.f, 800.f));
	this->backgroundTexture.loadFromFile("assets/backgroud.png");
	background.setTexture(&backgroundTexture);

	this->pJogador = new Jogador(sf::Vector2f(150.f, 250.f), sf::Vector2f(100.f, 100.f));

	this->GerenciadorColisao = new GerenciadorColisoes(pJogador,&listaInimigos, &listaPlataformas, &listaObstaculos);

	//add na lista entidades geral
	listaEntidades.addEntidade(pJogador);
	listaEntidades.addEntidade(new Morcego(pJogador, sf::Vector2f(500.f, 400.f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Cobra(pJogador, sf::Vector2f(800.f, 600.f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(3,sf::Vector2f(200.0f, 700.0f), sf::Vector2f(5000.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(3,sf::Vector2f(250.0f, 500.0f), sf::Vector2f(300.0f, 150.0f)));
	listaEntidades.addEntidade(new Caixa(sf::Vector2f(300.0f, 300.0f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(3,sf::Vector2f(20, 800), sf::Vector2f(100.0f, 5000.0f)));

	//add na lista de inimigos
	/*listaInimigos.addEntidade(&Joao);
	listaInimigos.addEntidade(&Jorge);

	//add na lista de plataformas
	listaPlataformas.addEntidade(&chao);
	listaPlataformas.addEntidade(&chao2);
	listaPlataformas.addEntidade(&parede);*/

	//add na lista de obstaculos
	//listaObstaculos.addEntidade(new Caixa(sf::Vector2f(300.0f, 300.0f), sf::Vector2f(50.0f, 50.0f)));

}

FaseCastelo::~FaseCastelo()
{
}

void FaseCastelo::update()
{
	while (pGrafico->verificaJanelaAberta()) {
		pEvento->exec();
		pGrafico->limpaJanela();
		pGrafico->desenhaElementos(this->background);

		for (int i = 0; i < listaEntidades.getTamanho(); i++) {
				listaEntidades[i]->update();
		}	
		this->GerenciadorColisao->updateColisao();

		for (int i = 0; i < listaEntidades.getTamanho(); i++) {
			pGrafico->desenhaElementos(listaEntidades[i]->getCorpo());
		}

		pGrafico->mostraElementos();
	}
}

void FaseCastelo::render()
{
}
