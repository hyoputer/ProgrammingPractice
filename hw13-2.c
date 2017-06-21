#include<stdio.h>
#include<stdlib.h>

typedef struct dc {
	double real;
	double cpx;
} dc;

int input(dc *n) {
	char str[20], c;
	int i = 0;
	while(1) {
		c = getchar();
		if(c == ' ')
			continue;
		else if(c == 'e')
			return -1;
		if(c == '(') {
			while((c = getchar()) != ' ') 
				str[i++] = c;
			str[i] = '\0';
			n -> real = atof(str);
	
			i = 0;
		
			while(1) {
				c = getchar();
				if((c >= '0' && c <= '9') || c == '-')
					break;
			}
			
			while(c != 'i') {
				str[i++] = c;
				c = getchar();
			}
			str[i] = '\0';
			getchar();
			getchar();
			n -> cpx = atof(str);
		}
		else {
			while(c != ' ' && c != '\n') {
				str[i++] = c;
				c = getchar();
			}
			str[i] = '\0';
			
			n -> real = atof(str);
			n -> cpx = 0;
		}
		return 0;
	}
}
	

dc dc_add(dc a, dc b) {
	dc result;
	result.real = a.real + b.real;
	result.cpx = a.cpx + b.cpx;
	return result;
}

dc dc_multi(dc a, dc b) {
	dc result;
	result.real = a.real * b.real - a.cpx * b.cpx;
	result.cpx = a.real * b.cpx + a.cpx * b.real;
	return result;
}

int main() {
	dc a, b, result;
	char c;
	
	while(1) {
		printf("Input : ");
		if(input(&a) == -1)
			break;
		c = getchar();
		while(c != '+' && c != '*')
			c = getchar();
		input(&b);
		if(c == '+')
			result = dc_add(a, b);
		else
			result = dc_multi(a, b);
		if(result.cpx == 0)
			printf("%lf\n", result.real);
		else
			printf("(%lf + %lfi)\n", result.real, result.cpx);

	}
	return 0;
}
