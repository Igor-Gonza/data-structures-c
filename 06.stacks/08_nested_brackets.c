#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
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
	int value = stack[top];
	top--;
	return value;
}

int isOpeningBracket(char c)
{
	return c == '(' || c == '[' || c == '{' || c == '<';
}

int isClosingBracket(char c)
{
	return c == ')' || c == ']' || c == '}' || c == '>';
}

char matchBrackets(char a, char b)
{
	if (a == '[' && b == ']')
		return 1;
	if (a == '(' && b == ')')
		return 1;
	if (a == '{' && b == '}')
		return 1;
	if (a == '<' && b == '>')
		return 1;
	return 0;
}

void checkBalanced(char *s)
{
	int i, temp;
	int len = strlen(s);
	for (i = 0; i < len; i++)
	{
		temp = s[i];
		if (isOpeningBracket(temp))
		{
			push(temp);
			continue;
		}
		if (!isClosingBracket(temp))
			continue;

		if (isEmpty())
		{
			printf("Not balanced - More right brackets than left");
			return;
		}
		if (!matchBrackets(pop(), temp))
		{
			printf("Not balanced - Mismatched brackets");
			return;
		}
	}
	if (!isEmpty())
	{
		printf("Not balanced - More left brackets than right");
		return;
	}
	printf("Balanced expression");
}

int main()
{
	char expr[MAX];
	printf("Enter the algebraic expression: ");
	fgets(expr, sizeof(expr), stdin);

	checkBalanced(expr);
	return 0;
}
