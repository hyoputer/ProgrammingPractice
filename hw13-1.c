#include<stdio.h>
#include<stdlib.h>

typedef struct student {
	char name[20];
	char ID[20];
	char grade[3];
	int fg;
} student;

int main() {
	student a[20], temp;
	int i = 0, j, k;
	while(1)  {
		if(scanf("%s", a[i].name) == EOF)
			break;
		scanf("%s", a[i].ID);
		scanf("%s", a[i].grade);
		if(a[i].grade[1] == '0')
			a[i].fg = 0;
		else if(a[i].grade[1] == '+')
			a[i].fg = 1;
		else
			a[i].fg = -1;
		for(j = 0; j < i; j++) {
			if(a[i].grade[0] < a[j].grade[0]) {
				temp = a[i];
				for(k = i - 1; k >= j; k--)
					a[k + 1] = a[k];
				a[j] = temp;
				break;
			}
			else if(a[i].grade[0] == a[j].grade[0]) {
				if(a[i].fg > a[j].fg) {
					temp = a[i];
					for(k = i - 1; k >= j; k--)
						a[k + 1] = a[k];
					a[j] = temp;
					break;
				}
				else if(a[i].fg == a[j].fg) {
					if(atoi(a[i].ID) < atoi(a[j].ID)) {
						temp = a[i];
						for(k = i - 1; k >= j; k--)
							a[k + 1] = a[k];
						a[j] = temp;
						break;
					}
				}
			}
		}
	
		i++;	
	}

	for(j = 0; j < i; j++) {
		printf("%s", a[j].name);
		printf("\t");
		printf("%s", a[j].ID);
		printf(" ");
		printf("%s\n", a[j].grade);
	}
	return 0;
}
