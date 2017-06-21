#include<stdio.h>

int main() {
	int num, arr[8]={0}, i, j;

	i = 0;
	while(1) {
		fputs("input number: ",stdout);
		scanf("%d",&num);
		if(num == 0) {
			if ( i = 0)
				puts("queue empty!");
			else {
				printf("[%d]\n",arr[0]);
				printf("%d\n",arr[1]);
				for (j = 0; j < i; j++) {
					arr[j] = arr[j + 1];
				}
				i--;
			}
		}
		else if (num < 0)
			break;
		else {
			arr[i] = num;
			i++;
		}
	}

	system("pause");
	return 0;

}
