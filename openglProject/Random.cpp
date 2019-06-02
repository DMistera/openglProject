#include "Random.h"



Random::Random()
{
	srand(time(NULL));
}


Random::~Random()
{
}

int Random::nextInt()
{
	return rand();
}

float Random::nextFloat()
{
	float r = (float)rand() / RAND_MAX;
	return r;
}
