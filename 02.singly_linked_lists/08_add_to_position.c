#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void print_data(struct Node *head)
{
	if (head == NULL)
	{
		printf("Linked List is empty");
		return;
	}

	struct Node *aux = NULL;
	aux = head;
	while (aux != NULL)
	{
		printf("%d ", aux->data);
		aux = aux->next;
	}
	printf("%n");
}

struct Node *add_to_end(struct Node *tail, int data)
{
	struct Node *new_tail = malloc(sizeof(struct Node));
	new_tail->data = data;
	new_tail->next = NULL;

	tail->next = new_tail;
	return new_tail;
}

void *add_to_position(struct Node *head, int position, int data)
{
	struct Node *aux = head;
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = NULL;

	while (position > 2)
	{
		aux = aux->next;
		position--;
	}
	new_node->next = aux->next;
	aux->next = new_node;
}

int main()
{
	struct Node *head = malloc(sizeof(struct Node));
	head->data = 10;
	head->next = NULL;

	struct Node *tail = head;
	tail = add_to_end(tail, 20);
	tail = add_to_end(tail, 30);
	tail = add_to_end(tail, 40);

	add_to_position(head, 3, 25);
	add_to_position(head, 3, 24);
	add_to_position(head, 3, 23);

	print_data(head);
	return 0;
}
