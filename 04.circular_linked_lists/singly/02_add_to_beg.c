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

void add_to_beg(struct Node *tail, int data)
{
	struct Node *new_head = malloc(sizeof(struct Node));
	new_head->data = data;
	new_head->next = tail->next;
	tail->next = new_head;
}

int main()
{
	struct Node *tail = NULL;
	tail = circularSingly(40);

	add_to_beg(tail, 30);
	add_to_beg(tail, 20);
	add_to_beg(tail, 10);

	print_data(tail);
	return 0;
}
