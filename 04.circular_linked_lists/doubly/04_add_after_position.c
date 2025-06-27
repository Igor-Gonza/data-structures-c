#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *prev;
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

	struct Node *aux = tail->next;
	while (aux != tail)
	{
		printf("%d ", aux->data);
		aux = aux->next;
	}
	printf("%d -> %d | ", aux->data, aux->next->data);

	while (aux != tail->next)
	{
		printf("%d ", aux->data);
		aux = aux->prev;
	}
	printf("%d -> %d\n", aux->data, aux->prev->data);
}

struct Node *circularDoubly(int data)
{
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->prev = new_node;
	new_node->next = new_node;
	return new_node;
}

struct Node *add_to_beg(struct Node *tail, int data)
{
	struct Node *new_node = circularDoubly(data);
	if (tail == NULL)
		return new_node;

	struct Node *aux = tail->next;
	new_node->prev = tail;
	new_node->next = aux;

	aux->prev = new_node;
	tail->next = new_node;
	return tail;
}

struct Node *add_after_position(struct Node *tail, int data, int position)
{
	struct Node *new_node = circularDoubly(data);
	if (tail == NULL)
		return new_node;

	struct Node *aux = tail->next;
	while (position-- > 1)
		aux = aux->next;

	new_node->prev = aux;
	new_node->next = aux->next;

	aux->next->prev = new_node;
	aux->next = new_node;
	if (aux == tail)
		tail = tail->next;

	return tail;
}

int main()
{
	struct Node *tail = NULL;

	tail = add_to_beg(tail, 40);
	tail = add_to_beg(tail, 30);
	tail = add_to_beg(tail, 20);
	tail = add_to_beg(tail, 10);

	tail = add_after_position(tail, 15, 1);
	tail = add_after_position(tail, 25, 3);
	tail = add_after_position(tail, 35, 5);
	tail = add_after_position(tail, 45, 7);

	print_data(tail);
	return 0;
}
