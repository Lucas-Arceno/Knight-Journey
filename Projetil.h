#pragma once
#include "Entidade.h"
#include <math.h>

class Projetil : public Entidade
{
private:
	bool colisaoProjetil = 0;
	//sf::Vector2f posJogador;
	sf::Vector2f Direcao; // Coordenadas que o projetil deverá ir ( diferença de pos do morcego e do player )
	int contTempVida = 0;

public:

	Projetil(sf::Vector2f posicao = sf::Vector2f(5.f, 5.f), sf::Vector2f tamanho = sf::Vector2f(20.f, 10.f));
	~Projetil();

	void update();
	void updateMovimento();


	// Gambiarra, alterar os parametros de update e updatemovimento transforma a classe em abstrata -- Procurar solução melhor
	// Atualmente recebendo separadamente o valor x e y da posição -- Não consegui passar como um vector2f
	void updateProjetil(float posX, float posY, float JposX, float JposY);
	void updateMovimentoProjetil(float posX, float posY, float JposX, float JposY);

};

