#pragma once
#include "Entidade.h"
#include "Lista.h"

namespace List {
	class ListaEntidade
	{
	private:
		Lista<Entidades::Entidade>lista;

	public:
		ListaEntidade();
		virtual ~ListaEntidade();

		void addEntidade(Entidades::Entidade* pEntidade);
		void removeEntidade(Entidades::Entidade* pEntidade);
		void removeEntidade(unsigned int index);
		void limpar();
		unsigned int getTamanho();
		Entidades::Entidade* operator[](int index);
	};
}

