#pragma once
#include "State.h"
#include <stack>
#include <memory>
using namespace std;
// State e Stateman baseado em : www.youtube.com/watch?v=QhIqhen6cmw
// github.com/ufrshubham

namespace Engine {
	class Stateman
	{
	private:
		stack<unique_ptr<State>> m_stateStack;
		unique_ptr<State> m_newState;

		bool m_add;
		bool m_replace;
		bool m_remove;

	public:
		Stateman();
		~Stateman();

		void add(unique_ptr<State> toAdd, bool replace);
		void popCurrent();
		void processStateChange();
		unique_ptr<State>& getCurrent();


	};
}
