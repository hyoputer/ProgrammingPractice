#include<stdio.h>

int main() {
	int i, j, n1 = 0, n2 = 0, f1 = 0, f2 = 0, a1[100], a2[100], r[100] = {0}, nr, k;
	char c;

	fputs("Input 1 : ", stdout);
 	while((c = getchar()) != '\n') {
		if(c == '-')
			f1 = 1;
		else
			a1[n1++] = (c - '0');
	}

	fputs("Input 2 : ", stdout);
	while((c = getchar()) != '\n') {
		if(c == '-')
			f2 = 1;
		else
			a2[n2++] = (c - '0');
	}

	for(i = n1 - 1; i >= 0; i--) {
		for(j = n2 - 1; j >= 0; j--) {
			k = n1 - i + n2 - j - 2;
			r[k] += (a1[i] * a2[j]);
			if(r[k] >= 10) {
				r[k + 1] += r[k] / 10;
				r[k] %= 10;
			}
		}
	}
	if(r[n1 + n2 - 1] != 0)
		nr = n1 + n2;
	else
		nr = n1 + n2 - 1;
	
/*	while(1) {
		if(n1 <= 0 && n2 <= 0)
			break;
		else if(n1 <= 0)
			r[nr++] += a2[--n2];
		else if(n2 <= 0)
			r[nr++] += a1[--n1];
		else {
			r[nr] += (a1[--n1] * a2[--n2]);
			if(r[nr] >= 10) {
				r[nr + 1] = r[nr] / 10;
				r[nr] %= 10;
				if(n1 == 0 && n2 == 0)
					nr++;
			}
			nr++;
		}
	}*/
	if(f1 == 1)
		fputs("-", stdout);
	
	for(i = 0; i < n1; i++)
		printf("%d", a1[i]);

	fputs(" * ", stdout);

	if(f2 == 1)
		fputs("-", stdout);
	
	for(i = 0; i < n2; i++)
		printf("%d", a2[i]);
	
	fputs(" = ", stdout);
	
	if(f1 != f2)
		fputs("-", stdout);

	for(i = nr - 1; i >= 0; i--) 
		printf("%d", r[i]);
	printf("\n");

	return 0;
}
