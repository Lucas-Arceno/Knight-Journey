#include "Rei.h"


Rei::Rei(Jogador* pJogador, sf::Vector2f posicao, sf::Vector2f tamanho) : Inimigo(5, pJogador, posicao, tamanho), vidaMaxima(1000)
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
	cont_DMG++;
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
		ataqueJogador(posJogador, posInimigo);
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
void Rei::ataqueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo) {
	
	if (cooldownPulo == false) {
		this->velocidade.y -= 40.0 * this->gravity;
		cooldownPulo = true;
		cont_DMG = 0;
	}
	
	
	
	//.top RETORNA FLOAT.
	//if (this->getCorpo().getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds().top)) {
	//	updateDano(5000);
	//}
	// 
	// SOLUÇÃO TEMPORARIA ? 
	// PENSAR EM MANEIRAS DE PEGAR APENAS A COLISÃO INFERIOR DO REI OU A SUPERIOR DO JOGADOR.
	// REI CONTINUA EMPURRANDO JOGADOR
	if (cont_DMG < 100) {
		updateDano(5);
	}
	else {
		updateDano(2);
	}
}
