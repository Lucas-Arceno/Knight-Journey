#include "Stateman.h"

Engine::Stateman::Stateman(){

}

Engine::Stateman::~Stateman() {

}


void Engine::Stateman::add(unique_ptr<State> toAdd, bool replace){
	m_add = true;
	m_newState = move(toAdd);

	m_replace = replace;

}

void Engine::Stateman::popCurrent(){
	m_remove = true;
}

void Engine::Stateman::processStateChange(){
	if (m_remove && (!m_stateStack.empty())) {
		m_stateStack.pop();

		if (!m_stateStack.empty()) {
			m_stateStack.top()->start();
		}

		m_remove = false;
	}

	if (m_add) {
		if (m_replace && (!m_stateStack.empty())) {
			m_stateStack.pop();
			m_replace = false;
		}
		if (!m_stateStack.empty()) {
			m_stateStack.top()->pause();
		}
		m_stateStack.push(move(m_newState));
		m_add = false;
	}
}

unique_ptr<Engine::State>& Engine::Stateman::getCurrent()
{
	return m_stateStack.top();
}

