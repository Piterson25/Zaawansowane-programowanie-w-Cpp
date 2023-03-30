#include "Wolf.h"

Wolf::Wolf(int power, Position position) : Organism(power, position)
{
	setSpecies("W");
}

Wolf::Wolf() : Organism()
{
	setSpecies("W");
}

