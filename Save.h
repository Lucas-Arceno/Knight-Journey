#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct info {
	int rank;
	string nome;
};

class Save
{
	private:
		ofstream Gravador;
		ifstream Leitor;
		info informacoes;

	public:
		Save();
		~Save();

		void savePontos(int pt, int idJog);
		void loadPontos();
};
