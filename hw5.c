#include<stdio.h>

int main() {
	int ycount = 0, cncount = 0, y = 0, n = 0, cc = 0;
	char c;	

	while((c = getchar()) != EOF) {
		if(y == 1) {
			if(c == ' ' || c == '\n' || c == EOF) {
				ycount++;
				y = 0;
			}
			else
				y = 0;
		}
		if(n == 1) {
			if(c == ' ' || c == '\n' || c == EOF || c == '.' || c == ',') {
				cncount++;
				n = 0;
				cc = 0;
			}
			else {
				n = 0;
			}
		}
		if(cc == 1) {
			if(c == 'n') {
				n = 1;
			}
			else if(c == ' ' || c == '\n' || c == EOF || c == '.' || c == ',')
				cc = 0;
		}
		if (c == 'y')
			y = 1;
		if(c == 'c')
			cc = 1;
	}
	printf("Number of words that end with y is %d\n",ycount);
	printf("Number of words that start with c and end with n is %d\n", cncount);
	return 0;
}
