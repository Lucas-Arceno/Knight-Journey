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
	Morcego Joao(&Teste, sf::Vector2f(500.f, 400.f), sf::Vector2f(50.0f, 50.0f));
	Cobra Jorge(&Teste, sf::Vector2f(800.f, 750.f), sf::Vector2f(50.0f, 50.0f));

	Plataforma chao(sf::Vector2f(200.0f, 700.0f), sf::Vector2f(400.0f, 50.0f));

	GerenciadorColisoes Colisao(&Teste, &listaInimigos, &listaPlataformas);

	listaEntidades.addEntidade(&Teste);
	listaEntidades.addEntidade(&Joao);
	listaEntidades.addEntidade(&Jorge);
	listaEntidades.addEntidade(&chao);

	listaInimigos.addEntidade(&Joao);
	listaInimigos.addEntidade(&Jorge);

	listaPlataformas.addEntidade(&chao);

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

		Colisao.updateColisao();
;
		Teste.collisionWindow(pGrafico->getJanela()->getSize().y);;

		for (int i = 0; i < listaEntidades.getTamanho(); i++) {
			pGrafico->desenhaElementos(listaEntidades[i]->getCorpo());
		}

		pGrafico->mostraElementos();
	}
}
