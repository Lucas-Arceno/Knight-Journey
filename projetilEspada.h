#pragma once
#include "Entidade.h"

class projetilEspada : public Entidade 
{
	private:

		int timerVida = 0; // Tempo de vida da espada.
		bool disparo = false;
		bool isDireita; 

	public:

		projetilEspada(sf::Vector2f posicao = sf::Vector2f(150.f, 250.f), sf::Vector2f tamanho = sf::Vector2f(20.f, 10.f));
		~projetilEspada();

		void update();
		void updateMovimento();
		void disparoEspada(sf::Vector2f posJogador, bool isDir);
};

