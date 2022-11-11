#pragma once
#include <SFML/System/Time.hpp>

// State e Stateman baseado em : www.youtube.com/watch?v=QhIqhen6cmw
// github.com/ufrshubham

namespace Engine {
	class State
	{
	public:
		State();
		virtual ~State();

		virtual void init() = 0;
		virtual void processInput() = 0;
		virtual void update(sf::Time deltaTime) = 0;

		virtual void pause() {};
		virtual void start() {};
	};
}
