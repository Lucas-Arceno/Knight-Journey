#include "Save.h"

Save::Save(){
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

	printf("savePoints \n");
	string nomePlayer;

	cout << "Digite nome do jogador" << endl;
	//cin >> nomePlayer;
	nomePlayer.assign("oi");

	Gravador << idJog << " " << nomePlayer << " " << pt << endl;
}