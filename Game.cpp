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
	MenuFases MenuFases(1200, 800);
	FasePalacio Palacio;
	FaseCastelo Castelo;
	int i = 1;
	while (i != -1) {
		while (pGrafico->verificaJanelaAberta() && i != -1) {
			pEvento->exec();
			pGrafico->limpaJanela();
			if (i == 1) {
				Menu.Update(i);
				Menu.draw(*pGrafico->getJanela());
			}
			else if (i == 2) {
				if (!Castelo.checkTerminou()) {
					Castelo.update();
				}
				else {
					i = 4;
				}
			}
			else if (i == 3) {
				MenuFases.Update(i);
				MenuFases.draw(*pGrafico->getJanela());
			}
			else if (i == 4) {
				Palacio.update();
			}
			pGrafico->mostraElementos();
		}
	}
}
