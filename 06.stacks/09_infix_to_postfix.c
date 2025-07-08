#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

int stack[MAX];
char infix[MAX], postfix[MAX];
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

int isWhitSpace(char c)
{
	return c == ' ' || c == '\t' || c == '\n';
}

int isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char c)
{
	switch (c)
	{
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

void toPostfix()
{
	char symbol, next;
	int i, j = 0;
	int len = strlen(infix);
	for (i = 0; i < len; i++)
	{
		symbol = infix[i];
		if (isWhitSpace(symbol))
			continue;

		if (symbol == '(')
		{
			push(symbol);
			continue;
		}
		if (symbol == ')')
		{
			while ((next = pop()) != '(')
				postfix[j++] = next;
			continue;
		}
		if (isOperator(symbol))
		{
			while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
				postfix[j++] = pop();
			push(symbol);
			continue;
		}
		postfix[j++] = symbol;
	}
	while (!isEmpty())
		postfix[j++] = pop();
	postfix[j] = '\0';
}

int calculatePostfix()
{
	char symbol;
	int i, a, b, aux;
	int len = strlen(postfix);
	for (i = 0; i < len; i++)
	{
		symbol = postfix[i];
		if (!isOperator(symbol))
		{
			push(symbol - '0');
			continue;
		}
		b = pop();
		a = pop();
		switch (symbol)
		{
		case '+':
			aux = a + b;
			break;
		case '-':
			aux = a - b;
			break;
		case '*':
			aux = a * b;
			break;
		case '/':
			aux = a / b;
			break;
		case '^':
			aux = pow(a, b);
			break;
		}
		push(aux);
	}
	return pop();
}

int main()
{
	int result;
	printf("Enter the infix expression (only works with single digits)\n");
	fgets(infix, sizeof(infix), stdin);

	// Expression -> 8*(5^4+2)-6^2/(9*3)
	// Postfix    -> 854^2+*62^93*/-
	// Result     -> 5014,666... (no decimals)

	// Expression -> 7+(9-5)*2
	// Postfix    -> 795-2*+
	// Result     -> 15

	toPostfix();
	result = calculatePostfix();
	printf("\nPostfix: %s\n", postfix);
	printf("Result: %d\n", result);
	return 0;
}
