#include "projetilEspada.h"

projetilEspada::projetilEspada(sf::Vector2f posicao, sf::Vector2f tamanho) : Entidade(11, posicao, tamanho)
{
	this->corpo.setFillColor(sf::Color::Yellow);
}

projetilEspada::~projetilEspada() {

}

void projetilEspada::update()
{
	//updatePhysics();
	
	if (disparo == true) {
		timerVida++;
		updateMovimento();

		if (timerVida > 50) {
			timerVida = 0;
			disparo = false;
			printf("timerVida \n");
			corpo.setPosition(5000, 5000);
		}
	}
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
		corpo.setPosition(posJogador);
		disparo = true;
	}
}


