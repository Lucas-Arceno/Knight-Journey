#pragma once
#include "Entidade.h"

namespace Entidades {
	class Plataforma : public Entidade
	{
	private:
		const int tipo;
	public:
		Plataforma(sf::Vector2f posicao, sf::Vector2f tamanho, const int tipo);
		~Plataforma();

		void update();
		void updateEmpuxo();
		void updateMovimento();
	};
}


