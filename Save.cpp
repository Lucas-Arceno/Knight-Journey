#include "Save.h"
#include <SFML/Graphics.hpp>

Save::Save(){
	//Gravador.open("Ranking.txt");
	//if (!Gravador) {
	//	cout << "erro ao abrir gravador" << endl;
	//}
	//Gravador.close();
	
	loadPontos();
}

Save::~Save() {

}

void Save::savePontos(int pt, string nome) {

	try {
		Gravador.open("Ranking.txt");
		Gravador.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);

		//Auxiliar para copia de informações
		info aux2;
		aux2.nome = nome;
		aux2.pont = pt;

		informacoes.push_back(aux2);

		// Bubble sort
		int i, j;
		for (i = 0; i < informacoes.size() - 1; i++) {
			for (j = 0; j < informacoes.size() - i - 1; j++) {
				if (informacoes[j].pont < informacoes[j + 1].pont) {
					swap(informacoes[j], informacoes[j + 1]);
				}
			}
		}

		// Maximo de 10 scores
		if (informacoes.size() > 10) {
			informacoes.resize(10);
		}

		//Grava a lista em ranking.txt
		for (int i = 0; i < informacoes.size(); i++) {
			Gravador << ' ' << informacoes[i].nome << ' ' << informacoes[i].pont << endl;
		}

		Gravador.close();
	}
	catch (std::exception const& e) {
		cout << "Erro ao ler arquivo : " << e.what() << endl;
	}
}

void Save::loadPontos() {
	
	try {
		Leitor.open("Ranking.txt");
		Leitor.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);

		info aux;

		while (!Leitor.eof()) {
			Leitor >> aux.nome >> aux.pont;
			//cout << "auxNOME : " << aux.nome << " || auxPONT : " << aux.pont << endl;
			if (aux.pont != -1) {
				informacoes.push_back(aux);
			}
		}

		// Leitor sempre duplica a ultima linha
		if (informacoes.size() > 10) {
			informacoes.resize(10);
		}

		Leitor.close();
	}
	catch (std::exception const& e) {
		cout << "Erro ao ler arquivo : " << e.what() << endl;
	}
}

vector<info> Save::getPontos()
{
	return informacoes;
}
