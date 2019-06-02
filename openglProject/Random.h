#pragma once

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Random
{
public:
	Random();
	~Random();
	int nextInt();
	float nextFloat();
};

