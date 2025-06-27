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

struct Node *delete_last(struct Node *tail)
{
	if (tail == NULL)
		return tail;

	struct Node *aux = tail->next;
	if (aux == tail)
	{
		free(tail);
		tail = NULL;
		return tail;
	}

	aux = tail->prev;
	aux->next = tail->next;
	tail->next->prev = aux;
	free(tail);
	tail = aux;
	return tail;
}

int main()
{
	struct Node *tail = NULL;

	tail = add_to_beg(tail, 50);
	tail = add_to_beg(tail, 40);
	tail = add_to_beg(tail, 30);
	tail = add_to_beg(tail, 20);
	tail = add_to_beg(tail, 10);

	tail = delete_last(tail);
	tail = delete_last(tail);
	tail = delete_last(tail);

	print_data(tail);
	return 0;
}
