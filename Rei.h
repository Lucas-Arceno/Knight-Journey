#pragma once
#include "Inimigo.h"
#include <iostream>

class Rei : public Inimigo
{

	private:
		const int vidaMaxima;
		bool cooldownPulo = true;
		int i = 0; // Contador para cooldownPulo
	public:
		Rei(Jogador* pJogador, sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
		~Rei();

		void setColdownPulo(bool cd) { this->cooldownPulo = cd; }

		void update();
		void updateMovimento();
		void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
		void ataqueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
};

