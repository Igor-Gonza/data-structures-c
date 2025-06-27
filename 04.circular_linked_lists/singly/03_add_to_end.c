#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void print_data(struct Node *tail)
{
	if (tail == NULL)
	{
		printf("Linked List is empty\n");
		return;
	}

	struct Node *aux = tail;
	do
	{
		aux = aux->next;
		printf("%d ", aux->data);
	} while (aux != tail);

	printf("-> %d", tail->next->data);
	printf("\n");
}

struct Node *circularSingly(int data)
{
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = new_node;
	return new_node;
}

struct Node *add_to_end(struct Node *tail, int data)
{
	struct Node *new_tail = malloc(sizeof(struct Node));
	new_tail->data = data;
	new_tail->next = NULL;

	new_tail->next = tail->next;
	tail->next = new_tail;
	tail = new_tail;
	return tail;
}

int main()
{
	struct Node *tail = NULL;
	tail = circularSingly(40);

	tail = add_to_end(tail, 50);
	tail = add_to_end(tail, 60);
	tail = add_to_end(tail, 70);

	print_data(tail);
	return 0;
}
