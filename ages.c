#include<stdio.h>
int main() {
 int i = 0;
 int year, age;
 
 year = 2016; 
 scanf("%d", &age);

 while( i < 3) {
  printf("In %d, I'm %d years old\n", year, age);
  year++;
  age++;
  i++;
 }
 return 0;
}
