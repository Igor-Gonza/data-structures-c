#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

int main()
{
	struct Node *head = NULL;
	// It's not mandatory to type cast the void pointer
	head = (struct Node *)malloc(sizeof(struct Node));

	// EVIL HEAD!!!!
	head->data = 45;
	head->next = NULL;

	printf("%d", head->data);
	return 0;
}
