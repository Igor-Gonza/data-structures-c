#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
	float coefficient;
	int exponent;
	struct Node *next;
};

struct Node *insert(struct Node *head, int coefficient, int exponent)
{
	struct Node *aux;
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->coefficient = coefficient;
	new_node->exponent = exponent;
	new_node->next = NULL;

	if (head == NULL || exponent > head->exponent)
	{
		new_node->next = head;
		head = new_node;
		return head;
	}

	aux = head;
	while (aux->next != NULL && aux->next->exponent > exponent)
		aux = aux->next;

	new_node->next = aux->next;
	aux->next = new_node;
	return head;
}

struct Node *create(struct Node *head)
{
	int n;
	int i;
	float coefficient;
	int exponent;

	printf("Enter the numbers of terms: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Enter the coefficient for term %d: ", i + 1);
		scanf("%f", &coefficient);

		printf("Enter the exponent for term %d: ", i + 1);
		scanf("%d", &exponent);
		head = insert(head, coefficient, exponent);
	}
	return head;
}

void print(struct Node *head)
{
	if (head == NULL)
	{
		printf("No Polynomial.");
		return;
	}

	struct Node *aux = head;
	while (aux != NULL)
	{
		printf("(%.1fx^%d)", aux->coefficient, aux->exponent);
		aux = aux->next;
		printf(aux != NULL ? " + " : "\n");
	}
}

int main()
{
	struct Node *head = NULL;

	printf("Enter the polynomial\n ");
	head = create(head);

	print(head);
}
