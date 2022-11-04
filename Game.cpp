#include "Game.h"
#include "ColisaoTeste.h"


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
	ColisaoTeste Colisao;
	Jogador Teste(sf::Vector2f(50.f, 50.f), sf::Vector2f(100.f, 100.f));
	Morcego Joao(&Teste, sf::Vector2f(500.f, 400.f), sf::Vector2f(50.f, 50.f));
	Cobra Jorge(&Teste, sf::Vector2f(800.f, 750.f), sf::Vector2f(50.f, 50.f));
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
		Teste.update();
		Jorge.update();
		Joao.update();

		Colisao.checkColisao(Teste.getCorpo(), Jorge.getCorpo());
		Joao.GetColisao().CheckCollision(Teste.GetColisao(), 1.0f);
		Jorge.GetColisao().CheckCollision(Teste.GetColisao(), 1.0f);

		Teste.collisionWindow(pGrafico->getJanela()->getSize().y);;


		pGrafico->desenhaElementos(Teste.getCorpo());
		pGrafico->desenhaElementos(Jorge.getCorpo());
		pGrafico->desenhaElementos(Joao.getCorpo());
		pGrafico->mostraElementos();
	}
}
