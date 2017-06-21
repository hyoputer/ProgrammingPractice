#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int solution[9][9], problem[9][9];

int sol(int a, int b) {
	int i, j, k, l, n = 9, arr[10] = {1,2,3,4,5,6,7,8,9}, fr, fc;
	
	for(i = 0; i < b; i++) {
		for(j = 0; j < n; j++) {
			if(solution[a][i] == arr[j]) {
				for(k = j; k < n; k++)
					arr[k] = arr[k + 1];
				n--;
			}
		}
	}

	for(i = 0; i < a; i++) {
		for(j = 0; j < n; j++) {
			if(solution[i][b] == arr[j] ) {
				for(k = j; k< n; k++)
					arr[k] = arr[k + 1];
				n--;
			}
		}
	}

	fr = a / 3;
	fc = b / 3;
	for(i = (fr * 3); i < a; i++) {
		for(j = (fc *3); j < b; j++) {
			for(k = 0; k < n; k++) {
				if(solution[i][j] == arr[k]) {
					for(l = k; l < n; l++)
						arr[l] = arr[l + 1];
					n--;
				}
			}
		}
	}
	if(n <= 0)
		return -1;
	
	solution[a][b] = arr[rand() % n];
	return 0;	
}

void prb(int a, int b) {
	int n, arr[9] = {1,2,3,4,5,6,7,8,9}, i, c;
	n = rand() % 3 + 4;
	for(i = 0; i < n; i++) {
		c = rand() % 9;
		if(arr[c] == 0) {
			i--;
			continue;
		}
		arr[c] = 0;
	}
	for(i = 0; i < 9; i++) {
		if(arr[i] != 0)
			problem[i / 3 + a * 3][i % 3 + b * 3] = solution[i / 3 + a * 3][i % 3 + b * 3];
		else		
			problem[i / 3 + a * 3][i % 3 + b * 3] = 0;		
	}
}

int main() {
	int i, j;
	srand(time(NULL));
	
	for(i = 0; i < 9; i++)
		for(j = 0; j < 9; j++) {
			if(sol(i, j) == -1) {
				j = -1;
				i--;;
			}
		}
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			prb(i, j);
	puts("Sudoku Problem :");
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++)
			printf("%d ", problem[i][j]);
		printf("\n");
	}

	puts("Sudoku Solution :");
	for(i = 0; i < 9; i++) 	{
		for(j = 0; j < 9; j++)
			printf("%d ", solution[i][j]);
		printf("\n");
	}
	
	return 0;
}
