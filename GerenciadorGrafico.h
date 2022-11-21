#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

//Baseado no video do monitor : https://www.youtube.com/watch?v=RXmFcBGD8T8

namespace Gerenciadores {
	class GerenciadorGrafico
	{
	private:
		sf::RenderWindow* window;

		/*Singleton desing pattern*/
		static GerenciadorGrafico* pGraphics;
	private:
		GerenciadorGrafico();
	public:
		~GerenciadorGrafico();
		sf::RenderWindow* getJanela();
		const bool verificaJanelaAberta();
		static GerenciadorGrafico* getGerenciadorGrafico();
		void limpaJanela();
		void desenhaSprites(sf::Sprite sprite);
		void desenhaElementos(sf::RectangleShape body);
		void mostraElementos();
		void fechaJanela();
		void setView(sf::Vector2f(pos));
	};
}

