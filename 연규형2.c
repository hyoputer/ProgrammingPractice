#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	float input, max, min, sum = 0;
	int i;

	scanf("%f", &input);
	sum += input;
	max = min = input;
	for (i = 1; i < 100; i++)
	{
		scanf("%f", &input);
		sum += input;
		if (input < min)
		{
			min = input;
		}
		if (input > max)
		{
			max = input;
		}
	}

	printf("Max : %f, Min : %f, Average : %f\n", max, min, sum / 100);
}
