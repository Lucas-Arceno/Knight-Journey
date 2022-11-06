#include "Game.h"

Game::Game() : pGrafico(pGrafico->getGerenciadorGrafico()), pEvento(pEvento->getGerenciadorEvento())
{
	if (pGrafico == nullptr) {
		std::cout << "Nao foi possivel criar um gerenciador grafico." << std::endl;
		exit(1);

	}
	else {
		std::cout << "Gerenciador grafico criado com sucesso." << std::endl;
	}
	exec();
}

Game::~Game()
{
}

void Game::exec()
{
	FaseCastelo Castelo;
	Castelo.update();
	/*
	//Background
	sf::RectangleShape Background;
	Background.setSize(sf::Vector2f(1200.f, 800.f));
	sf::Texture BackgroundT;
	BackgroundT.loadFromFile("assets/backgroud.png");
	Background.setTexture(&BackgroundT);
	//Jogador 
	Jogador Teste(sf::Vector2f(50.f, 50.f), sf::Vector2f(100.f, 100.f));

	//Inimigos
	Morcego Joao(&Teste, sf::Vector2f(500.f, 400.f), sf::Vector2f(50.0f, 50.0f));
	Cobra Jorge(&Teste, sf::Vector2f(800.f, 600.f), sf::Vector2f(50.0f, 50.0f));

	//Plataformas
	Plataforma chao(sf::Vector2f(200.0f, 700.0f), sf::Vector2f(5000.0f, 50.0f));
	Plataforma chao2(sf::Vector2f(250.0f,500.0f), sf::Vector2f(300.0f, 150.0f));
	Plataforma parede(sf::Vector2f(20, 800), sf::Vector2f(100.0f, 5000.0f));

	//Obstaculos
	Caixa caixa(sf::Vector2f(300.0f, 300.0f), sf::Vector2f(50.0f, 50.0f));

	GerenciadorColisoes GerenciadorColisoes(&Teste, &listaInimigos, &listaPlataformas, &listaObstaculos);

	//add na lista entidades geral
	listaEntidades.addEntidade(&Teste);
	listaEntidades.addEntidade(&Joao);
	listaEntidades.addEntidade(&Jorge);
	listaEntidades.addEntidade(&caixa);
	listaEntidades.addEntidade(&chao);
	listaEntidades.addEntidade(&chao2);
	listaEntidades.addEntidade(&parede);

	//add na lista de inimigos
	listaInimigos.addEntidade(&Joao);
	listaInimigos.addEntidade(&Jorge);

	//add na lista de plataformas
	listaPlataformas.addEntidade(&chao);
	listaPlataformas.addEntidade(&chao2);
	listaPlataformas.addEntidade(&parede);

	//add na lista de obstaculos
	listaObstaculos.addEntidade(&caixa);

	while (pGrafico->verificaJanelaAberta()) {
		pEvento->exec();
		pGrafico->limpaJanela();
		pGrafico->desenhaElementos(Background);

		for (int i = 0; i < listaEntidades.getTamanho(); i++) {
			listaEntidades[i]->update();
		}
		GerenciadorColisoes.updateColisao();

		for (int i = 0; i < listaEntidades.getTamanho(); i++) {
			pGrafico->desenhaElementos(listaEntidades[i]->getCorpo());
		}

		pGrafico->mostraElementos();
	}*/

}
