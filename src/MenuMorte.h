#pragma once
#include "MenuBase.h"
#include "Save.h"

namespace Menus {
	class MenuMorte : public MenuBase
	{
	private:
		int pontPlayers;
		Save saves;
		sf::Text inputText;
		std::string playerInput;

	public:
		MenuMorte(float widht, float height);
		~MenuMorte();

		void updateEstado(int& aux);
		void draw(sf::RenderWindow& window);
		void MoveUp();
		void MoveDown();
		void update();
		
		// Função para somar a pontuação dos jogadores
		void setPontPlayers(int pont);
		// Função para pegar o nome do jogador
		void getStringPlayer();
	};
}


