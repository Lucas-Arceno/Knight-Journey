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
	

	// Função simples para ver se houve colisão
	bool verificaColisao(sf::RectangleShape outroCorpo);

	// Além de conferir se houve colisão, a função verificaEColide também empurra em sentido contrario qualquer corpo colidindo.
    // Feito com base em : www.youtube.com/watch?v=l2iCYCLi6MU&list=PL21OsoBLPpMOO6zyVlxZ4S4hwkY_SLRW9&index=13
	bool verificaEColide(calculoColisao outro, float push);
	sf::Vector2f GetPosition() { return corpo.getPosition(); }
	sf::Vector2f GetHalfSize() { return corpo.getSize() / 2.0f; }
};

