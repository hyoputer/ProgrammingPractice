#include<stdio.h>

int main() {
 char c;
 int count=0;
 int counta=0;
 int num=0;
 int line=0;
 int space=0;
 
 while ((c = getchar()) != EOF) {
  switch (c) {
  case 'a':
   counta++;
   break;
  case '1':
  case '2':
  case '0':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
   num++;
   break;
  case '\n':
   line++;
   break;
  case ' ':
  case '\t':
   space++;
   break;
  }
  count++;
 }

 printf("전체 글자 수: %d\n a개수: %d\n 숫자개수: %d\n 개행문자개수: %d\n 공백문자개수: %d\n", count, counta, num, line, space);

 return 0;
}
   
