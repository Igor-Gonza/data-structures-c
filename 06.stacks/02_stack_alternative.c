#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int first = -1;

int isFull()
{
	return first == MAX - 1 ? 1 : 0;
}

int isEmpty()
{
	return first == -1 ? 1 : 0;
}

void push(int data)
{
	if (isFull())
	{
		printf("Stack overflow\n");
		return;
	}
	int i;
	first++;
	for (i = first; i > 0; i--)
		stack[i] = stack[i - 1];
	stack[0] = data;
}

int pop()
{
	if (isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	int i, data = stack[0];
	for (i = 0; i < first; i++)
		stack[i] = stack[i + 1];
	first--;
	return data;
}

int peek()
{
	if (isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return stack[0];
}

void print()
{
	if (isEmpty())
	{
		printf("Stack is empty\n");
		return;
	}
	int i = 0;
	for (i; i <= first; i++)
		printf("%d ", stack[i]);
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
