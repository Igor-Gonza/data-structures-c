#include <stdio.h>
#include <stdlib.h>
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

void prime_fact(int num)
{
	int i = 2;
	int threshold = sqrt(num);
	while (num != 1)
	{
		if (i > threshold)
		{
			push(num);
			num = 1;
			break;
		}
		while (num % i == 0)
		{
			push(i);
			num /= i;
			if (num % i != 0)
				threshold = sqrt(num);
		}
		i++;
	}
	while (!isEmpty())
		printf("%d ", pop());
}

int main()
{
	int number;
	printf("Please enter a positive number: ");
	scanf("%d", &number);

	prime_fact(number);
	return 0;
}
