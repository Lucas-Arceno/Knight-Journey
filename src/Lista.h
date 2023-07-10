#pragma once
#include <iostream>

namespace List {
	template <class TL>
	class Lista
	{
	private:
		template <class TE>
		class Node {
		private:
			Node<TE>* pProximo;
			Node<TE>* pAnterior;
			TE* pInfo;
		public:
			Node() {
				pProximo = NULL;
				pAnterior = NULL;
				pInfo = NULL;
			}
			~Node() {
				pProximo = NULL;
				pAnterior = NULL;
				pInfo = NULL;
			}

			void setProximo(Node<TE>* pProximo) { this->pProximo = pProximo; }
			Node<TE>* getProximo() { return pProximo; }

			void setAnterior(Node<TE>* pAnteiror) { this->pAnterior = pAnteiror; }
			Node<TE>* getAnterior() { return pAnterior; }

			void setInfo(TE* pInfo) { this->pInfo = pInfo; }
			TE* getInfo() { return pInfo; }

		};

		Node<TL>* pPrimeiro;
		Node<TL>* pUltimo;
		unsigned int tam;

	public:
		Lista();
		~Lista();

		void limpar();
		unsigned int getTamanho() { return tam; }
		TL* operator[](int x);
		void push(TL* pInfo);
		TL* pop(TL* pInfo);
		TL* pop(int index);

	private:
		void setNode(Node<TL>* pNode);
		Node<TL>* getpPrimeiro() { return pPrimeiro; }
		Node<TL>* getpUltimo() { return pUltimo; }
	};

	template <class TL>
	Lista<TL>::Lista() :
		pPrimeiro(), pUltimo(), tam(0) {
		limpar();
	}

	template <class TL>
	Lista<TL>::~Lista() {
		//limpar();
	}

	template <class TL>
	void Lista<TL>::limpar() {
		Node<TL>* paux1;
		Node<TL>* paux2;

		paux1 = pPrimeiro;
		paux2 = paux1;

		while (paux1 != NULL) {
			paux2 = paux1->getProximo();
			delete(paux1->getInfo());
			paux1 = nullptr;
			paux1 = paux2;
			tam--;
		}
		pPrimeiro = NULL;
		pUltimo = NULL;
		
	}

	template <class TL>
	void Lista<TL>::setNode(Node<TL>* pNode) {
		if (pNode != NULL) {
			if (pPrimeiro == NULL) {
				pPrimeiro = pNode;
				pUltimo = pNode;
			}
			else {
				pUltimo->setProximo(pNode);
				pNode->setAnterior(pUltimo);
				pUltimo = pNode;
			}
			tam++;
		}
		else {
			std::cout << "Erro na função setNode Lista<TL>" << std::endl;
		}
	}

	template <class TL>
	TL* Lista<TL>::operator[](int x) {
		if (x >= tam || x < 0) {
			std::cout << "ERROR: Segmentation fault on template list. Exceeded boundaries. Index " << x << " out of " << tam << " elements." << std::endl;
			exit(1);
		}

		Node<TL>* pAux = pPrimeiro;
		for (int i = 0; i < x; i++) {
			pAux = pAux->getProximo();
		}

		if (pAux == nullptr) {
			std::cout << "ERROR: on template operator[] pAux == nullptr." << std::endl;
			exit(1);
		}
		return pAux->getInfo();
	}

	template <class TL>
	void Lista<TL>::push(TL* pInfo) {
		if(pInfo != NULL){
			Node<TL>* pNode = NULL;
			pNode = new Node<TL>();
			pNode->setInfo(pInfo);
			setNode(pNode);
		}
		else {
			std::cout << "Erro na função push Lista<TL>" << std::endl;
		}
	}

	template <class TL>
	TL* Lista<TL>::pop(TL* pInfo) {
		Node<TL>* pAux = pPrimeiro;
		Node<TL>* pPrev = NULL;
		while (pAux != NULL) {
			if (pAux->getInfo() == pInfo) {
				if (pAux == pPrimeiro) {
					pPrimeiro = pAux->getProximo();
				}
				else if (pAux == pUltimo) {
					pUltimo = pAux->getAnterior();
				}
				else {
					pPrev->setProximo(pAux->getProximo());
				}
				delete(pAux);
				tam--;
				return pInfo;
			}
			pPrev = pAux;
			pAux = pAux->getProximo();
		}
		return NULL;
	}

	template <class TL>
	TL* Lista<TL>::pop(int index) {
		if (index >= tam || index < 0) {
			exit(1);
		}

		Node<TL>* pAux = pPrimeiro;
		Node<TL>* pPrev = nullptr;

		for (int i = 0; i < index; i++) {
			pPrev = pAux;
			pAux = pAux->getProximo();
		}

		if (pAux == pPrimeiro) {
			pPrimeiro = pAux->getProximo();
		} 
		else if (pAux == pUltimo) {
			pUltimo = pPrev;
			pPrev->setProximo(nullptr);
		} 
		else {
			pPrev->setProximo(pAux->getProximo());
		}

		TL* pInfo = pAux->getInfo();

		delete (pAux);
		tam--;

		return pInfo;
	}
}



