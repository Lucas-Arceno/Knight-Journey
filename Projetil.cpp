#include "Projetil.h"
#include <iostream>
using namespace std;

Projetil::Projetil(Jogador* pJogador, sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(2, posicao, tamanho) {
	this->corpo.setFillColor(sf::Color::Red);
	this->pJogador = pJogador;
}


Projetil::~Projetil() {

}

// Redundante 
void Projetil::update()
{
}

// Redundante 
void Projetil::updateMovimento()
{
}

sf::Vector2f Projetil::normalizedVector(sf::Vector2f direcao)
{
	float m = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
	
	sf::Vector2f vetorNormalizado;

	vetorNormalizado.x = direcao.x / m;
	vetorNormalizado.y = direcao.y / m;

	return vetorNormalizado;
}


void Projetil::updateProjetil(float posX, float posY) {
	updateMovimentoProjetil(posX, posY);
}

void Projetil::updateMovimentoProjetil(float posX, float posY) {
	if (colisaoProjetil) { // Reseta o projetil
		corpo.setPosition(sf::Vector2f(posX, posY));

		posJogador = pJogador->getCorpo().getPosition();
		Direcao.x = -(posX - posJogador.x);
		Direcao.y = -(posY - posJogador.y);
		Direcao = normalizedVector(Direcao);
		cout << "DIRECAO BALA : " << Direcao.x << " " << Direcao.y << endl;

		colisaoProjetil = 0;
		contTempVida = 0;
	}
	else {
		//cout << "JOGADOR x e y : " << posJogador.x << " " << posJogador.y << " MORCEGO x e y : " << posX << " " << posY << endl;
		corpo.setPosition(corpo.getPosition() + 10.0f * Direcao); // Movimento da bala, velocidade constante.
		if (this->corpo.getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds())) {
			printf("Acertou\n");
			this->corpo.setPosition(sf::Vector2f(5000.f, 2000.f));
		}
		contTempVida++;
	}
	if (contTempVida >= 200) {
		colisaoProjetil = 1;
	}
}
