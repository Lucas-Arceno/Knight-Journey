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
	verificaDano();
}

void Rei::updateMovimento() {
	sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= 500 && fabs(posJogador.y - posInimigo.y) <= 500) {
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
		this->velocidade.y -= 30.0 * this->gravity;
		this->cooldownPulo = true;
	}
	this->i++;
	if (this->i > 200) {
		this->cooldownPulo = false;
		this->i = 0;
		std::cout << "COOLDOWN REI" << std::endl;
	}
}
