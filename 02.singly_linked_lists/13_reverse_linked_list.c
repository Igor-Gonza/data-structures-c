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

struct Node *reverse_list(struct Node *head)
{
	if (head == NULL)
	{
		printf("List is empty\n");
		return head;
	}

	if (head->next == NULL)
	{
		printf("Tiny list, no change\n");
		return head;
	}

	struct Node *prev = head;
	struct Node *new_head = head;
	struct Node *next = head->next;
	new_head->next = NULL;
	while (next != NULL)
	{
		new_head = next;
		next = next->next;
		new_head->next = prev;
		prev = new_head;
	}
	head = new_head;
	return head;
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

	head = reverse_list(head);

	print_data(head);
	return 0;
}
