#pragma once
#include "ListaEntidade.h"
#include "Personagem.h"
#include "projetilEspada.h"
#include "Save.h"
#include <iostream>

class Jogador : public Personagem
{
protected:
	//Animation
	sf::Vector2i size;
	sf::Clock animationTimer;
	sf::IntRect currentFrame;
	short animState;
	bool animationSwitch;

	List::ListaEntidade* pListaEntidade;
	bool coldownPulo;

	bool cd_ATK = false; // cooldown ataque

	int invFrame; // Frame de invencibilidade.
	int cont_CD = 0; // contador cooldown

	Save gravador;

	int pontos = 0; // Pontuação
	int idJogador = 3; // id para diferenciar entre jogador 1 ou 2

	sf::Vector2f posJogador; // Posição do player para a espada
public:
	sf::Sprite sprite;
	projetilEspada* espadaP;

public:
	//Constructors
	Jogador(sf::Vector2f posicao = sf::Vector2f(0.f, 0.f), sf::Vector2f tamanho = sf::Vector2f(50.f, 50.f));
	~Jogador();
	
	//
	void setListaEntidade(List::ListaEntidade* pListaEntidade);

	//Init variaveis
	void initVariables();

	//Pegar posicoes 
	const sf::FloatRect getGlobalBounds() const;

	//Pulo manager
	void setColdownPulo(bool cd) { this->coldownPulo = cd; }

	//Movimentacao Jogador
	void move(const float dir_x, const float dir_y);
	void setPosition(const float x, const float y);

	//iFrame
	int getInvFrame();
	void setInvFrame();

	//Pontuação
	int getPontucao();
	void givePontuacao(int pts);
	void salvePontuacao();

	//Ataque
	void atacarDir();
	void atacarEsq();

	//Velocidade
	void resetVelocity();
	void setVelocityX(float vel_x);
	void setVelocityY(float vel_y);

	void operator- (int dano);

	//Updates
	virtual void update() = 0;
	virtual void updateMovimento() = 0;
};

