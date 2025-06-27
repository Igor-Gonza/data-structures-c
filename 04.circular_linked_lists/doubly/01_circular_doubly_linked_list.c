#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};

struct Node *circularDoubly(int data)
{
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->prev = new_node;
	new_node->next = new_node;
	return new_node;
}

int main()
{
	struct Node *tail;
	tail = circularDoubly(34);

	printf("%d", tail->data);
	return 0;
}
