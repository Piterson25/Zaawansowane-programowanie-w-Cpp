#pragma once
#include "Organism.h"

using namespace std;

class Wolf final : public Organism
{
	public:
		Wolf(int power, Position position);
		Wolf();
};

