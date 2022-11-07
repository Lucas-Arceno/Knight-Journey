#pragma once
#include "Entidade.h"
#include "Jogador.h"
#include <math.h>

class Projetil : public Entidade
{
private:
	
	bool colisaoProjetil = 1;
	int contTempVida = 0;
	// Coordenadas que o projetil dever� ir ( diferen�a de pos do morcego e do player )
	sf::Vector2f Direcao; 
	sf::Vector2f posJogador;
	
public:

	Jogador* pJogador;

	Projetil(Jogador *pJogador,sf::Vector2f posicao = sf::Vector2f(5.f, 5.f), sf::Vector2f tamanho = sf::Vector2f(20.f, 10.f));
	~Projetil();

	void update();
	void updateMovimento();


	// Gambiarra, alterar os parametros de update e updatemovimento transforma a classe em abstrata -- Procurar solu��o melhor
	// Atualmente recebendo separadamente o valor x e y da posi��o -- N�o consegui passar como um vector2f
	void updateProjetil(float posX, float posY);
	void updateMovimentoProjetil(float posX, float posY);
	sf::Vector2f normalizedVector(sf::Vector2f direcao); // Creditos : www.youtube.com/watch?v=_Qc_cj1Nggw&list=LL&index=14
};
