#include "Game.h"

Game::Game() : pGrafico(pGrafico->getGerenciadorGrafico())
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
	Jogador Teste(sf::Vector2f(50.f, 50.f), sf::Vector2f(100.f, 100.f));
	Morcego Joao(&Teste, sf::Vector2f(500.f, 400.f), sf::Vector2f(50.f, 50.f));
	Cobra Jorge(&Teste, sf::Vector2f(800.f, 750.f), sf::Vector2f(50.f, 50.f));

	listaEntidades.addEntidade(&Teste);
	listaEntidades.addEntidade(&Joao);
	listaEntidades.addEntidade(&Jorge);

	while (pGrafico->verificaJanelaAberta()) {
		sf::Event evento;
		if (pGrafico->getJanela()->pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				pGrafico->fechaJanela();
			}
			else if (evento.type == sf::Event::KeyPressed) {
				if (evento.key.code == sf::Keyboard::Escape) {
					pGrafico->fechaJanela();
				}
			}
		}
		pGrafico->limpaJanela();

		for (int i = 0; i < listaEntidades.getTamanho(); i++) {
			listaEntidades[i]->update();
		}

		Joao.GetColisao().CheckCollision(Teste.GetColisao(), 0.0f);
		Jorge.GetColisao().CheckCollision(Teste.GetColisao(), 1.0f);

		Teste.checkColisao(Jorge.getCorpo());
		Teste.collisionWindow(pGrafico->getJanela()->getSize().y);;


		pGrafico->desenhaElementos(Teste.getCorpo());
		pGrafico->desenhaElementos(Jorge.getCorpo());
		pGrafico->desenhaElementos(Joao.getCorpo());
		pGrafico->mostraElementos();
	}
}
