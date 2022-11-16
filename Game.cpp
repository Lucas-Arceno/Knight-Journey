#include "Game.h"

struct Ranking {
	int pontos;
};

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
	MenuGameOver MenuGameOver(1200, 800);
	FaseCastelo Castelo;
	FasePalacio Palacio;

	Ranking ListaPontos[10];

	int i = 1;
	while (i != -1) {
		while (pGrafico->verificaJanelaAberta() && i != -1) {
			pEvento->exec();
			pGrafico->limpaJanela();
			if (i == 1) {
				Menu.updateEstado(i);
				Menu.draw(*pGrafico->getJanela());
			}
			else if (i == 2) {
				if (!Castelo.checkTerminou()) {
					Castelo.update();
					if (Castelo.checkMorreu()) {
						i = 5;
					}
				}
				else {
					i = 4;
				}
			}
			else if (i == 3) {
				MenuFases.updateEstado(i);
				MenuFases.draw(*pGrafico->getJanela());
			}
			else if (i == 4) {
				Palacio.update();
			}
			else if (i == 5) {
				MenuGameOver.Update(i);
				MenuGameOver.draw(*pGrafico->getJanela());
			}
			else if (i == 6) {
				ListaPontos[1].pontos = Castelo.getPontuacao();
			}
			pGrafico->mostraElementos();
		}
	}
}
