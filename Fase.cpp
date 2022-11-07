#include "Fase.h"

Fase::Fase() : GerenciadorColisao(), background(), listaEntidades(), listaObstaculos(), listaInimigos(), listaPlataformas(), pGrafico(pGrafico->getGerenciadorGrafico()), pEvento(pEvento->getGerenciadorEvento())
{
}
Fase::~Fase()
{
}

