#include<stdio.h>
#include<math.h>

void menu() {
	puts("1. add	2. sub	3. mul	4. div	5. pow");
}

double add(double a, double b) {
	return a+b;
}

double sub(double a, double b) {
	return a-b;
}

double mul(double a, double b) {
	return a*b;
}

double div(double a, double b) {
	double result;
	result = a / b;
	return result;
}

int main() {
	int num;
	double a, b, result;

	menu();
	fputs("Select Menu : ",stdout);
	scanf("%d", &num);
	
	fputs("Input two values : ", stdout);
	scanf("%lf%lf",&a ,&b);
	switch(num) {
	case 1:
		result = add(a, b);
		break;
	case 2:
		result = sub(a, b);
		break;
	case 3:
		result = mul(a, b);
		break;
	case 4:
		result = div(a, b);
		break;
	case 5:
		result = pow(a, b);
	}
	printf("Result : %lf\n", result);
	return 0;
}
