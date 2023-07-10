#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
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
		
		//Save e load
		void savePontos(int pt, string nome);
		void loadPontos();
		vector<info> getPontos();
};

