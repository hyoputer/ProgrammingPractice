#include<stdio.h> 

int GCD(int a, int b) {
	if (a % b == 0)
		return b;
	GCD(b , a % b);
	}
int main () {  
	int a, b, small, big, i;  
        printf("Input 1st number : ");
	scanf("%d", &a);
	printf("Input 2nd number : ");
	scanf("%d", &b);  
        if (a > b) {  
            small = b;  
            big = a;  
        } else {  
            small = a;  
            big = b;  
        }  
          
        printf("GCD of %d and %d is %d\n", a, b,  GCD(big, small));
        return 0;  
}
