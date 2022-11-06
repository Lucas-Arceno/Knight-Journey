#pragma once
#include "Entidade.h"
#include "Lista.h"

namespace List {
	class ListaEntidade
	{
	private:
		Lista<Entidade>lista;

	public:
		ListaEntidade();
		~ListaEntidade();

		void addEntidade(Entidade* pEntidade);
		void removeEntidade(Entidade* pEntidade);
		void removeEntidade(unsigned int index);
		unsigned int getTamanho();
		Entidade* operator[](int index);
	};
}

