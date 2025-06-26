#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};

struct Node *add_to_empty(struct Node *head, int data)
{
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->prev = NULL;
	new_node->data = data;
	new_node->next = NULL;

	head = new_node;
	return head;
}

int main()
{
	struct Node *head = NULL;
	head = add_to_empty(head, 10);

	printf("%d", head->data);
	return 0;
}
