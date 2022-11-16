#include "efetuaColisao.h"
#include <iostream>

calculoColisao::calculoColisao(sf::RectangleShape& corpo) : corpo(corpo)
{
}

calculoColisao::~calculoColisao()
{
}

bool calculoColisao::verificaColisao(sf::RectangleShape outroCorpo)
{
	if (this->corpo.getGlobalBounds().intersects(outroCorpo.getGlobalBounds())) {
		return true;
	}
	else {
		return false;
	}
}

bool calculoColisao::CheckCollision(calculoColisao outro, float push)
{
	sf::Vector2f outroPosicao = outro.GetPosition();
	sf::Vector2f outroHalfSize = outro.GetHalfSize();
	sf::Vector2f thisPosicao = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize(); 

	float deltaX = outroPosicao.x - thisPosicao.x;
	float deltaY = outroPosicao.y - thisPosicao.y;

	float intersecX = abs(deltaX) - (outroHalfSize.x + thisHalfSize.x);
	float intersecY = abs(deltaY) - (outroHalfSize.y + thisHalfSize.y);

	if (intersecX < 0.f && intersecY < 0.f) {
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersecX > intersecY) {
			if (deltaX > 0.0f) {
				this->Move(intersecX * (1.0f - push), 0.0f);
				outro.Move(-intersecX * push, 0.0f);
			}
			else {
				this->Move(-intersecX * (1.0f - push), 0.0f);
				outro.Move(intersecX * push, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				this->Move(0.0f, intersecY * (1.0f - push));
				outro.Move(0.0f , -intersecY * push);
			}
			else {
				this->Move(0.0f ,-intersecY * (1.0f - push));
				outro.Move(0.0f, intersecY * push);
			}
		}
		return true;
	}

	return false;
}
