#include "Fase.h"

Fase::Fase() : pGrafico(), pEvento(), pColisao(), pJogador(), listaEntidades(), listaInimigos(), listaObstaculos(), listaPlataformas()
{
}

Fase::~Fase()
{
	if (pGrafico) {
		delete(pGrafico);
		pGrafico = NULL;
	}
	if (pEvento) {
		delete(pEvento);
		pEvento = NULL;
	}
	if (pColisao) {
		delete(pColisao);
		pColisao = NULL;
	}
	if (pJogador) {
		delete(pJogador);
		pJogador = NULL;
	}
	if (listaEntidades) {
		delete(listaEntidades);
		listaEntidades = NULL;
	}
	if (listaInimigos) {
		delete(listaInimigos);
		listaInimigos = NULL;
	}
	if (listaObstaculos) {
		delete(listaObstaculos);
		listaObstaculos = NULL;
	}
	if (listaPlataformas) {
		delete(listaPlataformas);
		listaPlataformas = NULL;
	}
}
