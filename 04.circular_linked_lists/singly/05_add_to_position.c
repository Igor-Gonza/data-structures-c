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

struct Node *add_to_position(struct Node *tail, int data, int position)
{
	if (position == 1)
	{
		add_to_beg(tail, data);
		return tail;
	}

	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = NULL;

	struct Node *aux = tail->next;
	while (position-- > 2)
		aux = aux->next;

	new_node->next = aux->next;
	aux->next = new_node;
	if (aux == tail)
		tail = tail->next;

	return tail;
}

int main()
{
	struct Node *tail = NULL;
	tail = circularSingly(40);

	add_to_beg(tail, 30);
	add_to_beg(tail, 20);
	add_to_beg(tail, 10);

	tail = add_to_position(tail, 5, 1);
	tail = add_to_position(tail, 15, 3);
	tail = add_to_position(tail, 25, 5);
	tail = add_to_position(tail, 35, 7);
	tail = add_to_position(tail, 45, 9);

	print_data(tail);
	return 0;
}
