#include<stdio.h>
typedef struct 
{
	int x;
	int y;
} Point;

void outPoint(Point *p);

main()
{
	Point p;
	p.x = 10;
	p.y = 8;
	
	outPoint(&p);
	return 0;
}

void outPoint(Point *p)
{
	printf("x=%d \n", p->x);
	printf("y=%d \n", p->y);
}
