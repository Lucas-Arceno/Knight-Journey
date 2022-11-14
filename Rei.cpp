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

	// cooldown do pulo
	cont_CD++;
	//cont_DMG++;
	if (cont_CD > 200) {
		cooldownPulo = false;
		cont_CD = 0;
		std::cout << "COOLDOWN REI" << std::endl;
	}
}

void Rei::updateMovimento() {
	sf::Vector2f posJogador = pJogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= 400 && fabs(posJogador.y - posInimigo.y) <= 400) {
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
		this->velocidade.y -= 40.0 * this->gravity;
		cooldownPulo = true;
		//cont_DMG = 0;
	}
	
	
	//FloatRect playerBounds = player.getGlobalBounds();
	//FloatRect wallBounds = parede.getGlobalBounds();
	//// Colisão Topo
	//if (playerBounds.top > wallBounds.top
	//	&& playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
	//	&& playerBounds.left < wallBounds.left + wallBounds.width
	//	&& playerBounds.left + playerBounds.width > wallBounds.left)
	//{
	//	velocidade.y = 0.f;
	//	player.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
	//	cout << "COLISAO TOPO" << endl;
	//}
	//

	sf::FloatRect playerBounds = pJogador->getCorpo().getGlobalBounds();
	sf::FloatRect bossBounds = corpo.getGlobalBounds();

	if (playerBounds.top > bossBounds.top
		&& playerBounds.top + playerBounds.height > bossBounds.top + bossBounds.height
		&& playerBounds.left < bossBounds.left + bossBounds.width
		&& playerBounds.left + playerBounds.width > bossBounds.left)
	{
		printf("colisao embaixo");
			updateDano(5);
	}
	else {
		updateDano(2);
	}
	//if (cont_DMG < 100) {
	//	updateDano(5);
	//}
	//else {
	//	updateDano(2);
	//}
}
