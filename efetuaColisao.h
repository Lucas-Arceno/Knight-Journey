#pragma once
#include <SFML/Graphics.hpp>

class calculoColisao
{
private:
	sf::RectangleShape& corpo;
public:
	calculoColisao(sf::RectangleShape& corpo);
	~calculoColisao();

	void Move(float dx, float dy) { corpo.move(dx, dy); }

	bool verificaColisao(sf::RectangleShape outroCorpo);
	bool CheckCollision(calculoColisao outro, float push);
	sf::Vector2f GetPosition() { return corpo.getPosition(); }
	sf::Vector2f GetHalfSize() { return corpo.getSize() / 2.0f; }
};

