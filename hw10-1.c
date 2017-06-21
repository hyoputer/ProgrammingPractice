#include<stdio.h>

int main() {
	int num1, num2, sum;
	char c;

	
	scanf("%d", &num1);
	sum = num1;
	while(1) {
		c = getchar();
		if(c == '\n')
			break;
		scanf("%d", &num2);
		if(c == '+')
			sum += num2;
		else if(c == '-')
			sum -= num2;
	}
	
	printf("%d\n", sum);
	return 0;
}
