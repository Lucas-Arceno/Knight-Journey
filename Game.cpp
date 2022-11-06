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
	//Jogador 
	Jogador Teste(sf::Vector2f(50.f, 50.f), sf::Vector2f(100.f, 100.f));

	//Inimigos
	Morcego Joao(&Teste, sf::Vector2f(500.f, 400.f), sf::Vector2f(50.0f, 50.0f));
	Cobra Jorge(&Teste, sf::Vector2f(800.f, 600.f), sf::Vector2f(50.0f, 50.0f));
	Cobra Jorge1(&Teste, sf::Vector2f(400.f, 100.f), sf::Vector2f(50.0f, 50.0f));
	Cobra Jorge2(&Teste, sf::Vector2f(10.f, 500.f), sf::Vector2f(50.0f, 50.0f));

	//Plataformas
	Plataforma chao(sf::Vector2f(200.0f, 700.0f), sf::Vector2f(5000.0f, 50.0f));

	//Obstaculos
	Caixa caixa(sf::Vector2f(300.0f, 300.0f), sf::Vector2f(60.0f, 60.0f));

	GerenciadorColisoes GerenciadorColisoes(&Teste, &listaInimigos, &listaPlataformas, &listaObstaculos);

	//add na lista entidades geral
	listaEntidades.addEntidade(&Teste);
	listaEntidades.addEntidade(&Joao);
	listaEntidades.addEntidade(&Jorge);
	listaEntidades.addEntidade(&Jorge1);
	listaEntidades.addEntidade(&Jorge2);
	listaEntidades.addEntidade(&caixa);
	listaEntidades.addEntidade(&chao);

	//add na lista de inimigos
	listaInimigos.addEntidade(&Joao);
	listaInimigos.addEntidade(&Jorge);
	listaInimigos.addEntidade(&Jorge1);
	listaInimigos.addEntidade(&Jorge2);

	//add na lista de plataformas
	listaPlataformas.addEntidade(&chao);

	//add na lista de obstaculos
	listaObstaculos.addEntidade(&caixa);

	while (pGrafico->verificaJanelaAberta()) {
		pEvento->exec();
		pGrafico->limpaJanela();

		for (int i = 0; i < listaEntidades.getTamanho(); i++) {
			listaEntidades[i]->update();
		}

		GerenciadorColisoes.updateColisao();

		for (int i = 0; i < listaEntidades.getTamanho(); i++) {
			pGrafico->desenhaElementos(listaEntidades[i]->getCorpo());
		}
		
		// Solução temporaria -- Lista de morcego talvez ?
		pGrafico->desenhaElementos(Joao.projetil.getCorpo());

		pGrafico->mostraElementos();
	}
}
