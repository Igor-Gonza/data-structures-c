#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

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

	// Not exactly there yet (for the "adding new nodes" action)
	head->next->next = current;
	return 0;
}
