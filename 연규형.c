#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	float randomFloat;
	int i;

	srand((unsigned int)time(NULL));
	for (i = 0; i < 100; i++)
	{
		randomFloat = ((float)rand()) / RAND_MAX;
		printf("%f\n", randomFloat);
	}
}
