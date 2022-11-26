#include "JogadorSecundario.h"

void Entidades::Personagens::Jogadores::JogadorSecundario::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

Entidades::Personagens::Jogadores::JogadorSecundario::JogadorSecundario(sf::Vector2f posicao, sf::Vector2f tamanho) : vidaMaxima(50), Jogador(posicao, tamanho)
{
	this->vida = vidaMaxima;
	this->animState = IDLE2;
	this->currentFrame = sf::IntRect(0, 0, 96, 96);
	initSprite();
}

Entidades::Personagens::Jogadores::JogadorSecundario::~JogadorSecundario()
{
}

const bool& Entidades::Personagens::Jogadores::JogadorSecundario::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch) {
		this->animationSwitch = false;
	}
	return anim_switch;
}

void Entidades::Personagens::Jogadores::JogadorSecundario::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Entidades::Personagens::Jogadores::JogadorSecundario::initSprite()
{
	this->sprite.setScale(sf::Vector2f(1, 1));
}

void Entidades::Personagens::Jogadores::JogadorSecundario::update()
{
	updateMovimento();
	updateAnimations();
	updatePhysics();
	//if (this->getVida() <= 0) {
	//	printf("Morreu");
	//	this->corpo.setPosition(150.f, 600.f);
	//	this->vida = vidaMaxima;
	//}

	if (invFrame > 0) {
		invFrame++;
		if (invFrame > 55)
			invFrame = 0;
	}

	if (cont_CD > 0) {
		cont_CD++;
		if (cont_CD > 75) {
			cont_CD = 0;
			cd_ATK = false;
		}
	}
}

void Entidades::Personagens::Jogadores::JogadorSecundario::updateMovimento()
{
	this->animState = JogadorSecundarioAnimation_States::IDLE2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
		this->move(-1.0f, 0.f);
		this->animState = JogadorSecundarioAnimation_States::MOVING_LEFT2;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		this->move(1.f, 0.f);
		this->animState = JogadorSecundarioAnimation_States::MOVING_RIGHT2;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && coldownPulo == true)) {
		this->velocidade.y -= 20 * this->gravity;
		this->animState = JogadorSecundarioAnimation_States::JUMPING2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
		atacarEsq();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
		atacarDir();
	}
	sprite.setPosition(corpo.getPosition());
}

void Entidades::Personagens::Jogadores::JogadorSecundario::updateAnimations()
{
	if (this->animState == JogadorSecundarioAnimation_States::IDLE2) {
		texture.loadFromFile("assets/Pixel Art Crusader/Crusader 2/Crusader-2-Idle.png");
		sprite.setTexture(texture);
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch()) {
			this->currentFrame.top = 0;
			this->currentFrame.left += 112;
			if (this->currentFrame.left >= 672) {
				this->currentFrame.left = 0;
			}

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		this->sprite.setScale(1, 1);
		this->sprite.setOrigin(50, 50);
	}
	else if (this->animState == JogadorSecundarioAnimation_States::MOVING_RIGHT2) {
		texture.loadFromFile("assets/Pixel Art Crusader/Crusader 2/Crusader-2-Running.png");
		sprite.setTexture(texture);
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch()) {
			this->currentFrame.top = 0;
			this->currentFrame.left += 112;
			if (this->currentFrame.left >= 672) {
				this->currentFrame.left = 0;
			}

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		this->sprite.setScale(1, 1);
		this->sprite.setOrigin(50.f, 50.f);
	}
	else if (this->animState == JogadorSecundarioAnimation_States::MOVING_LEFT2) {
		this->texture.loadFromFile("assets/Pixel Art Crusader/Crusader 2/Crusader-2-Running.png");
		sprite.setTexture(texture);
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch()) {
			this->currentFrame.top = 0;
			this->currentFrame.left += 112;
			if (this->currentFrame.left >= 672) {
				this->currentFrame.left = 0;
			}

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		this->sprite.setScale(-1, 1);
		this->sprite.setOrigin(50, 50);
	}
}

void Entidades::Personagens::Jogadores::JogadorSecundario::reagir() {

}