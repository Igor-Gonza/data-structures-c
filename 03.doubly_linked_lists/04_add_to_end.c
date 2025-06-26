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

void add_to_end(struct Node *head, int data)
{
	struct Node *new_tail = malloc(sizeof(struct Node));
	new_tail->prev = NULL;
	new_tail->data = data;
	new_tail->next = NULL;

	struct Node *aux = head;
	while (aux->next != NULL)
		aux = aux->next;

	aux->next = new_tail;
	new_tail->prev = aux;
}

int main()
{
	struct Node *head = NULL;
	head = add_to_empty(head, 10);

	head = add_to_beginning(head, 8);
	head = add_to_beginning(head, 6);
	head = add_to_beginning(head, 4);
	head = add_to_beginning(head, 2);

	add_to_end(head, 20);
	add_to_end(head, 30);
	add_to_end(head, 40);
	add_to_end(head, 50);

	print_data(head);
	return 0;
}
