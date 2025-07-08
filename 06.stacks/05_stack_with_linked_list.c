#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
} *top = NULL;

int isEmpty()
{
	return top == NULL ? 1 : 0;
}

void push(int data)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("Stack overflow\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;

	newNode->next = top;
	top = newNode;
}

int pop()
{
	if (isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	struct Node *oldTop = top;
	int poppedValue = oldTop->data;
	top = top->next;

	free(oldTop);
	oldTop = NULL;
	return poppedValue;
}

int peek()
{
	if (isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return top->data;
}

void print()
{
	if (isEmpty())
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
	while (1)
	{
		printf("\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Print the top element\n");
		printf("4. Print all elements of the stack\n");
		printf("5. Quit\n");
		printf("Please enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the element to be pushed: ");
			scanf("%d", &data);
			push(data);
			break;
		case 2:
			data = pop();
			printf("Deleted element is %d\n", data);
			break;
		case 3:
			printf("The topmost element of the stack is %d\n", peek());
			break;
		case 4:
			print();
			break;
		case 5:
			exit(1);
		default:
			printf("Wrong choice\n");
		}
	}
	return 0;
}
