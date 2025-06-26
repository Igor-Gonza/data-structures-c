#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void count_nodes(struct Node *head)
{
	if (head == NULL)
	{
		printf("Linked List is empty");
		return;
	}

	int count = 0;
	struct Node *aux = NULL;
	aux = head;
	while (aux != NULL)
	{
		count++;
		aux = aux->next;
	}
	printf("Count is %d elements\n", count);
}

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

	count_nodes(head);
	print_data(head);
	return 0;
}
