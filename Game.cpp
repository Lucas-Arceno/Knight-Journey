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
	std::list<Entidades::Personagens::Jogadores::Jogador*>Jogadores;

	Jogadores.push_back(new Entidades::Personagens::Jogadores::JogadorPrincipal(sf::Vector2f(150.f, 250.f), sf::Vector2f(100.f, 100.f)));

	Menus::Menu Menu(1200, 800);
	Menus::MenuFases MenuFases(1200, 800);
	Menus::MenuEscolhaOnline MenuOnline(1200, 800);
	Menus::MenuMorte MenuMorte(1200, 800);
	Menus::MenuRank MenuRank(1200, 800);

	Fases::FasePalacio Palacio(&Jogadores);
	Fases::FaseCastelo Castelo(&Jogadores);
	
	Ranking ListaPontos[10]{};

	int aux_test = 0;
	int aux_test2 = 0;
	int aux_test3 = 0;
	bool aux_test4 = true;

	int i = 1;
	while (i != -1) {
		while (pGrafico->verificaJanelaAberta() && i != -1) {
			pEvento->exec();
			pGrafico->limpaJanela();
			if (i == 1) {
				Menu.updateEstado(i);
				Menu.draw(*pGrafico->getJanela());
			}
			else if (i == 11) {
				MenuRank.updateEstado(i);
				MenuRank.draw(*pGrafico->getJanela());
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
				Jogadores.push_back(new Entidades::Personagens::Jogadores::JogadorSecundario(sf::Vector2f(150.f, 250.f), sf::Vector2f(100.f, 100.f)));
				Castelo.multiplayer(true);
				i = 7;
				aux_test3 = 1;
			}
			else if (i == 4) {
				if (aux_test3 == 1) {
					Palacio.multiplayer(true);
					aux_test3++;
				}
				if (aux_test == 0) {
					for (auto const& Jogador : Jogadores)
					{
						Jogador->setCorpoPosicao(sf::Vector2f(100, 100));
					}

					Palacio.teste();
					aux_test++;
				}
				Palacio.update();
				if (Palacio.checkTerminou()) {
					i = 5;
				}
			}
			else if (i == 5) {
				if (aux_test4 == true) {
					for (auto const& Jogador : Jogadores)
					{
						MenuMorte.setPontPlayers(Jogador->getPontucao());
					}
					aux_test4 = false;
				}
				MenuMorte.updateEstado(i);
				MenuMorte.draw(*pGrafico->getJanela());
			}
			else if (i == 6) {
				//ListaPontos[1].pontos = Castelo.getPontuacao();
			}
			pGrafico->mostraElementos();
		}
	}
}
