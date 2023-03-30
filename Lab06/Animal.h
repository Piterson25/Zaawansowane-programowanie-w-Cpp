#pragma once
#include "Organism.h"

using namespace std;

class Animal final : public Organism
{
	public:
		Animal(int power, Position position);
		Animal();

};

