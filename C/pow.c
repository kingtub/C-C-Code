#include<stdio.h>
#include<math.h>

int my_pow(int i, int j);
int main()
{
	int i;
	for(i = 1; i < 10; i++)
	{
	    printf("%.0f\n", pow(i, 3));
	    printf("%d\n", my_pow(i, 3));
	}
	return 0;
}

int my_pow(int i, int j)
{
	int r = 1;
	int m;
	for(m = 0; m < j; m++)
	{
		r *= i;
	}
	return r;
}

