#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
	float coefficient;
	int exponent;
	struct Node *next;
};

void add_at_end(struct Node **head, float coefficient, int exponent)
{
	struct Node *new_tail = malloc(sizeof(struct Node));
	new_tail->coefficient = coefficient;
	new_tail->exponent = exponent;
	new_tail->next = NULL;

	if (*head == NULL)
	{
		*head = new_tail;
		return;
	}

	struct Node *curr = *head;
	while (curr->next != NULL)
		curr = curr->next;

	curr->next = new_tail;
}

void print(struct Node *head)
{
	struct Node *curr = head;
	while (curr != NULL)
	{
		printf("%s", curr->coefficient < 0 ? "-" : "+");
		printf(" %.0fx^%d ", fabsf(curr->coefficient), curr->exponent);
		curr = curr->next;
	}
}

int main()
{
	struct Node *head = NULL;

	add_at_end(&head, 5, 3);
	add_at_end(&head, -3, 2);
	add_at_end(&head, 2, 1);
	add_at_end(&head, 1, 0);

	print(head);
}
