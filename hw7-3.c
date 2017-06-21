#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int i;
	
	srand(time(NULL));
	for(i = 0; i < 6; i++) {
		printf("%d ", rand() % 10 + i*10 + 1);
	}
	printf("\n");
	return;
}
