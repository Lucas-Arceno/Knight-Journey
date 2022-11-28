#pragma once
#include "ProjetilBase.h"
#include "Jogador.h"

// Projetil feito com a ajuda de : www.youtube.com/watch?v=_Qc_cj1Nggw&list=LL&index=14, mais especificamente a função normalizedVector.

namespace Entidades {
	class Projetil : public ProjetilBase
	{
	private:
		// Coordenadas que o projetil deverá ir ( diferença de pos do morcego e do player )
		sf::Vector2f Direcao;
		sf::Vector2f posJogador;

	public:
		Entidades::Personagens::Jogadores::Jogador* pJogador;
		std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores;

		Projetil(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao = sf::Vector2f(5.f, 5.f), sf::Vector2f tamanho = sf::Vector2f(20.f, 10.f));
		~Projetil();

		void update();
		void updateMovimento();
		void updateProjetil(float posX, float posY);
		void reagir();
		sf::Vector2f normalizedVector(sf::Vector2f direcao); 
	};
}
