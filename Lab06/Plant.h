#pragma once
#include "Organism.h"

class Plant final : public Organism
{
	public:
		Plant(int power, Position position);
		Plant();

		void move(int dx, int dy);
};

