#include<stdio.h>

void Print(int a[], int n) {
	int i;
	for(i = 0; i < n; i++)
		printf("%d", a[i]);
}

int main() {

	int arr1[100], arr2[100], sum[100] = {0}, sub[100] = {0},  n1 = 0, n2 = 0, s1 = 0, s2 = 0, i, nn1, nn2, *big, *small ,b , s, f, z;
	char c;

	fputs("Input 1 : ", stdout);
	while((c = getchar()) != '\n')
		arr1[n1++] = (c - '0');

	fputs("Input 2 : ", stdout);
	while((c = getchar()) != '\n')
		arr2[n2++] = (c - '0');

	if(n1 != n2) {
		if(n1 > n2) {
			big = arr1;
			small = arr2;
			b = n1;
			s = n2;
		}
		else {
			big = arr2;
			small = arr1;
			b = n2;
			s = n1;
			f = 1;
		
		}
	}
	else {
		for(i = 0; i < n1; i++) {
			if(arr1[i] != arr2[i]) {
				if(arr1[i] > arr2[i]) {
					big = arr1;
					small = arr2;
					b = n1;
					s = n2;
				}
				else {
					big = arr2;
					small = arr1;
					b = n2;
					s = n1;
					f = 1;
				}
			}
		}
	}
	nn1 = n1;
	nn2 = n2;
	while(1){
		if(n1 <= 0 && n2 <= 0)
			break;
		else if(n1 <= 0)
			sum[s1++] += arr2[--n2];
		else if(n2 <= 0)
			sum[s1++] += arr1[--n1];
	
		else {
			sum[s1] += ((arr1[--n1] + arr2[--n2]));
			if(sum[s1] > 9) {
				sum[s1] %= 10;
				sum[s1 + 1] = 1;
			if(n1 == 0 && n2 == 0)
				s1++;
			}
			s1++;
		
		}
	}
	Print(arr1, nn1);
	printf(" + ");
	Print(arr2, nn2);
	printf(" = ");

	for(i = s1 - 1; i >= 0; i--)
		printf("%d",sum[i]);
	printf("\n");
	Print(arr1, nn1);
	printf(" - ");
	Print(arr2, nn2);
	printf(" = ");

	while(1) {
		if(b <= 0 && s <= 0)
			break;
		else if(s <= 0)
			sub[s2++] = big[--b];
		else {
			b--;
			s--;
			if(big[b] < small[s]) {
				sub[s2] = (10 + big[b] - small[s]);
				big[b - 1] -= 1;
				s2++;
			}
			else
				sub[s2++] = (big[b] - small[s]);
		}
	}
	
	if(f == 1)
		printf("-");

	for(i = s2 - 1; i >= 0; i--) {
		if(sub[i] != 0)
			z = 1;
		if(z == 1)
			printf("%d", sub[i]);
	}
	printf("\n");
			
	return 0;
}
