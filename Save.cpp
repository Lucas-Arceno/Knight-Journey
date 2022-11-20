#include "Save.h"

Save::Save(){
	//loadPontos();
}

Save::~Save() {

}

void Save::savePontos(int pt, int idJog) {

	Gravador.open("Ranking.txt");
	if (!Gravador) {
		cout << "erro ao abrir gravador" << endl;
	}

	info aux2;

	cout << "Digite nome do jogador" << endl;
	cin >> aux2.nome;

	aux2.pont = pt;
	aux2.idJog = idJog;

	informacoes.push_back(aux2);
	// bubble sort
	int i, j;
	for (i = 0; i < informacoes.size() - 1; i++) {
		for (j = 0; j < informacoes.size() - i - 1; j++) {
			if (informacoes[j].pont < informacoes[j + 1].pont) {
				swap(informacoes[j], informacoes[j + 1]);
			}
		}
	}

	if (informacoes.size() > 10) {
		informacoes.resize(10);
	}

	for (int i = 0; i < informacoes.size(); i++) {
		Gravador << informacoes[i].idJog << ' ' << informacoes[i].nome << ' ' << informacoes[i].pont << endl;
	}

	Gravador.close();
}

void Save::loadPontos() {
	
	Leitor.open("Ranking.txt");
	if (!Leitor) {
		cout << "erro ao abrir leitor" << endl;
	}

	info aux;

	while (!Leitor.eof()) {
		Leitor >> aux.idJog >> aux.nome >> aux.pont;
		if (aux.pont != -1) {
			informacoes.push_back(aux);
		}
	}

	Leitor.close();
}