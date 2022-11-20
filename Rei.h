#pragma once
#include "Inimigo.h"
#include <iostream>

class Rei : public Inimigo
{
	private:
		const int vidaMaxima;
		bool cooldownPulo = false;
		int cont_CD = 0; // Contador para cooldownPulo
		//int cont_DMG = 0; // Contador para o dano do pulo

	public:
		Rei(std::list<Jogador*>* pJogadores, sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
		~Rei();

		void setColdownPulo(bool cd) { this->cooldownPulo = cd; }

		void update();
		void updateMovimento();
		void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
		void ataqueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
};

