#include<stdio.h>
#define SIZE_INT 32

void bit_print(int a) {
	int i;
	for(i = 1; i <= SIZE_INT; i++) {
		if((a >> (SIZE_INT - i)) & 1)
			fputs("1", stdout);
		else
			fputs("0" , stdout);
		if(i % 8 == 0)
			fputs(" ", stdout);
	}
	fputs("\n", stdout);
}
	
int circular_right(int a, int n) {
	int b, c = a << (32 - n);
	a >>= n;

	if(a < 0) {
		b = 1 << 31;
		b >>= (n - 1);
		a ^= b;
	}	
	return (a + c);
}

int main() {
	int a, n;
	fputs("a: ", stdout);
	scanf("%d", &a);
	fputs("n: ", stdout);
	scanf("%d", &n);
	fputs("bigwise a:", stdout);
	bit_print(a);
	fputs("circular right shift a: ", stdout);
	bit_print(circular_right(a, n));

	return 0;
}
