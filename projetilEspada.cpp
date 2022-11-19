#include "projetilEspada.h"

projetilEspada::projetilEspada(sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(11, posicao, tamanho)
{
	this->texture.loadFromFile("assets/vento.png");
	this->corpo.setTexture(&texture);
	this->corpo.setFillColor(sf::Color::White);
	this->corpo.setSize(sf::Vector2f(100.0f, 100.0f));
	this->corpo.setPosition(sf::Vector2f(412342.0f, 41231.0f));
}

projetilEspada::~projetilEspada() {

}

void projetilEspada::update()
{
	//updatePhysics();
	
	if (disparo == true) {
		timerVida++;
		updateMovimento();

		if (timerVida > 20) {
			timerVida = 0;
			disparo = false;
			printf("timerVida \n");
			corpo.setPosition(5000, 5000);
		}
	}
	updatePhysics();
	updateEmpuxo();
}

void projetilEspada::updateEmpuxo()
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

void projetilEspada::updateMovimento()
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

void projetilEspada::disparoEspada(sf::Vector2f posJogador, bool isDir)
{	
	this->isDireita = isDir;
	if (disparo == false) {
		corpo.setPosition(posJogador.x, posJogador.y - 50);
		disparo = true;
	}
}


