#include "Rei.h"
#include <iostream>

Rei::Rei(Jogador* pJogador, sf::Vector2f posicao, sf::Vector2f tamanho) : Inimigo(24, pJogador, posicao, tamanho), vidaMaxima(1000)
{
	this->corpo.setFillColor(sf::Color::Magenta);
	this->vida = vidaMaxima;
}

Rei::~Rei() {

}

void Rei::update() {
	updateMovimento();
	updatePhysics();

	// cooldown do pulo
	cont_CD++;
	//cont_DMG++;
	if (cont_CD > 200) {
		cooldownPulo = false;
		cont_CD = 0;
		std::cout << "COOLDOWN REI" << std::endl;
	}
}

void Rei::updateMovimento() {
	sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= 400 && fabs(posJogador.y - posInimigo.y) <= 400) {
		persegueJogador(posJogador, posInimigo);
	}
	if (fabs(posJogador.x - posInimigo.x) <= 200 && fabs(posJogador.y - posInimigo.y) <= 100) {
		ataqueJogador();
	}
}

void Rei::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo) {
	if (posJogador.x - posInimigo.x > 0.0f) {
		corpo.move(2.f, 0.0f);
	}
	else {
		corpo.move(-2.f, 0.0f);
	}
}

// O ataque do rei é um super pulo
void Rei::ataqueJogador() {
	
	if (cooldownPulo == false) {
		this->velocidade.y -= 40.0 * this->gravity;
		cooldownPulo = true;
		//cont_DMG = 0;
	}
	
	//TESTES

	sf::Vector2f outroPosicao = pJogador->getCorpo().getPosition();
	sf::Vector2f outroHalfSize = pJogador->getCorpo().getSize() / 2.0f;
	sf::Vector2f thisPosicao = this->getCorpo().getPosition();
	sf::Vector2f thisHalfSize = this->getCorpo().getSize() / 2.0f;

	float deltaX = outroPosicao.x - thisPosicao.x;
	float deltaY = outroPosicao.y - thisPosicao.y;

	float intersecX = abs(deltaX) - (outroHalfSize.x + thisHalfSize.x);
	float intersecY = abs(deltaY) - (outroHalfSize.y + thisHalfSize.y);
	if (intersecX < 0.f && intersecY < 0.f) {
		if (deltaY > 0.0f) {
			printf("teste");
		}
	}
}
