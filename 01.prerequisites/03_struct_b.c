#include <stdio.h>

// Simple structure/object declaration
struct charset
{
	char s;
	int i;
};

// Receives the addresses and uses them to asign values to the struct
void keyValue(char *s, int *i)
{
	printf("Enter Key Value Pair: ");
	scanf("%c %d", s, i);
}

// It passes the addresses of each parameters inside the struct
int main()
{
	int j;
	struct charset cs;

	keyValue(&cs.s, &cs.i);
	printf("%c %d", cs.s, cs.i);
	return 0;
}
