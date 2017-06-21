#include<stdio.h>


int main() {
	int i;
	for(i = 0; i < 9; i++) {
		printf("%d ",i);
		if(i == 6)
			i = -1;
		printf("%d ",i);
	}
	return 0;
}
