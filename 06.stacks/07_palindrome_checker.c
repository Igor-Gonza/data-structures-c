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

void palindromeCheck(char *s)
{
	int i = 0;
	while (s[i] != 'X')
	{
		push(s[i]);
		i++;
	}
	i++;
	while (s[i])
	{
		if (isEmpty() || s[i] != pop())
		{
			printf("Not a palindrome");
			exit(1);
		}
		i++;
	}
	printf("Palindrome");
}

int main()
{
	char s[100];
	printf("Please enter the string: ");
	scanf("%s", s);

	palindromeCheck(s);
	return 0;
}
