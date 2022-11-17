#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem
{
protected:
	std::list<Jogador*>* pJogadores;

	int cont_mov; // Contador para o movimento aleatorio;
	int dir_mov; // Direção para o movimento aleatorio;

	int iFrame = 0;
public:
	Inimigo(int id, std::list<Jogador*>* pJogadores,sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
	virtual ~Inimigo(); 

	void updateDano(int dano);
	void randomMovimento();
	virtual void update() = 0;
	virtual void updateMovimento() = 0;
};

