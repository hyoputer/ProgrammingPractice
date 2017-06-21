#include<stdio.h>

int sum2(int n) {
	if(n == 0)
		return 0;
	if(n % 2 == 0)
		return (n + sum2(n - 1));
	else
		return sum2(n - 1);
}

int main() {
	int n;

	fputs("n : ",stdout);
	scanf("%d", &n);
	
	printf("%d\n", sum2(n));
	return 0;
}
