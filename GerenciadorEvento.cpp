#include "GerenciadorEvento.h"

GerenciadorEvento* GerenciadorEvento::pEvento = nullptr;

GerenciadorEvento::GerenciadorEvento() : pJogador(nullptr), pGrafico(pGrafico->getGerenciadorGrafico()) {

}

GerenciadorEvento::~GerenciadorEvento()
{
}

GerenciadorEvento* GerenciadorEvento::getGerenciadorEvento()
{
	if (pEvento == nullptr) {
		pEvento = new GerenciadorEvento();
	}
	return pEvento;
}

void GerenciadorEvento::setJogador(Jogador* pJogador)
{
	this->pJogador = pJogador;
}

void GerenciadorEvento::verificarTeclaPressionada(sf::Keyboard::Key tecla)
{
	if (tecla == sf::Keyboard::Escape) {
		pGrafico->fechaJanela();
	}
	if (tecla == sf::Keyboard::P) {
		int aux = 1;
		sf::Event evento2{};
		while (aux == 1) {
			if (pGrafico->getJanela()->pollEvent(evento2)) {
				if (evento2.type == sf::Event::KeyPressed) {
					if (evento2.key.code == sf::Keyboard::B) {
						aux = 2;
					}
				}
			}
		}
	}
}

void GerenciadorEvento::verificarTeclaSolta(sf::Keyboard::Key tecla)
{
}

void GerenciadorEvento::exec()
{
	sf::Event evento;
	if (pGrafico->getJanela()->pollEvent(evento)) {
		if (evento.type == sf::Event::KeyPressed) {
			verificarTeclaPressionada(evento.key.code);
		}
		if (evento.type == sf::Event::KeyReleased) {
			verificarTeclaSolta(evento.key.code);
		}
		else if (evento.type == sf::Event::Closed) {
			pGrafico->fechaJanela();
		}
	}
}
