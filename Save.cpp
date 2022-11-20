#include "Save.h"

Save::Save(){
	loadPontos();
}

Save::~Save() {

}

bool comparacao(const info& a, const info& b) {
	return a.pont < b.pont;
}


void Save::savePontos(int pt, int idJog) {

	Gravador.open("Ranking.txt", ios::in);
	if (!Gravador) {
		cout << "erro ao abrir gravador" << endl;
	}

	info aux2;

	cout << "Digite nome do jogador" << endl;
	cin >> aux2.nome;

	aux2.pont = pt;
	aux2.idJog = idJog;

	informacoes.push_back(aux2);
	sort(informacoes.begin(), informacoes.end(), comparacao);

	if (informacoes.size() > 10) {
		informacoes.resize(10);
	}

	for (int i = 0; i < informacoes.size(); i++) {
		Gravador << informacoes[i].idJog << ' ' << informacoes[i].nome << ' ' << informacoes[i].pont << endl;
	}

	Gravador.close();
}

void Save::loadPontos() {
	
	Leitor.open("Ranking.txt", ios::in);
	if (!Leitor) {
		cout << "erro ao abrir leitor" << endl;
	}

	info aux;

	while (!Leitor.eof()) {
		Leitor >> aux.idJog >> aux.nome >> aux.pont;
		informacoes.push_back(aux);
	}

	Leitor.close();
}