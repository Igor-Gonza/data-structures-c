#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};

int main()
{
	struct Node *head = malloc(sizeof(struct Node));
	head->prev = NULL;
	head->data = 10;
	head->next = NULL;

	printf("%d", head->data);
	return 0;
}
