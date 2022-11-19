#include "Jogador.h"

Jogador::Jogador(sf::Vector2f posicao, sf::Vector2f tamanho) : Personagem(0,posicao, tamanho)
{
	initVariables();
	initPhysics();
	invFrame = 0;
	pontos = 0;
}

Jogador::~Jogador()
{
}

void Jogador::setListaEntidade(List::ListaEntidade* pListaEntidade)
{
	this->pListaEntidade = pListaEntidade;
	espadaP = new projetilEspada;
	this->pListaEntidade->addEntidade(espadaP);
}

void Jogador::initVariables()
{
	//Personagem e afins
	this->coldownPulo = false;
	this->corpo.setFillColor(sf::Color::Blue);

	//Textura e cor
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/knight.png");
	this->corpo.setTexture(&texture);
}

const sf::FloatRect Jogador::getGlobalBounds() const
{
	return corpo.getGlobalBounds();
}

void Jogador::setPosition(const float x, const float y)
{
	this->corpo.setPosition(x, y);
}

int Jogador::getInvFrame()
{
	return invFrame;
}

void Jogador::setInvFrame()
{
	invFrame = 1;
}

int Jogador::getPontucao()
{
	return this->pontos;
}

void Jogador::givePontuacao(int pts)
{
	pontos = pontos + pts;
	printf("pontuacao %d \n", pontos);
}

void Jogador::salvePontuacao() 
{
	gravador.savePontos(pontos, idJogador);
}

void Jogador::atacarDir()
{
	posJogador = corpo.getPosition();
	espadaP->disparoEspada(posJogador, true);
}

void Jogador::atacarEsq()
{
	posJogador = corpo.getPosition();
	espadaP->disparoEspada(posJogador, false);
}

void Jogador::resetVelocity()
{
	this->velocidade.y = 0.0f;
}

void Jogador::move(const float dir_x, const float dir_y)
{
	//Acceleration
	this->velocidade.x += dir_x * this->acceleration;

	//Limit velocity
	if (std::abs(this->velocidade.x) > this->velocidadeMax) {
		this->velocidade.x = this->velocidadeMax * ((this->velocidade.x < 0.f) ? -1.f : 1.f);
	}
}

void Jogador::setVelocityX(float vel_x)
{
	this->velocidade.x = vel_x;
}

void Jogador::setVelocityY(float vel_y)
{
	this->velocidade.y = vel_y;
}

