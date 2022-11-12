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
	Menu Menu(1200, 800);
	int i = 1;
	while (pGrafico->verificaJanelaAberta() && i == 1) {
		pEvento->exec();
		pGrafico->limpaJanela();
		Menu.Update(i);
		Menu.draw(*pGrafico->getJanela());
		pGrafico->mostraElementos();
	}
	FaseCastelo Castelo;
	Castelo.update();
}
