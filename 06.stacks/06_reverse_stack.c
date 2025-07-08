#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

int isEmpty(struct Node *top)
{
	return top == NULL ? 1 : 0;
}

void push(int data, struct Node **top)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("Stack overflow\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;

	newNode->next = *top;
	*top = newNode;
}

int pop(struct Node **top)
{
	if (isEmpty(*top))
	{
		printf("Stack underflow\n");
		exit(1);
	}
	struct Node *oldTop = *top;
	int poppedValue = oldTop->data;
	*top = oldTop->next;

	free(oldTop);
	oldTop = NULL;
	return poppedValue;
}

void reverseStack(struct Node **top)
{
	if (*top == NULL || (*top)->next == NULL)
		return;
	struct Node *temp1 = NULL;
	struct Node *temp2 = NULL;

	while (!isEmpty(*top))
		push(pop(top), &temp1);

	while (!isEmpty(temp1))
		push(pop(&temp1), &temp2);

	while (!isEmpty(temp2))
		push(pop(&temp2), top);
}

void print(struct Node *top)
{
	if (isEmpty(top))
	{
		printf("Stack is empty\n");
		return;
	}
	struct Node *aux = top;
	while (aux != NULL)
	{
		printf("%d ", aux->data);
		aux = aux->next;
	}
	printf("\n");
}

int main()
{
	int choice, data;
	struct Node *top = NULL;
	while (1)
	{
		printf("1. Push\n");
		printf("2. Print\n");
		printf("3. Reverse the stack\n");
		printf("4. Quit\n");
		printf("Enter the choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the element to be pushed: ");
			scanf("%d", &data);
			push(data, &top);
			break;
		case 2:
			print(top);
			break;
		case 3:
			reverseStack(&top);
			printf("Stack is reversed.");
			break;
		case 4:
			exit(1);
		default:
			printf("Wrong choice!\n");
		}
	}
	return 0;
}
