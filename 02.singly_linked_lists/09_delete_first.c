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

void delete_first(struct Node **head)
{
	if (*head == NULL)
	{
		printf("The list is already empty");
		return;
	}
	struct Node *deleted_node = *head;
	*head = (*head)->next;
	free(deleted_node);
	deleted_node = NULL;
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
	tail = add_to_end(tail, 50);
	tail = add_to_end(tail, 60);

	delete_first(&head);
	delete_first(&head);
	delete_first(&head);

	print_data(head);
	return 0;
}
