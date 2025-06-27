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

void polynomial_addition(struct Node *head1, struct Node *head2)
{
	struct Node *aux1 = head1;
	struct Node *aux2 = head2;
	struct Node *head3 = NULL;
	while (aux1 != NULL && aux2 != NULL)
	{
		if (aux1->exponent == aux2->exponent)
		{
			head3 = insert(head3, aux1->coefficient + aux2->coefficient, aux1->exponent);
			aux1 = aux1->next;
			aux2 = aux2->next;
		}
		else if (aux1->exponent > aux2->exponent)
		{
			head3 = insert(head3, aux1->coefficient, aux1->exponent);
			aux1 = aux1->next;
		}
		else if (aux1->exponent < aux2->exponent)
		{
			head3 = insert(head3, aux2->coefficient, aux2->exponent);
			aux2 = aux2->next;
		}
	}

	while (aux1 != NULL)
	{
		head3 = insert(head3, aux1->coefficient, aux1->exponent);
		aux1 = aux1->next;
	}
	while (aux2 != NULL)
	{
		head3 = insert(head3, aux2->coefficient, aux2->exponent);
		aux2 = aux2->next;
	}
	printf("Added polynomial is: ");
}

int main()
{
	struct Node *head1 = NULL;
	struct Node *head2 = NULL;

	printf("Enter the First polynomial\n ");
	head1 = create(head1);

	printf("Enter the second polynomial\n ");
	head2 = create(head2);

	polynomial_addition(head1, head2);
	return 0;
}
