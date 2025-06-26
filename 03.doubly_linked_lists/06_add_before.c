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

struct Node *add_before_position(struct Node *head, int data, int position)
{
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->prev = NULL;
	new_node->data = data;
	new_node->next = NULL;

	struct Node *aux = head;
	int pos = position;
	while (pos > 1)
	{
		aux = aux->next;
		pos--;
	}

	if (position == 1)
	{
		head = add_to_beginning(head, data);
		return head;
	}

	new_node->prev = aux->prev;
	aux->prev->next = new_node;
	new_node->next = aux;
	aux->prev = new_node;
	return head;
}

int main()
{
	struct Node *head = NULL;
	head = add_to_empty(head, 10);

	head = add_to_beginning(head, 8);
	head = add_to_beginning(head, 6);
	head = add_to_beginning(head, 4);
	head = add_to_beginning(head, 2);

	head = add_before_position(head, 9, 5);
	head = add_before_position(head, 7, 4);
	head = add_before_position(head, 5, 3);
	head = add_before_position(head, 3, 2);
	head = add_before_position(head, 1, 1);

	print_data(head);
	return 0;
}
