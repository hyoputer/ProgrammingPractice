#include<stdio.h>
#include<math.h>

int main() {
	int binum[2], i, j, num[2], temp, result;
	char n[100];

	for(j = 0;j < 2;j++) {
		printf("Input %d : ",j+1);
		scanf("%d",&binum[j]);
		temp = 0;
		i = 0;
		while(binum[j] != 0) {
			temp += ((binum[j] % 10) *(int)pow(2, i++));
			binum[j] /= 10;
		}
		num[j] = temp;
	}
	result = num[0] + num[1];
	
	i = 0;
	while(result != 0) {
		n[i++] = result % 2;
		result /= 2;
	}
	for(i -= 1; i >= 0; i--)
		printf("%d", n[i]);
	printf("\n");

	return 0;
}
