#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *circularSingly(int data)
{
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = new_node;
	return new_node;
}

int main()
{
	struct Node *tail;
	tail = circularSingly(34);

	printf("%d", tail->data);
	return 0;
}
