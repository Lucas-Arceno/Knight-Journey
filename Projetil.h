#pragma once
#include "Entidade.h"
#include "Jogador.h"
#include <math.h>

class Projetil : public Entidade
{
private:
	bool colisaoProjetil = true;
	int contTempVida = 0;
	// Coordenadas que o projetil deverá ir ( diferença de pos do morcego e do player )
	sf::Vector2f Direcao; 
	sf::Vector2f posJogador;
	
public:
	Jogador* pJogador;
	std::list<Jogador*>* pJogadores;

	Projetil(std::list<Jogador*>* pJogadores,sf::Vector2f posicao = sf::Vector2f(5.f, 5.f), sf::Vector2f tamanho = sf::Vector2f(20.f, 10.f));
	~Projetil();

	void update();
	void updateMovimento();
	void updateProjetil(float posX, float posY);
	sf::Vector2f normalizedVector(sf::Vector2f direcao); // Creditos : www.youtube.com/watch?v=_Qc_cj1Nggw&list=LL&index=14
};

