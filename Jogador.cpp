#include "Jogador.h"

Entidades::Personagens::Jogadores::Jogador::Jogador(sf::Vector2f posicao, sf::Vector2f tamanho) : Entidades::Personagens::Personagem(0,posicao, tamanho)
{
	initVariables();
	initPhysics();
	invFrame = 0;
	pontos = 0;
}

Entidades::Personagens::Jogadores::Jogador::~Jogador()
{
}

void Entidades::Personagens::Jogadores::Jogador::setListaEntidade(List::ListaEntidade* pListaEntidade)
{
	this->pListaEntidade = pListaEntidade;
	espadaP = new projetilEspada;
	this->pListaEntidade->addEntidade(espadaP);
}

void Entidades::Personagens::Jogadores::Jogador::initVariables()
{
	//Personagem e afins
	this->coldownPulo = false;
	this->corpo.setFillColor(sf::Color::Blue);

	//Textura e cor
	this->corpo.setFillColor(sf::Color::White);
	this->texture.loadFromFile("assets/knight.png");
	this->corpo.setTexture(&texture);
}

const sf::FloatRect Entidades::Personagens::Jogadores::Jogador::getGlobalBounds() const
{
	return corpo.getGlobalBounds();
}

void Entidades::Personagens::Jogadores::Jogador::setPosition(const float x, const float y)
{
	this->corpo.setPosition(x, y);
}

int Entidades::Personagens::Jogadores::Jogador::getInvFrame()
{
	return invFrame;
}

void Entidades::Personagens::Jogadores::Jogador::setInvFrame()
{
	invFrame = 1;
}

int Entidades::Personagens::Jogadores::Jogador::getPontucao()
{
	return this->pontos;
}

void Entidades::Personagens::Jogadores::Jogador::givePontuacao(int pts)
{
	pontos = pontos + pts;
	printf("pontuacao %d \n", pontos);
}

void Entidades::Personagens::Jogadores::Jogador::atacarDir()
{
	posJogador = corpo.getPosition();
	espadaP->disparoEspada(posJogador, true);
}

void Entidades::Personagens::Jogadores::Jogador::atacarEsq()
{
	posJogador = corpo.getPosition();
	espadaP->disparoEspada(posJogador, false);
}

void Entidades::Personagens::Jogadores::Jogador::resetVelocity()
{
	this->velocidade.y = 0.0f;
}

void Entidades::Personagens::Jogadores::Jogador::move(const float dir_x, const float dir_y)
{
	//Acceleration
	this->velocidade.x += dir_x * this->acceleration;

	//Limit velocity
	if (std::abs(this->velocidade.x) > this->velocidadeMax) {
		this->velocidade.x = this->velocidadeMax * ((this->velocidade.x < 0.f) ? -1.f : 1.f);
	}
}

void Entidades::Personagens::Jogadores::Jogador::setVelocityX(float vel_x)
{
	this->velocidade.x = vel_x;
}

void Entidades::Personagens::Jogadores::Jogador::setVelocityY(float vel_y)
{
	this->velocidade.y = vel_y;
}

void Entidades::Personagens::Jogadores::Jogador::operator- (int dano)
{
	this->giveDano(dano);
	this->setInvFrame();
}

void Entidades::Personagens::Jogadores::Jogador::operator++() {
	this->givePontuacao(5);
}