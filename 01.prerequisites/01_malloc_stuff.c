#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n;
	printf("Enter the number of integers: ");
	scanf("%d", &n);

	// Reserves an array of n int variables with int size
	int *ptr = (int *)malloc(n * sizeof(int));

	// If it doesn't initialize, there's no memory, so abort
	if (ptr == NULL)
	{
		printf("Memory not available.");
		exit(1);
	}

	// Do what you have to do...
	for (i = 0; i < n; i++)
	{
		printf("Enter an integer: ");
		scanf("%d", ptr + i);
	}
	for (i = 0; i < n; i++)
	{
		printf("%d", *(ptr + i));
	}

	// After using it all, clean memory to avoid memory leak
	free(ptr);
	return 0;
}
