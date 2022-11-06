#pragma once
#include <SFML/Graphics.hpp>

class Colisao
{
private:
	sf::RectangleShape& corpo;
public:
	Colisao(sf::RectangleShape& corpo);
	~Colisao();

	void Move(float dx, float dy) { corpo.move(dx, dy); }

	bool verificaColisao(sf::RectangleShape outroCorpo);
	bool CheckCollision(Colisao outro, float push);
	sf::Vector2f GetPosition() { return corpo.getPosition(); }
	sf::Vector2f GetHalfSize() { return corpo.getSize() / 2.0f; }
};

