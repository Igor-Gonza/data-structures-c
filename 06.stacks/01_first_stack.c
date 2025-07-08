#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack[MAX];
int top = -1;

int isFull()
{
	return top == MAX - 1 ? 1 : 0;
}

int isEmpty()
{
	return top == -1 ? 1 : 0;
}

void push(int data)
{
	if (isFull())
	{
		printf("Stack overflow\n");
		return;
	}
	top++;
	stack[top] = data;
}

int pop()
{
	if (isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	int value = stack[top--];
	return value;
}

int peek()
{
	if (isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return stack[top];
}

void print()
{
	if (isEmpty())
	{
		printf("Stack is empty\n");
		return;
	}
	int i = 0;
	for (i; i <= top; i++)
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
