#include<stdio.h>

int main() {
 int i;
 float num, sum;

 num = 1;
 i = 0;
 sum = 0;
 while(1) {
  printf("Input number %d : ",i+1);
  scanf("%f",&num);
  if (num == 0)
   break;
  i++;
  sum += num;
  
 }
 printf("You input %d numbers. Sum of them is %f, and average of them is %f.\n",i, sum, sum / i);
 
 return 0;
}
