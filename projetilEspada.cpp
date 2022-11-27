#include "projetilEspada.h"



Entidades::Personagens::Jogadores::projetilEspada::projetilEspada(Jogador* pJogador, sf::Vector2f posicao, sf::Vector2f tamanho) : Entidades::ProjetilBase(11, posicao, tamanho)
{
	this->texture.loadFromFile("assets/vento.png");
	this->corpo.setTexture(&texture);
	this->corpo.setFillColor(sf::Color::White);
	this->corpo.setSize(sf::Vector2f(100.0f, 100.0f));
	this->corpo.setPosition(sf::Vector2f(412342.0f, 41231.0f));
	this->pJogador = pJogador;
}

Entidades::Personagens::Jogadores::projetilEspada::~projetilEspada() {

}

void Entidades::Personagens::Jogadores::projetilEspada::update()
{
	//updatePhysics();
	
	if (disparo == true) {
		tempVida++;
		updateMovimento();

		if (tempVida > 20) {
			tempVida = 0;
			disparo = false;
			printf("timerVida espada \n");
			corpo.setPosition(5000, 5000);
		}
	}
	updatePhysics();
	updateEmpuxo();
}

void Entidades::Personagens::Jogadores::projetilEspada::updateEmpuxo()
{
	//Gravity
	(this->velocidade).y += 1 * this->gravity;
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

void Entidades::Personagens::Jogadores::projetilEspada::updateMovimento()
{
	if (isDireita) {
		corpo.move(10.0f, 0);
		//printf("dir + corpo pos %f || %f \n", corpo.getPosition().x, corpo.getPosition().y);
	}
	else {
		corpo.move(-10.0f, 0);
		//printf("esq \n");
	}

}

void Entidades::Personagens::Jogadores::projetilEspada::disparoEspada(bool isDir)
{	
	if (disparo == false) {
		this->isDireita = isDir;
		corpo.setPosition(pJogador->getCorpo().getPosition().x, pJogador->getCorpo().getPosition().y - 50);
		disparo = true;
	}
}

void Entidades::Personagens::Jogadores::projetilEspada::reagir() {

}
