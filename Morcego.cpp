#include "Morcego.h"


Morcego::Morcego(List::ListaEntidade* pListaEntidade, Jogador* pJogador, sf::Vector2f posicao, sf::Vector2f tamanho) : Inimigo(4, pJogador, posicao, tamanho), vidaMaxima(100), projetil()
{
	this->pListaEntidade = pListaEntidade;
	this->vida = vidaMaxima;
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/morcego.png");
	this->corpo.setTexture(&texture);
	projetil = new Projetil(pJogador);
	this->pListaEntidade->addEntidade(projetil);
}

Morcego::~Morcego()
{
}

void Morcego::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	if (posJogador.x - posInimigo.x > 200.0f) {
		corpo.move(1.f, 0.0f);
	}
	else {
		corpo.move(-1.f, 0.0f);
	}
	if (posJogador.y - posInimigo.y > 100.0f) {
		corpo.move(0, 1.f);
	}
	else {
		corpo.move(0, -1.f);
	}
}

void Morcego::updateEmpuxo()
{
	//Gravity
	this->velocidade.y += 1.0 * this->gravity;
	if (std::abs(this->velocidade.x) > this->velocidadeMaxY) {
		this->velocidade.y = this->velocidadeMaxY * ((this->velocidade.y < 0.f) ? -1.f : 1.f);
	}

	//Deceleration
	this->velocidade *= this->drag;

	//Limit deceleration
	if (std::abs(this->velocidade.x) < this->velocidadeMin) {
		this->velocidade.x = 0.0f;
	}
	if (std::abs(this->velocidade.y) < this->velocidadeMin) {
		this->velocidade.y = 0.0f;
	}

	this->corpo.move(-(this->velocidade));
}

void Morcego::update()
{
	updateMovimento();
	updatePhysics();
	updateEmpuxo();
	verificaDano();
	// Gambiarra para passar a pos do inimigo
	sf::Vector2f posInimigo = corpo.getPosition();
	projetil->updateProjetil(posInimigo.x, posInimigo.y);
}

void Morcego::updateMovimento()
{
	sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) < 300 && fabs(posJogador.y - posInimigo.y) < 300) {
		persegueJogador(posJogador, posInimigo);
	}
}
