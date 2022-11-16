#include "Save.h"

Save::Save(){
	
	Leitor.open("testejogo11.txt", ios::in);
	if (!Leitor) {
		cout << "Erro ao abrir leitor" << endl;
		fflush(stdin);
		exit;
	}
	
	
	Gravador.open("testejogo11.txt", ios::out);
	if (!Gravador) {
		cout << "erro ao abrir gravador" << endl;
		fflush(stdin);
		exit;
	}
}

Save::~Save() {

}

void Save::savePontos(int pt, int idJog) {

	string nomePlayer;

	cout << "Digite nome do jogador" << endl;
	//cin >> nomePlayer;
	nomePlayer.assign("oi");

	Gravador << idJog << ' ' << nomePlayer << ' ' << pt << endl;
}

void Save::loadPontos() {

	int id;
	int pt;
	string nome;

	while (!Leitor.eof()) {

		Leitor >> id >> nome >> pt;

	}

}