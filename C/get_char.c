#include<stdio.h>

main()
{
	char c = getchar();
	while(c != '\n')
	{
		putchar(c);
		c = getchar();
	}
	printf("\n");
} 
