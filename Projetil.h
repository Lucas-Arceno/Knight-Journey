#pragma once
#include "Entidade.h"

class Projetil : public Entidade 
{
	private: 
		bool colisaoProjetil = 0;

	public:

		Projetil(sf::Vector2f posicao = sf::Vector2f(5.f, 5.f), sf::Vector2f tamanho = sf::Vector2f(20.f, 10.f));
		~Projetil();

		void update();
		void updateMovimento();

		// Gambiarra, alterar os parametros de update e updatemovimento transforma a classe em abstrata -- Procurar solução melhor
		void updateProjetil(float posX, float posY);
		void updateMovimentoProjetil(float posX, float posY);

};

