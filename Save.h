#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
	int idJog;
	int pont;
	string nome;
};

class Save
{
	private:
		ofstream Gravador;
		ifstream Leitor;
		vector<info> informacoes; 
		
	public:
		Save();
		~Save();
		
		//Comparacao para o sort()
		bool comparacao(const info& a, const info& b);

		//Save e load
		void savePontos(int pt, int idJog);
		void loadPontos();
};

