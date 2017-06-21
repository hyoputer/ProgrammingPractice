#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int arr[5], i, j, n, temp, min_ix, f = 0;
	
	srand(time(NULL));
	for(n = 0; n < 5; n++) {
		for(i = 0; i < 6; i++) {
			temp = rand() % 45 + 1;
			for(j = 0; j <= i; j++) {
				if(arr[j] == temp)
					f = 1;
			}
			if(f == 1) {
				f = 0;
				i--;
				continue;
			}
			arr[i] = temp;
		}
		temp = 0;
		
		for(i = 0; i < 6; i++) {
			min_ix = i;
			for(j = i + 1; j < 6; j++)
				if(arr[min_ix] > arr[j])
					min_ix = j;
			temp = arr[min_ix];
			arr[min_ix] = arr[i];
			arr[i] = temp;
		}
		
		for(i = 0; i < 6; i++)
			printf("%d ",arr[i]);
		printf("\n");
	}
}



