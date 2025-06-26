#include <stdio.h>

struct point
{
	int x;
	int y;
};

// The struct is passed as a copy
void print_with_copy(struct point p)
{
	printf("%d %d\n", p.x, p.y);
}

// The struct is passed as a reference
void print_with_reference(struct point *p)
{
	// Wrong/harder way
	printf("%d %d\n", (*p).x, (*p).y);

	// Right/abbreviated way
	printf("%d %d\n", p->x, p->y);
}

int main()
{
	struct point p1 = {23, 45};
	struct point p2 = {56, 90};

	printf("-> With copy\n");
	print_with_copy(p1);
	print_with_copy(p2);

	printf("-> With reference\n");
	print_with_reference(&p1);
	print_with_reference(&p2);
	return 0;
}
