#include "Cobra.h"

Entidades::Personagens::Inimigos::Cobra::Cobra(std::list<Entidades::Personagens::Jogadores::Jogador*>* pJogadores, sf::Vector2f posicao, sf::Vector2f tamanho) : Entidades::Personagens::Inimigos::Inimigo(21, pJogadores, posicao, tamanho), vidaMaxima(2), venenosa(false)
{
	int aux = rand() % 2 + 1;
	if (aux == 1) {
		this->venenosa = false;
		this->texture.loadFromFile("assets/cobra.png");
	}
	if (aux == 2) {
		this->venenosa = true;
		this->texture.loadFromFile("assets/cobravenenosa.png");
	}
	setVida(vidaMaxima);
	this->corpo.setFillColor(sf::Color::White);
	this->corpo.setTexture(&texture);
}

Entidades::Personagens::Inimigos::Cobra::~Cobra()
{
}

void Entidades::Personagens::Inimigos::Cobra::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	if (posJogador.x - posInimigo.x > 0.0f) {
		corpo.move(1.f, 0.0f);
	}
	else {
		corpo.move(-1.f, 0.0f);
	}
}


void Entidades::Personagens::Inimigos::Cobra::update()
{
	updateMovimento();
	updatePhysics();	
}

void Entidades::Personagens::Inimigos::Cobra::updateMovimento()
{
	sf::Vector2f posInimigo = corpo.getPosition();
	sf::Vector2f posJogador;

	for (auto const& pJogador : *pJogadores)
	{
		if (pJogador == pJogadores->front()) {
			posJogador = pJogador->getCorpo().getPosition();
		}
		else {
			if (pJogador->getCorpo().getPosition().x < posJogador.x) {
				posJogador = pJogador->getCorpo().getPosition();
			}
		}
	}

	if (fabs(posJogador.x - posInimigo.x) <= 300 && fabs(posJogador.y - posInimigo.y) <= 300) {
		persegueJogador(posJogador, posInimigo);
	}
	else randomMovimento();
}

void Entidades::Personagens::Inimigos::Cobra::reagir() {
	if (this->venenosa == true) {
		updateDanotest(2);
	}
	else {
		updateDanotest(1);
	}
}