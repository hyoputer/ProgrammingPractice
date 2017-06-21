#include<stdio.h>

int main() {
	char c;
	
	while((c = getchar()) != EOF) {
		if(c >= 'a' && c <= 'z') {
			c -= 'a';
			printf("%c", (c + 2) % 25 + 'a');
		}
		else if(c >= 'A' && c <= 'Z') {
			c -= 'A';
			printf("%c", (c + 2) % 25 + 'a');
		}
		else
			printf("%c", c);
	}
	return 0;
}
