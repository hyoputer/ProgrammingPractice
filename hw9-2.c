#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sort(int a[], int n) {
	int i, min_ix, j, tmp;
	for(i = 0; i < n - 1; i++) {
		min_ix = i;
		for(j = i + 1; j < n; j++)
			if(a[min_ix] > a[j])
				min_ix = j;
		tmp = a[min_ix];
		a[min_ix] = a[i];
		a[i] = tmp;
	}
}

int main() {
	int s = 4, i, num, n = 3, f, menu, j;
	int *a = (int*)malloc(s*sizeof(int));
	srand(time(NULL));
	for(i = 0; i < 3; i++) {
		a[i] = (rand() % 64) + 1;
	}
	sort(a, n);
	
	do {
	puts("0. Exit 1. Insert 2. Delete 3. Print");
	fputs("Select Menu : ", stdout);
	scanf("%d" ,&menu);
	switch(menu) {
	case 0:
		for(i = 0;i < n; i++)
			printf("%d ", a[i]);
		printf("\n");
		break;
	case 1:
		fputs("Input number : ", stdout);
		scanf("%d", &num);
		for(i = 0; i < n; i++)
			if(a[i] == num)
				f = 1;
		if(f != 1) {
			if(s == n) {
				s *= 2;
				a = (int*)realloc(a, s * sizeof(int));
			}
			a[n++] = num;
			sort(a, n);
		}
		break;
	case 2:
		fputs("Input number : ", stdout);
		scanf("%d", &num);
		for(i = 0; i < n; i++)
			if(a[i] == num) {
				for(j = i; j < n; j++)
					a[j] = a[j + 1];
			n--;
			}
		if(n < (s / 2)) {
			s /= 2;
			a = (int*)realloc(a, s * sizeof(int));
		}
		break;
	case 3:
		printf("size of array : %d\n", s);
		for(i = 0; i < n; i++)
			printf("%d ",a[i]);
		printf("\n");
		break;
	}
	}while(menu != 0);
	free(a);
	return 0;
}
