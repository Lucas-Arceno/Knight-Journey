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
		if (Teste.getGlobalBounds().top + Teste.getGlobalBounds().height > pGrafico->getJanela()->getSize().y) {
			Teste.resetVelocity();
			Teste.setPosition(
				Teste.getGlobalBounds().left, pGrafico->getJanela()->getSize().y - Teste.getGlobalBounds().height
			);
		}
		pGrafico->desenhaElementos(Teste.getCorpo());
		pGrafico->mostraElementos();
	}
}
