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
	std::list<Jogador*>Jogadores;
	Jogadores.push_back(new JogadorPrincipal(sf::Vector2f(150.f, 250.f), sf::Vector2f(100.f, 100.f)));
	JogadorSecundario* a = new JogadorSecundario(sf::Vector2f(150.f, 250.f), sf::Vector2f(100.f, 100.f));

	Menu Menu(1200, 800);
	MenuFases MenuFases(1200, 800);
	MenuGameOver MenuGameOver(1200, 800);
	MenuEscolhaOnline MenuOnline(1200, 800);

	FasePalacio Palacio(&Jogadores);
	FaseCastelo Castelo(&Jogadores);
	
	Ranking ListaPontos[10];

	int aux_test = 0;
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
				MenuOnline.updateEstado(i);
				MenuOnline.draw(*pGrafico->getJanela());
			}
			else if (i == 7) {
				MenuFases.updateEstado(i);
				MenuFases.draw(*pGrafico->getJanela());
			}
			else if (i == 8) {
				Jogadores.push_back(a);
				Castelo.multiplayer(true);
				Palacio.multiplayer(true);
				i = 7;
			}
			else if (i == 4) {
				if (aux_test == 0) {
					for (auto const& Jogador : Jogadores)
					{
						if (Jogador == (Jogadores).back()) {
							Jogador->setPosition(100, 100);
						}
					}
					Palacio.teste();
					aux_test++;
				}
				Palacio.update();
			}

			else if (i == 5) {
				MenuGameOver.Update(i);
				MenuGameOver.draw(*pGrafico->getJanela());
			}
			else if (i == 6) {
				//ListaPontos[1].pontos = Castelo.getPontuacao();
			}
			pGrafico->mostraElementos();
		}
	}
}
