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

void delete_last1(struct Node *head)
{
	if (head == NULL)
	{
		printf("The linked list is already empty");
		return;
	}

	if (head->next == NULL)
	{
		free(head);
		head = NULL;
		return;
	}

	struct Node *penultimate = head;
	struct Node *last = head->next;
	while (last->next != NULL)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = NULL;
	free(last);
	last = NULL;
}

void delete_last2(struct Node *head)
{
	if (head == NULL)
	{
		printf("The linked list is already empty");
		return;
	}

	if (head->next == NULL)
	{
		free(head);
		head = NULL;
		return;
	}

	struct Node *last = head;
	while (last->next->next != NULL)
		last = last->next;

	free(last->next);
	last->next = NULL;
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

	delete_last1(head);
	delete_last1(head);
	delete_last2(head);
	delete_last2(head);

	print_data(head);
	return 0;
}
