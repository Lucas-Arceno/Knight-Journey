#pragma once
#include "GerenciadorGrafico.h"
#include "Jogador.h"

class GerenciadorEvento
{
private:
	GerenciadorGrafico* pGrafico;
	Jogador* pJogador;

	static GerenciadorEvento* pEvento;
	GerenciadorEvento();
public:
	~GerenciadorEvento();
	static GerenciadorEvento* getGerenciadorEvento();
	void setJogador(Jogador* pJogador);
	void verificarTeclaPressionada(sf::Keyboard::Key tecla);
	void verificarTeclaSolta(sf::Keyboard::Key tecla);
	void exec();
};

