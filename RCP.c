#include<stdio.h>
#include<stdlib.h>
#include<time.h>

 int main() {
  int n, user;
  srand(time(NULL));

  n = rand() % 3;

  if(n == 1)
   n = 'O';
  else if (n == 2)
   n = 'X';
  else if (n == 0)
   n = '#';

  puts("choose rock(O), scissor(X), or paper(#)");

  user = getchar();

  printf("coumputer: %c, user: %c\n", n, user);

  if((n == 'O' && user == '#') || (n == 'X' && user == 'O') || (n == '#' && user == 'X')) 
   puts("you win");
  else if(n == user)
   puts("draw");
  else 
   puts("you lose");
  
  return 0;
}

 
