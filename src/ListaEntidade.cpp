#include "ListaEntidade.h"

List::ListaEntidade::ListaEntidade()
{
}

List::ListaEntidade::~ListaEntidade()
{
	//lista.limpar();
}

void List::ListaEntidade::addEntidade(Entidades::Entidade* pEntidade)
{
	if (pEntidade == NULL) {
		std::cout << "Ponteiro vazio em addEntidade" << std::endl;
	}
	lista.push(pEntidade);
}

void List::ListaEntidade::removeEntidade(Entidades::Entidade* pEntidade)
{
	if (pEntidade == NULL) {
		std::cout << "Ponteiro vazio em removeEntidade" << std::endl;
	}
	lista.pop(pEntidade);
}

void List::ListaEntidade::removeEntidade(unsigned int index)
{
	lista.pop(index);
}

void List::ListaEntidade::limpar()
{
	lista.limpar();
}

unsigned int List::ListaEntidade::getTamanho()
{
	return lista.getTamanho();
}

Entidades::Entidade* List::ListaEntidade::operator[](int index)
{
	return	lista[index];
}
