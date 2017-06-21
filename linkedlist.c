


#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int key;
	struct _node *next;
} node_t;

node_t *head = NULL, *tail = NULL;

void insert_node(int n) {
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	new_node->key = n;

	if (head == NULL) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = new_node;
	}

}

void print_list(node_t* from) {

	if (from == NULL)
		return;
	else{
		print_list(from->next);
		printf("%d ", from->key);
	}
}


int delete_node() {
	node_t *node;
	int r;

	if (head == NULL)
		return -1;

	node = head;
	head = head->next;

	if (head == NULL)
		tail = NULL;

	r = node->key;
	return r;

}

int main() {
	int i = 0, num;

	do {
		fputs("input number: ", stdout);
		scanf("%d", &num);
		if (num == 0) {
			if (i == 0)
				puts("Empty queue!");
			else {
				printf("%d\n", delete_node());
				i--;
			}
		}
		else if(num > 0) {
			insert_node(num);
			i++;
		}
	} while (num >= 0);

	print_list(head);

	return 0;

}
