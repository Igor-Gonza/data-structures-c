#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX 32

int array_stack[MAX];
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
	array_stack[top] = data;
}

int pop()
{
	if (isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	int value = array_stack[top];
	top--;
	return value;
}

void decimal_to_binary(int num)
{
	while (num != 0)
	{
		push(num % 2);
		num /= 2;
	}
	while (top != -1)
		printf("%d", pop());
	printf("\n");
}

int main()
{
	int number;
	printf("Please enter a positive number: ");
	scanf("%d", &number);

	decimal_to_binary(number);
	return 0;
}
