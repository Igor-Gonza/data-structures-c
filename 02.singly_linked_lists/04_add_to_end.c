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

void add_at_end(struct Node *head, int data)
{
	struct Node *new_tail = malloc(sizeof(struct Node));
	new_tail->data = data;
	new_tail->next = NULL;

	struct Node *aux = NULL;
	aux = head;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = new_tail;
}

int main()
{
	struct Node *head = malloc(sizeof(struct Node));
	head->data = 45;
	head->next = NULL;

	struct Node *current = malloc(sizeof(struct Node));
	current->data = 98;
	current->next = NULL;
	head->next = current;

	current = malloc(sizeof(struct Node));
	current->data = 3;
	current->next = NULL;
	head->next->next = current;

	add_at_end(head, 13);
	add_at_end(head, 69);
	add_at_end(head, 81);

	print_data(head);
	return 0;
}
