#include<stdio.h>
#include<stdlib.h>

typedef struct list {
	int data;
	struct list *next;
} list;

void insert(list *ptr, int num) {
	list *temp;
	temp = (list*)malloc(sizeof(list));
	if(ptr -> next == NULL) {
		temp -> next = NULL;
		temp -> data = num;
		ptr -> next = temp;
	}
	else if(((ptr -> next) -> data) > num) {
		temp -> next = ptr -> next;
		temp -> data = num;
		ptr -> next = temp;
	}
	else
		insert(ptr -> next, num);

	return;
}

void delete(list *ptr, int num) {
	list *temp;
	if((ptr -> next) -> data == num) {
		temp = ptr -> next;
		ptr -> next= (ptr -> next) -> next;
		free(temp);
	}
	else if((ptr -> next) -> next == NULL)
		return;
	else
		delete(ptr -> next, num);		
}

void find(list *ptr, int num) {
	if(ptr -> data == num) 
		puts("True");
	else if(ptr -> next == NULL)
		puts("False");
	else
		find(ptr -> next, num);
	return;
}

void print(list *ptr) {
	printf("%d ", (ptr -> next) -> data);
	if((ptr -> next) -> next == NULL)
		return;
	else
		print(ptr -> next);		
}

int main() {
	int num, f;
	char str[20];
	list *head;
	head = (list*)malloc(sizeof(list));
	head -> next = NULL;
	while(1) {
		scanf("%s", str);
		switch(str[0]) {
		case 'i':
			scanf("%d", &num);
			insert(head, num);
			break;
		case 'd':
			scanf("%d", &num);
			delete(head, num);
			break;
		case 'f':
			scanf("%d", &num);
			find(head, num);
			break;
		case 'p':
			print(head);
			printf("\n");
			break;
		case 'e':
			print(head);
			printf("\n");
			return 0;
		}
	}	
}
