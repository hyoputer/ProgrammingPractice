#include<stdio.h>
#include<string.h>

int main() {
	char arr[10000];
	int i, len;	

	fputs("input string : ",stdout);
	scanf("%s",arr);
	
	len = strlen(arr);
	for(i = 0; i < len / 2; i++)
		if(arr[i] != arr[len - i - 1]) {
			printf("%s is not a symmetrical word\n", arr);
			return 0;
		}
	printf("%s is a symmetrical word\n", arr);
	return 0;
}
