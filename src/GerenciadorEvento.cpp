#include "GerenciadorEvento.h"

Gerenciadores::GerenciadorEvento* Gerenciadores::GerenciadorEvento::pEvento = nullptr;

Gerenciadores::GerenciadorEvento::GerenciadorEvento() : pJogador(nullptr), pGrafico(pGrafico->getGerenciadorGrafico()) {

}

Gerenciadores::GerenciadorEvento::~GerenciadorEvento()
{
}

Gerenciadores::GerenciadorEvento* Gerenciadores::GerenciadorEvento::getGerenciadorEvento()
{
	if (pEvento == nullptr) {
		pEvento = new GerenciadorEvento();
	}
	return pEvento;
}

void Gerenciadores::GerenciadorEvento::setJogador(Entidades::Personagens::Jogadores::Jogador* pJogador)
{
	this->pJogador = pJogador;
}

void Gerenciadores::GerenciadorEvento::verificarTeclaPressionada(sf::Keyboard::Key tecla)
{
	if (tecla == sf::Keyboard::Escape) {
		pGrafico->fechaJanela();
	}
	if (tecla == sf::Keyboard::P) {
		bool pausado = true;
		sf::Event evento2{};
		while (pausado == true) {
			if (pGrafico->getJanela()->pollEvent(evento2)) {
				if (evento2.type == sf::Event::KeyPressed) {
					if (evento2.key.code == sf::Keyboard::B) {
						pausado = false;
					}
				}
			}
		}
	}
}

void Gerenciadores::GerenciadorEvento::verificarTeclaSolta(sf::Keyboard::Key tecla)
{
}

void Gerenciadores::GerenciadorEvento::exec()
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
