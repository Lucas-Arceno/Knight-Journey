#include "ListaEntidade.h"

List::ListaEntidade::ListaEntidade()
{
}

List::ListaEntidade::~ListaEntidade()
{
	lista.limpar();
}

void List::ListaEntidade::addEntidade(Entidade* pEntidade)
{
	if (pEntidade == NULL) {
		std::cout << "Ponteiro vazio em addEntidade" << std::endl;
	}
	lista.push(pEntidade);
}

void List::ListaEntidade::removeEntidade(Entidade* pEntidade)
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

unsigned int List::ListaEntidade::getTamanho()
{
	return lista.getTamanho();
}

Entidade* List::ListaEntidade::operator[](int index)
{
	return	lista[index];
}
