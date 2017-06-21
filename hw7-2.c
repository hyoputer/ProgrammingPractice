#include<stdio.h>

void factorize(int input) {
	int i, f = 0;
	if(input <= 0) {
		puts("Error");
	} else if(input == 1)
		puts("1 = 1");
	else {
		for(i = 2; i <= input; i++) {
			while(input % i == 0) {
				if(f == 0){
					printf("%d = %d ", input, i);
					f = 1;
					input /= i;
					continue;
				}
				input /= i;
				printf("* %d ", i);
			}
		}
	}
	printf("\n");
}

int main() {
	int input;
	
	fputs("Input value : ", stdout);
	scanf("%d",&input);
	factorize(input);
	return 0;
}
