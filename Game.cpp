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

	Jogadores.push_back(new Entidades::Personagens::Jogadores::JogadorPrincipal(sf::Vector2f(150.f, 250.f), sf::Vector2f(100.f, 100.f)));

	Palacio = new Fases::FasePalacio(&Jogadores);
	Castelo = new Fases::FaseCastelo(&Jogadores);
	exec();
}

Game::~Game()
{
	if (!Castelo) {
		delete Castelo;
	}
	if (!Palacio) {
		delete Palacio;
	}
	for (auto const& Jogador : Jogadores)
	{
		delete Jogador;
	}
	/*Jogadores.clear();*/
}

void Game::exec()
{
	Menus::Menu Menu(1200, 800);
	Menus::MenuFases MenuFases(1200, 800);
	Menus::MenuEscolhaOnline MenuOnline(1200, 800);
	Menus::MenuMorte MenuMorte(1200, 800);
	Menus::MenuRank MenuRank(1200, 800);
	
	Ranking ListaPontos[10]{};

	// Flag usada para inicialização de jogadores
	bool flagJogador = true;
	// Flag usada para o multiplayer
	bool flagMultiplayer = false;
	// Flag usada no fim do jogo
	bool flagPont = true;
	// Flag usada para poder deletar o castelo no estado 4
	bool flagCastelo = true;

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
				if (!Castelo->checkTerminou()) {
					Castelo->update();
					if (Castelo->checkMorreu()) {
						delete Castelo;
						delete Palacio;
						Castelo = NULL;
						Palacio = NULL;
						i = 5;
					}
				}
				else {
					delete Castelo;
					Castelo = NULL;
					flagCastelo = false;
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
				Castelo->multiplayer(true);
				i = 7;
				flagMultiplayer = true;
			}
			else if (i == 4) {
				
				if (flagCastelo) {
					delete Castelo;
					Castelo = NULL;
					flagCastelo = false;
				}

				if (flagMultiplayer) {
					Palacio->multiplayer(true);
					flagMultiplayer = false;
				}

				if (flagJogador) {
					for (auto const& Jogador : Jogadores)
					{
						Jogador->setCorpoPosicao(sf::Vector2f(100, 100));
					}

					Palacio->setListaEnt();
					flagJogador = false;
				}

				Palacio->update();
				if (Palacio->checkTerminou()) {
					i = 5;
				}
			}
			else if (i == 5) {
				if (flagPont) {
					for (auto const& Jogador : Jogadores)
					{
						MenuMorte.setPontPlayers(Jogador->getPontucao());
					}
					flagPont = false;
				}
				MenuMorte.updateEstado(i);
				MenuMorte.getStringPlayer();
				MenuMorte.draw(*pGrafico->getJanela());
			}
			if (i == 66) {
				this->~Game();
				exit(1);
			}
			pGrafico->mostraElementos();
		}
	}
}
