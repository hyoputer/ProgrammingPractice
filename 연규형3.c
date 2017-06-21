#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	float input, max, second, third;
	int i;

	scanf("%f", &input);
	max = second = third = input;
	for (i = 1; i < 100; i++)
	{
		scanf("%f", &input);
		if (input > max)
		{
			third = second;
			second = max;
			max = input;
		}
		else if (input > second)
		{
			third = second;
			second = input;
		}
		else if (input > third)
		{
			third = input;
		}
	}

	printf("2nd Max : %f, 3rd Max : %f\n", second, third);
}
