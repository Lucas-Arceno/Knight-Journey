#include "JogadorPrincipal.h"

Entidades::Personagens::Jogadores::JogadorPrincipal::JogadorPrincipal(sf::Vector2f posicao, sf::Vector2f tamanho) : vidaMaxima(20), Jogador(posicao, tamanho)
{
	this->vida = vidaMaxima;
	this->animState = IDLE;
	this->currentFrame = sf::IntRect(0, 0, 96, 96);
	initSprite();
}

Entidades::Personagens::Jogadores::JogadorPrincipal::~JogadorPrincipal()
{
}

void Entidades::Personagens::Jogadores::JogadorPrincipal::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

const bool& Entidades::Personagens::Jogadores::JogadorPrincipal::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch) {
		this->animationSwitch = false;
	}
	return anim_switch;
}

void Entidades::Personagens::Jogadores::JogadorPrincipal::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Entidades::Personagens::Jogadores::JogadorPrincipal::initSprite()
{
	this->sprite.setScale(sf::Vector2f(1.5, 1.5));
}

void Entidades::Personagens::Jogadores::JogadorPrincipal::update()
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

void Entidades::Personagens::Jogadores::JogadorPrincipal::updateMovimento()
{
	this->animState = JogadorPrincipal_Animation_States::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->move(-1.0f, 0.f);
		this->animState = JogadorPrincipal_Animation_States::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->move(1.f, 0.f);
		this->animState = JogadorPrincipal_Animation_States::MOVING_RIGHT;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && coldownPulo == true)) {
		this->velocidade.y -= 20 * this->gravity;
		this->animState = JogadorPrincipal_Animation_States::JUMPING;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		atacarEsq();
		this->animState = JogadorPrincipal_Animation_States::HIT_LEFT;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		atacarDir();
		this->animState = JogadorPrincipal_Animation_States::HIT_RIGHT;
	}
	sprite.setPosition(corpo.getPosition());
}

void Entidades::Personagens::Jogadores::JogadorPrincipal::updateAnimations()
{
	if (this->animState == JogadorPrincipal_Animation_States::IDLE) {
		texture.loadFromFile("assets/Pixel Art Crusader/Crusader 1/Crusader-1-Idle.png");
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
	else if (this->animState == JogadorPrincipal_Animation_States::MOVING_RIGHT) {
		texture.loadFromFile("assets/Pixel Art Crusader/Crusader 1/Crusader-1-Running.png");
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
	else if (this->animState == JogadorPrincipal_Animation_States::MOVING_LEFT) {
		this->texture.loadFromFile("assets/Pixel Art Crusader/Crusader 1/Crusader-1-Running.png");
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
	else if (this->animState == JogadorPrincipal_Animation_States::HIT_LEFT) {
		this->texture.loadFromFile("assets/Pixel Art Crusader/Crusader 1/Crusader-1-Attacking.png");
		sprite.setTexture(texture);
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch()) {
			this->currentFrame.top = 0;
			this->currentFrame.left += 112;
			if (this->currentFrame.left >= 1456) {
				this->currentFrame.left = 0;
			}

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		this->sprite.setScale(-1, 1);
		this->espadaP->setScalee(-1, 1);
		this->sprite.setOrigin(50, 50);
	}
	else if (this->animState == JogadorPrincipal_Animation_States::HIT_RIGHT) {
		this->texture.loadFromFile("assets/Pixel Art Crusader/Crusader 1/Crusader-1-Attacking.png");
		sprite.setTexture(texture);
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch()) {
			this->currentFrame.top = 0;
			this->currentFrame.left += 112;
			if (this->currentFrame.left >= 1456) {
				this->currentFrame.left = 0;
			}

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		this->sprite.setScale(1, 1);
		this->espadaP->setScalee(1, 1);
		this->sprite.setOrigin(50, 50);
	}
}
