#include "FaseCastelo.h"

FaseCastelo::FaseCastelo() : Fase()
{
	this->num_Morcegos = -1;
	this->num_Cobras = -1;
	this->background.setSize(sf::Vector2f(1920.0f , 1080.0f));
	this->backgroundTexture.loadFromFile("assets/castle.png");
	background.setTexture(&backgroundTexture);

	Jogadores.push_back(new JogadorPrincipal(&listaEntidades, sf::Vector2f(150.f, 250.f), sf::Vector2f(100.f, 100.f)));

	this->GerenciadorColisao = new GerenciadorColisoes(&Jogadores, &listaInimigos, &listaPlataformas, &listaObstaculos);

	for (auto const& Jogador : Jogadores)
	{
		listaEntidades.addEntidade(Jogador);
	}

	setPosicoesLivres();
	criaMapa();
	criaInimigos();
	criaObstaculos();

	//int kk =1;
	//listaEntidades.addEntidade(new Rei(pJogador, sf::Vector2f(250.0f * kk + 200, 200.0f), sf::Vector2f(100.0f, 100.0f)));

	for (unsigned int i = 0; i < listaEntidades.getTamanho(); i++) {
		/// 11 = teia
		/// 12 = espinhos
		/// 13 = portal
		if (listaEntidades[i]->getID() == 11 || listaEntidades[i]->getID() == 12 || listaEntidades[i]->getID() == 13) {
			listaObstaculos.addEntidade(listaEntidades[i]);
		}
		/// 21 = cobra
		/// 22 = morcego
		/// 23 = projetil
		/// 24 = rei
		else if (listaEntidades[i]->getID() == 21 || listaEntidades[i]->getID() == 22 || listaEntidades[i]->getID() == 23 || listaEntidades[i]->getID() == 24 ) {
			listaInimigos.addEntidade(listaEntidades[i]);
		}
		/// 31 = plataforma
		else if (listaEntidades[i]->getID() == 31) {
			listaPlataformas.addEntidade(listaEntidades[i]);
		}
	}

}

FaseCastelo::~FaseCastelo()
{
}

void FaseCastelo::setPosicoesLivres()
{
	//Cobras
	listaPosCobras[0].cord = sf::Vector2f(330.0f, 550.0f);
	listaPosCobras[1].cord = sf::Vector2f(540.0f, 550.0f);
	listaPosCobras[2].cord = sf::Vector2f(1364.0f , 550.0f);
	listaPosCobras[3].cord = sf::Vector2f(1561.0f, 550.0f);
	listaPosCobras[4].cord = sf::Vector2f(1800.0f , 550.0f);
	listaPosCobras[5].cord = sf::Vector2f(2273.0f , 550.0f);
	listaPosCobras[6].cord = sf::Vector2f(2577.0f , 550.0f);
	listaPosCobras[7].cord = sf::Vector2f(2950.0f , 550.0f);
	listaPosCobras[8].cord = sf::Vector2f(3350.0f , 550.0f);
	listaPosCobras[9].cord = sf::Vector2f(2421.0f , 200.0f);
	listaPosCobras[10].cord = sf::Vector2f(2921.0f , 200.0f);
	listaPosCobras[11].cord = sf::Vector2f(3353.0f , 200.0f);
	listaPosCobras[12].cord = sf::Vector2f(3840.0f , 600.0f);
	listaPosCobras[13].cord = sf::Vector2f(4242.0f, 550.0f);
	listaPosCobras[14].cord = sf::Vector2f(4520.0f , 550.0f);
	listaPosCobras[15].cord = sf::Vector2f(4824.0f , 550.0f);
	listaPosCobras[16].cord = sf::Vector2f(4208.0f , 200.0f);
	listaPosCobras[17].cord = sf::Vector2f(4528.0f , 200.0f);
	listaPosCobras[18].cord = sf::Vector2f(4714.0f , 200.0f);

	//Morcegos
	listaPosMorcegos[0].cord = sf::Vector2f(350, 300);
	listaPosMorcegos[1].cord = sf::Vector2f(550, 300);
	listaPosMorcegos[2].cord = sf::Vector2f(700, 100);
	listaPosMorcegos[3].cord = sf::Vector2f(1200, 100);
	listaPosMorcegos[4].cord = sf::Vector2f(1350, 300);
	listaPosMorcegos[5].cord = sf::Vector2f(1550, 300);
	listaPosMorcegos[6].cord = sf::Vector2f(1750, 300);
	listaPosMorcegos[7].cord = sf::Vector2f(2050, 200);
	listaPosMorcegos[8].cord = sf::Vector2f(2350, 100);
	listaPosMorcegos[9].cord = sf::Vector2f(2650, 100);
	listaPosMorcegos[10].cord = sf::Vector2f(2950, 100);
	listaPosMorcegos[11].cord = sf::Vector2f(3330, 100);
	listaPosMorcegos[12].cord = sf::Vector2f(2250, 400);
	listaPosMorcegos[13].cord = sf::Vector2f(2650, 400);
	listaPosMorcegos[14].cord = sf::Vector2f(2900, 400);
	listaPosMorcegos[15].cord = sf::Vector2f(3150, 400);
	listaPosMorcegos[16].cord = sf::Vector2f(3800, 100);
	listaPosMorcegos[17].cord = sf::Vector2f(4000, 100);
	listaPosMorcegos[18].cord = sf::Vector2f(4300, 100);
	listaPosMorcegos[19].cord = sf::Vector2f(4650, 100);
	listaPosMorcegos[20].cord = sf::Vector2f(4850, 100);
	listaPosMorcegos[21].cord = sf::Vector2f(4250, 400);
	listaPosMorcegos[22].cord = sf::Vector2f(4550, 400);
	listaPosMorcegos[23].cord = sf::Vector2f(4800, 400);
	listaPosMorcegos[24].cord = sf::Vector2f(5400, 200);
	listaPosMorcegos[25].cord = sf::Vector2f(5850, 200);
	listaPosMorcegos[26].cord = sf::Vector2f(6300, 200);

	//Obstaculos
	listaPosObstaculos[0].cord = sf::Vector2f(450, 350);
	listaPosObstaculos[1].cord = sf::Vector2f(1450, 350);
	listaPosObstaculos[2].cord = sf::Vector2f(650, 150);
	listaPosObstaculos[3].cord = sf::Vector2f(780, 150);
	listaPosObstaculos[4].cord = sf::Vector2f(1140, 150);
	listaPosObstaculos[5].cord = sf::Vector2f(1280, 150);
	listaPosObstaculos[6].cord = sf::Vector2f(1750, 450);
	listaPosObstaculos[7].cord = sf::Vector2f(2050, 250);
	listaPosObstaculos[8].cord = sf::Vector2f(2750, 150);
	listaPosObstaculos[9].cord = sf::Vector2f(2850, 150);
	listaPosObstaculos[10].cord = sf::Vector2f(2950, 150);
	listaPosObstaculos[11].cord = sf::Vector2f(3050, 150);
	listaPosObstaculos[12].cord = sf::Vector2f(2400, 500);
	listaPosObstaculos[13].cord = sf::Vector2f(2500, 500);
	listaPosObstaculos[14].cord = sf::Vector2f(2600, 500);
	listaPosObstaculos[15].cord = sf::Vector2f(2700, 500);
	listaPosObstaculos[16].cord = sf::Vector2f(3150, 500);
	listaPosObstaculos[17].cord = sf::Vector2f(3250, 500);
	listaPosObstaculos[18].cord = sf::Vector2f(3350, 500);
	listaPosObstaculos[19].cord = sf::Vector2f(3450, 500);
	listaPosObstaculos[20].cord = sf::Vector2f(4000, 350);
	listaPosObstaculos[21].cord = sf::Vector2f(4300, 150);
	listaPosObstaculos[22].cord = sf::Vector2f(4400, 150);
	listaPosObstaculos[23].cord = sf::Vector2f(4500, 150);
	listaPosObstaculos[24].cord = sf::Vector2f(4600, 150);
	listaPosObstaculos[25].cord = sf::Vector2f(4550, 500);
	listaPosObstaculos[26].cord = sf::Vector2f(4650, 500);
	listaPosObstaculos[27].cord = sf::Vector2f(4750, 500);
	listaPosObstaculos[28].cord = sf::Vector2f(4850, 500);



}

void FaseCastelo::criaMapa()
{
	//chao
	for (int i = 0; i < 4; i++) {
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(200.0f + (i*500), 700.0f), sf::Vector2f(500.0f, 70.0f)));
	}
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1950.0f, 800.0f), sf::Vector2f(50.0f, 250.0f)));

	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1950.0f, 900.0f), sf::Vector2f(500.0f, 50.0f)));

	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2150.0f, 800.0f), sf::Vector2f(50.0f, 250.0f)));

	for (int i = 0; i < 6; i++) {
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2400.0f + (i * 500), 700.0f), sf::Vector2f(500.0f, 70.0f)));
	}
	for (int i = 0; i < 6; i++) {
		if (i == 3) {
			continue;
		}
		else {
			listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2400.0f + (i * 500), 350.0f), sf::Vector2f(500.0f, 70.0f)));
		}
	}

	//"teto" dos corredos de cima
	for (int i = 0; i < 6; i++) {
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2400.0f + (i * 500), 50.0f), sf::Vector2f(500.0f, 70.0f)));
	}

	//torres do comeco fase
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(450.0f, 540.0f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(700.0f, 500.0f), sf::Vector2f(200.0f, 350.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(950.0f, 400.0f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1200.0f, 500.0f), sf::Vector2f(200.0f, 350.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(1450.0f, 540.0f), sf::Vector2f(50.0f, 50.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(2050.0f, 540.0f), sf::Vector2f(50.0f, 50.0f)));

	//sorteia qual caminho vai ficar liberado 
	int aux_rand = rand() % 3;
	if (aux_rand == 2) {
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(5000.0f, 200.0f), sf::Vector2f(200.0f, 350.0f)));
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(3600.0f, 500.0f), sf::Vector2f(200.0f, 350.0f)));
	}
	else {
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(5050.0f, 500.0f), sf::Vector2f(200.0f, 350.0f)));
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(3600.0f, 200.0f), sf::Vector2f(200.0f, 350.0f)));
	}

	//plataforma que permite o jogador voltar/descer entre os andares
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(4000.0f, 540.0f), sf::Vector2f(50.0f, 50.0f)));

	//quadrados do final q tem pular
	for (int i = 0; i < 10; i++) {
		listaEntidades.addEntidade(new Plataforma(sf::Vector2f(5250.0f + (150 * i), 600.0f), sf::Vector2f(50.0f, 50.0f)));
	}
	
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(5135.0f, 800.0f), sf::Vector2f(50.0f, 200.0f)));
	listaEntidades.addEntidade(new Plataforma(sf::Vector2f(5950.0f, 800.0f), sf::Vector2f(1500.0f, 50.0f)));
}

void FaseCastelo::criaInimigos()
{
	this->num_Cobras = (rand() % (10 + 1 - 3) + 3);
	this->num_Morcegos = (rand() % (15 + 1 - 3) + 3);

	for (int i = 0; i < num_Cobras; i++) {
		int aux = rand() % 19;
		// Exclui possivel spawn em cima de buracos
		while (!(listaPosCobras[aux].isLivre)) {
			aux = rand() % 19;
		}
		listaEntidades.addEntidade(new Cobra(&Jogadores, sf::Vector2f(listaPosCobras[aux].cord), sf::Vector2f(100.0f, 100.0f)));
		listaPosCobras[aux].isLivre = false;
	}
	for (int i = 0; i < num_Morcegos; i++) {
		int aux = rand() % 27;
		while (!(listaPosMorcegos[aux].isLivre)) {
			aux = rand() % 27;
		}
		listaEntidades.addEntidade(new Morcego(&listaEntidades, &Jogadores, sf::Vector2f(listaPosMorcegos[aux].cord), sf::Vector2f(50.0f, 50.0f)));
		listaPosMorcegos[aux].isLivre = false;
	}
	

}

void FaseCastelo::criaObstaculos()
{
	this->num_Teias = std::rand() % (18 + 1 - 3) + 3;
	this->num_Portais = std::rand() % (5 + 1 - 3) + 3;

	for (int i = 0; i < num_Teias; i++) {
		int aux2 = rand() % 29;
		while (!(listaPosObstaculos[aux2].isLivre)) {
			aux2 = rand() % 29;
		}
		listaEntidades.addEntidade(new Teia(sf::Vector2f(listaPosObstaculos[aux2].cord), sf::Vector2f(100.0f, 100.0f)));
		listaPosObstaculos[aux2].isLivre = false;
	}

	for (int i = 0; i < num_Portais; i++) {
		int aux3 = rand() % 29;
		while (!(listaPosObstaculos[aux3].isLivre)) {
			aux3 = rand() % 29;
		}
		listaEntidades.addEntidade(new Portal(&Jogadores, sf::Vector2f(100.f, 100.f),sf::Vector2f(listaPosObstaculos[aux3].cord), sf::Vector2f(70.0f, 70.0f)));
		listaPosObstaculos[aux3].isLivre = false;
	}

	num_Espinhos = num_Espinhos + 3;
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(850.f, 625.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(1000.f, 625.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(2000.f, 800.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(5300.f, 550.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(5450.f, 550.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(5600.f, 550.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(5750.f, 550.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(5900.f, 550.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(6050.f, 550.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(6200.f, 550.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(6350.f, 550.f)));
	listaEntidades.addEntidade(new Espinhos(sf::Vector2f(6500.f, 550.f)));

	num_Portais = num_Portais + 2;
	listaEntidades.addEntidade(new Portal(&Jogadores, sf::Vector2f(100.f, 100.f), sf::Vector2f(700.0f, 300.0f), sf::Vector2f(70.f, 70.f)));
	listaEntidades.addEntidade(new Portal(&Jogadores, sf::Vector2f(100.f, 100.f), sf::Vector2f(1200.0f, 300.0f), sf::Vector2f(70.f, 70.f)));

}

int const FaseCastelo::getPontuacao()
{
	return this->Jogadores.front()->getPontucao();
}

void FaseCastelo::multiplayer(bool status)
{
	if (status == true) {
		Jogadores.push_back(new JogadorSecundario(&listaEntidades, sf::Vector2f(150.f, 250.f), sf::Vector2f(100.f, 100.f)));
		listaEntidades.addEntidade(Jogadores.back());
;	}
}

bool FaseCastelo::checkMorreu()
{
	if (Jogadores.front()->getVida() <= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool FaseCastelo::checkTerminou() {
	sf::RectangleShape final;
	final.setSize(sf::Vector2f(100.f, 10000.f));
	final.setFillColor(sf::Color::Blue);
	final.setPosition(sf::Vector2f(6600.0f, 515.0f));

	if (Jogadores.front()->getCorpo().getGlobalBounds().intersects(final.getGlobalBounds())) {
		Jogadores.front()->setPosition(150.f, 600.f);
		return true;
	}
	else {
		return false;
	}
}

void FaseCastelo::update()
{
	this->GerenciadorColisao->updateColisao();
	render();
	//printf("%f %f\n", pJogador->getCorpo().getPosition().x, pJogador->getCorpo().getPosition().y);
}

void FaseCastelo::render()
{
	pGrafico->setView(sf::Vector2f(Jogadores.front()->getCorpo().getPosition().x, 300));
	pGrafico->desenhaElementos(this->background);

	//pJogador->salvePontuacao();

	for (unsigned int i = 0; i < listaEntidades.getTamanho(); i++) {
		listaEntidades[i]->seImprime(listaEntidades[i]->getCorpo());
	}
	for (unsigned int i = 0; i < listaEntidades.getTamanho(); i++) {
		listaEntidades[i]->update();
	}
}
