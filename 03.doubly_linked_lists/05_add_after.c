#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *prev;
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
	while (aux->next != NULL)
	{
		printf("%d ", aux->data);
		aux = aux->next;
	}
	printf("%d | ", aux->data);

	while (aux->prev != NULL)
	{
		printf("%d ", aux->data);
		aux = aux->prev;
	}
	printf("%d\n", aux->data);
}

struct Node *add_to_empty(struct Node *head, int data)
{
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->prev = NULL;
	new_node->data = data;
	new_node->next = NULL;

	head = new_node;
	return head;
}

struct Node *add_to_beginning(struct Node *head, int data)
{
	struct Node *new_head = malloc(sizeof(struct Node));
	new_head->prev = NULL;
	new_head->data = data;
	new_head->next = NULL;

	new_head->next = head;
	head->prev = new_head;
	head = new_head;
	return head;
}

void add_after_position(struct Node *head, int data, int position)
{
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->prev = NULL;
	new_node->data = data;
	new_node->next = NULL;

	struct Node *aux = head;
	while (position > 1)
	{
		aux = aux->next;
		position--;
	}

	if (aux->next == NULL)
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
	else
	{
		new_node->next = aux->next;
		aux->next->prev = new_node;
		new_node->prev = aux;
		aux->next = new_node;
	}
}

int main()
{
	struct Node *head = NULL;
	head = add_to_empty(head, 9);

	head = add_to_beginning(head, 7);
	head = add_to_beginning(head, 5);
	head = add_to_beginning(head, 3);
	head = add_to_beginning(head, 1);

	add_after_position(head, 10, 5);
	add_after_position(head, 8, 4);
	add_after_position(head, 6, 3);
	add_after_position(head, 4, 2);
	add_after_position(head, 2, 1);

	print_data(head);
	return 0;
}
