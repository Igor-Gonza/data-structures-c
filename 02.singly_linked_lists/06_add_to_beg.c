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

struct Node *add_to_beg(struct Node *head, int data)
{
	struct Node *new_head = malloc(sizeof(struct Node));
	new_head->data = data;
	new_head->next = NULL;

	new_head->next = head;
	head = new_head;
	return new_head;
}

int main()
{
	struct Node *head = malloc(sizeof(struct Node));
	head->data = 45;
	head->next = NULL;

	struct Node *tail = malloc(sizeof(struct Node));
	tail->data = 24;
	tail->next = NULL;

	head->next = tail;

	head = add_to_beg(head, 3);
	head = add_to_beg(head, 2);
	head = add_to_beg(head, 1);

	print_data(head);
	return 0;
}
